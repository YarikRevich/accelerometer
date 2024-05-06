#ifndef ACCELEROMETER_PROTO_HELPER_H
#define ACCELEROMETER_PROTO_HELPER_H

#include "request.h"
#include "data.h"

/**
 * Contains aliases to perform proto declaration related operation.
 */
class ProtoHelper {
public:
    /**
     * Checks if the given request container is related to data bus.
     *
     * @param container - given request container.
     * @return result of the check.
     */
    static bool is_data_bus_request_container(const accelerometer::RequestContainer &container);

    /**
     * Extracts data bus request container from the raw request container.
     *
     * @param container - given raw request container.
     * @return extracted data bus request container.
     */
    static accelerometer::DataBusRequestContent extract_data_bus_request_content(
            const accelerometer::RequestContainer &container);

    /**
     * Checks if the given data bus request content of raw data type.
     *
     * @param content - given data bus request content.
     * @return result of the check.
     */
    static bool is_data_bus_request_content_of_raw_data_type(const accelerometer::DataBusRequestContent &content);
};

#endif //ACCELEROMETER_PROTO_HELPER_H
