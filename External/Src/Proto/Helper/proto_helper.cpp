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

bool ProtoHelper::is_settings_bus_request_container(const accelerometer::RequestContainer &container) {
    return container.get_which_content() == accelerometer::RequestContainer::FieldNumber::SETTINGSBUS;
}

accelerometer::SettingsBusRequestContent ProtoHelper::extract_settings_bus_request_content(
        const accelerometer::RequestContainer &container) {
    return container.settingsBus();
}

bool ProtoHelper::is_settings_bus_request_content_of_set_suspend_settings_type(
        const accelerometer::SettingsBusRequestContent &content) {
    return content.settingsType() == accelerometer::SettingsType::SetSuspend;
}

bool ProtoHelper::is_settings_bus_request_content_of_set_serve_settings_type(
        const accelerometer::SettingsBusRequestContent &content) {
    return content.settingsType() == accelerometer::SettingsType::SetServe;
};