#include "scheduler_handler.h"
#include "indicator.h"

int SchedulerHandler::handle_request() {
    if (__HAL_UART_GET_FLAG(&huart2, UART_FLAG_RXNE) == SET) {
        Indicator::toggle_invalid_request();

        if (try_process_request_container() != EXIT_SUCCESS) {
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

int SchedulerHandler::handle_response() {
    auto request_container_sequence = State::get_request_container_sequence();

    if (!request_container_sequence->is_empty()) {
        return request_container_sequence->traverse_with_break(
                [](const accelerometer::RequestContainer &content) -> int {
                    return SchedulerHandler::try_process_response_container(content);
                });
    }

    return EXIT_SUCCESS;
}

int SchedulerHandler::try_process_request_container() {
    auto request_buffer = ProtoCodec::get_request_buffer();

    uint8_t max_size;

    if (HAL_UART_Receive(
            &huart2, &max_size, 1, POLL_TIMEOUT) != HAL_OK) {
        return EXIT_FAILURE;
    }

    request_buffer->set_max_size(max_size);

    uint8_t raw_buffer[max_size];

    if (HAL_UART_Receive(&huart2, raw_buffer, max_size, POLL_TIMEOUT) != HAL_OK) {
        return EXIT_FAILURE;
    }

    request_buffer->set_raw_buffer(raw_buffer);

    return ProtoCodec::decode_request_container();
}

int SchedulerHandler::try_process_response_container(const accelerometer::RequestContainer &content) {
    if (ProtoHelper::is_data_bus_request_container(content)) {

        if (SchedulerHandler::process_data_bus_request_content_response(content) != EXIT_SUCCESS) {
            return EXIT_FAILURE;
        }
    } else {
        return EXIT_FAILURE;
    }

    return SchedulerHandler::try_transmit_response_container();
}

int SchedulerHandler::try_transmit_response_container() {
    auto response_buffer = ProtoCodec::get_response_buffer();

    auto conversion_result = Converter::convertUint32ToUint8(response_buffer->get_size());

    if (HAL_UART_Transmit(
            &huart2,
            conversion_result.data,
            3,
            TRANSMIT_TIMEOUT) != HAL_OK) {
        return EXIT_FAILURE;
    }

    if (HAL_UART_Transmit(
            &huart2,
            response_buffer->get_raw_buffer(),
            response_buffer->get_size(),
            TRANSMIT_TIMEOUT) != HAL_OK) {
        return EXIT_FAILURE;
    }

    response_buffer->clear();

    return EXIT_SUCCESS;
}

int SchedulerHandler::process_data_bus_request_content_response(
        const accelerometer::RequestContainer &content) {
    auto data_bus_request_content =
            ProtoHelper::extract_data_bus_request_content(content);

    if (ProtoHelper::is_data_bus_request_content_of_raw_data_type(data_bus_request_content)) {

        return SchedulerHandler::process_data_bus_request_content_of_raw_data_type_response();
    }

    return EXIT_SUCCESS;
}

int SchedulerHandler::process_data_bus_request_content_of_raw_data_type_response() {
    accelerometer::ResponseContainer response_container;

    accelerometer::DataBusResponseContent data_bus_response_content;

    data_bus_response_content.set_dataType(accelerometer::DataType::Raw);

    accelerometer::RawDataTypeValue raw_data_type_value;

    if (LIS2DW12::is_available()) {
        data_bus_response_content.set_deviceId(LIS2DW12::get_device_id());

        LIS2DW12::RawDataTypeValue value = LIS2DW12::read_raw();

        raw_data_type_value.set_x(value.get_x());
        raw_data_type_value.set_y(value.get_y());
        raw_data_type_value.set_z(value.get_z());

        data_bus_response_content.set_raw(raw_data_type_value);
    } else {
        data_bus_response_content.set_deviceId(0);

        raw_data_type_value.set_x(0);
        raw_data_type_value.set_y(0);
        raw_data_type_value.set_z(0);

        data_bus_response_content.set_raw(raw_data_type_value);
    }

    data_bus_response_content.set_nonce(State::allocate_response_nonce());

    response_container.set_dataBus(data_bus_response_content);

    return ProtoCodec::encode_response_container(response_container);
}