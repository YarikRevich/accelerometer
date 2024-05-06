#ifndef LIGHT_DETECTOR_SCHEDULER_HANDLER_H
#define LIGHT_DETECTOR_SCHEDULER_HANDLER_H

#include "stm32l4xx_hal.h"
#include "sensor.h"

#include "request.h"
#include "data.h"
#include "proto_codec.h"
#include "proto_helper.h"

//#include "indicator.h"
#include "converter.h"
#include "state.h"

#define POLL_TIMEOUT (10000)
#define TRANSMIT_TIMEOUT (10000)

extern UART_HandleTypeDef huart2;

/**
 * Represents scheduler handler used to expose
 */
class SchedulerHandler {
public:
    /**
     * Handles high-level incoming request, received during one exact timer tick.
     *
     * @return status of the request handling.
     */
    static int handle_request();

    /**
     * Handles high-level outcoming response, sent during one exact timer tick.
     *
     * @return status of the response handling.
     */
    static int handle_response();
private:
    /**
     * Attempts to process incoming request container if there is one.
     *
     * @return status of the request container processing.
     */
    static int try_process_request_container();

    /**
     * Attempts to process outcoming response container if there is one.
     *
     * @param content - given request container content.
     * @return status of the response container processing.
     */
    static int try_process_response_container(const accelerometer::RequestContainer &content);

    /**
     * Attempts to transmit outcoming response container.
     *
     * @return status of the response container processing.
     */
    static int try_transmit_response_container();

    /**
     * Attempts to process data bus request content response.
     *
     * @param content - given data bus request content.
     * @return status of the data bus request content response processing.
     */
    static int process_data_bus_request_content_response(const accelerometer::RequestContainer& content);

    /**
     * Attempts to process data bus request content of raw data type response.
     *
     * @return status of the data bus request content response processing.
     */
    static int process_data_bus_request_content_of_raw_data_type_response();
};

#endif //LIGHT_DETECTOR_SCHEDULER_HANDLER_H
