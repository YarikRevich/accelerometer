#include "proto_helper.h"

bool ProtoHelper::is_data_bus_request_container(const accelerometer::RequestContainer &container) {
    return container.get_which_content() == accelerometer::RequestContainer::FieldNumber::DATABUS;
}

accelerometer::DataBusRequestContent ProtoHelper::extract_data_bus_request_content(
        const accelerometer::RequestContainer &container) {
    return container.dataBus();
}

bool ProtoHelper::is_data_bus_request_content_of_raw_data_type(const accelerometer::DataBusRequestContent &content) {
    return content.dataType() == accelerometer::DataType::Raw;
}

bool ProtoHelper::is_data_bus_request_content_of_full_data_type(const accelerometer::DataBusRequestContent &content) {
    return content.dataType() == accelerometer::DataType::Full;
}

bool
ProtoHelper::is_data_bus_request_content_of_infrared_data_type(const accelerometer::DataBusRequestContent &content) {
    return content.dataType() == accelerometer::DataType::Infrared;
}

bool
ProtoHelper::is_data_bus_request_content_of_visible_data_type(const accelerometer::DataBusRequestContent &content) {
    return content.dataType() == accelerometer::DataType::Visible;
}