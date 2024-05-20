#ifndef ACCELEROMETER_PROTO_HELPER_H
#define ACCELEROMETER_PROTO_HELPER_H

#include "request.h"
#include "data.h"
#include "settings.h"

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

    /**
     * Checks if the given request container is related to settings bus.
     *
     * @param container - given request container.
     * @return result of the check.
     */
    static bool is_settings_bus_request_container(const accelerometer::RequestContainer &container);

    /**
     * Extracts settings bus request container from the raw request container.
     *
     * @param container - given raw request container.
     * @return extracted data bus request container.
     */
    static accelerometer::SettingsBusRequestContent extract_settings_bus_request_content(
            const accelerometer::RequestContainer &container);

    /**
     * Checks if the given settings bus request content of set suspend settings type.
     *
     * @param content - given settings bus request content.
     * @return result of the check.
     */
    static bool is_settings_bus_request_content_of_set_suspend_settings_type(
            const accelerometer::SettingsBusRequestContent &content);

    /**
     * Checks if the given settings bus request content of set serve settings type.
     *
     * @param content - given settings bus request content.
     * @return result of the check.
     */
    static bool is_settings_bus_request_content_of_set_serve_settings_type(
            const accelerometer::SettingsBusRequestContent &content);
};

#endif //ACCELEROMETER_PROTO_HELPER_H
