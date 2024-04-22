import logging
from typing import Union

from serial import Serial
from serial import SerialException
from serial import EIGHTBITS

from proto.Content import data_pb2 as DataBus
from proto.Content import info_pb2 as InfoBus
from proto.Content import settings_pb2 as SettingsBus
from proto import request_pb2 as Request
from proto import response_pb2 as Response

from dto import DataTypeCompound
from dto import RetrievedDataDto
from dto import InfoTypeCompound
from dto import RetrievedInfoDto
from dto import SettingsTypeCompound
from dto import SetSettingsDto


class Client:
    """Represents client used to connect to remote device via serial port."""

    # Represents a connection with serial device.
    connection: Serial

    def __init__(self, device: str, baud_rate: int):
        self.device = device
        self.baud_rate = baud_rate

    def __enter__(self) -> object:
        try:
            self.connection = Serial(self.device, self.baud_rate, EIGHTBITS, timeout=1000, xonxoff=False)

            return self
        except SerialException:
            logging.fatal("Given device is not available")

    def __send_data_bus_request_content(self, type: DataBus.DataType) -> Response.ResponseContainer:
        """Sends request to the board via data bus to retrieve data."""

        request_container = Request.RequestContainer()

        data_bus_request = DataBus.DataBusRequestContent()
        data_bus_request.dataType = type

        request_container.dataBus.CopyFrom(data_bus_request)

        data_length = request_container.ByteSize().to_bytes(1, "big")
        data = request_container.SerializeToString()

        self.connection.write(data_length)
        self.connection.write(data)

        result_length_raw = self.connection.read(3)

        result_length = int.from_bytes(result_length_raw, 'big')

        result = self.connection.read(result_length)

        response_container = Response.ResponseContainer()
        response_container.ParseFromString(result)

        return response_container

    def send_data_bus_request_raw_data_type_content(self) -> RetrievedDataDto:
        """Sends request to the board via data bus to retrieve data of raw type."""

        data = self.__send_data_bus_request_content(DataBus.DataType.Raw)

        return RetrievedDataDto(
            data.dataBus.deviceId,
            DataTypeCompound.RAW,
            data.dataBus.value,
            data.dataBus.nonce)

    def send_data_bus_request_full_data_type_content(self) -> None:
        """Sends request to the board via data bus to retrieve data of full type."""

        data = self.__send_data_bus_request_content(DataBus.DataType.Full)

        return RetrievedDataDto(
            data.dataBus.deviceId,
            DataTypeCompound.FULL,
            data.dataBus.value,
            data.dataBus.nonce)

    def send_data_bus_request_infrared_data_type_content(self) -> None:
        """Sends request to the board via data bus to retrieve data of infrared type."""

        data = self.__send_data_bus_request_content(DataBus.DataType.Infrared)

        return RetrievedDataDto(
            data.dataBus.deviceId,
            DataTypeCompound.INFRARED,
            data.dataBus.value,
            data.dataBus.nonce)

    def send_data_bus_request_visible_data_type_content(self) -> None:
        """Sends request to the board via data bus to retrieve data of visible type."""

        data = self.__send_data_bus_request_content(DataBus.DataType.Visible)

        return RetrievedDataDto(
            data.dataBus.deviceId,
            DataTypeCompound.VISIBLE,
            data.dataBus.value,
            data.dataBus.nonce)

    def __send_info_bus_request_content(self, type: InfoBus.InfoType) -> Response.ResponseContainer:
        """Sends request to the board via info bus to retrieve info."""

        request_container = Request.RequestContainer()

        info_bus_request = InfoBus.InfoBusRequestContent()
        info_bus_request.infoType = type

        request_container.infoBus.CopyFrom(info_bus_request)

        data_length = request_container.ByteSize().to_bytes(1, "big")
        data = request_container.SerializeToString()

        self.connection.write(data_length)
        self.connection.write(data)

        result_length_raw = self.connection.read(3)

        result_length = int.from_bytes(result_length_raw, 'big')

        result = self.connection.read(result_length)

        response_container = Response.ResponseContainer()
        response_container.ParseFromString(result)

        return response_container

    def send_info_bus_request_gain_info_type_content(self) -> RetrievedInfoDto:
        """Sends request to the board via info bus to retrieve info of gain type."""

        data = self.__send_info_bus_request_content(InfoBus.InfoType.Gain)

        return RetrievedInfoDto(
            data.infoBus.deviceId,
            InfoTypeCompound.GAIN,
            data.infoBus.value,
            data.infoBus.nonce)

    def send_info_bus_request_integral_time_info_type_content(self) -> RetrievedInfoDto:
        """Sends request to the board via info bus to retrieve info of integral time type."""

        data = self.__send_info_bus_request_content(InfoBus.InfoType.IntegralTime)

        return RetrievedInfoDto(
            data.infoBus.deviceId,
            InfoTypeCompound.INTEGRAL_TIME,
            data.infoBus.value,
            data.infoBus.nonce)

    def send_info_bus_request_processed_requests_info_type_content(self) -> RetrievedInfoDto:
        """Sends request to the board via info bus to retrieve info of processed requests time type."""

        data = self.__send_info_bus_request_content(InfoBus.InfoType.ProcessedRequests)

        return RetrievedInfoDto(
            data.infoBus.deviceId,
            InfoTypeCompound.PROCESSED_REQUESTS,
            data.infoBus.value,
            data.infoBus.nonce)

    def send_info_bus_request_device_available_info_type_content(self) -> RetrievedInfoDto:
        """Sends request to the board via info bus to retrieve info of device available time type."""

        data = self.__send_info_bus_request_content(InfoBus.InfoType.DeviceAvailable)

        return RetrievedInfoDto(
            data.infoBus.deviceId,
            InfoTypeCompound.DEVICE_AVAILABLE,
            data.infoBus.value,
            data.infoBus.nonce)

    def __send_settings_bus_request_content(self, type: SettingsBus.SettingsType) -> Response.ResponseContainer:
        """Sends request to the board via settings bus to set settings."""

        request_container = Request.RequestContainer()

        settings_bus_request = SettingsBus.SettingsBusRequestContent()
        settings_bus_request.settingsType = type

        request_container.settingsBus.CopyFrom(settings_bus_request)

        data_length = request_container.ByteSize().to_bytes(1, "big")
        data = request_container.SerializeToString()

        self.connection.write(data_length)
        self.connection.write(data)

        result_length_raw = self.connection.read(3)

        result_length = int.from_bytes(result_length_raw, 'big')

        result = self.connection.read(result_length)

        response_container = Response.ResponseContainer()
        response_container.ParseFromString(result)

        return response_container

    def send_settings_bus_request_reset_settings_type_content(self) -> SetSettingsDto:
        """Sends request to the board via settings bus to set setting of reset type."""

        data = self.__send_settings_bus_request_content(SettingsBus.SettingsType.Reset)

        return SetSettingsDto(
            data.settingsBus.deviceId,
            SettingsTypeCompound.RESET,
            data.settingsBus.result,
            data.settingsBus.nonce)

    def send_settings_bus_request_set_gain_low_settings_type_content(self) -> SetSettingsDto:
        """Sends request to the board via settings bus to set setting of set gain low type."""

        data = self.__send_settings_bus_request_content(
            SettingsBus.SettingsType.SetGainLow)

        return SetSettingsDto(
            data.settingsBus.deviceId,
            SettingsTypeCompound.SET_GAIN_LOW,
            data.settingsBus.result,
            data.settingsBus.nonce)

    def send_settings_bus_request_set_gain_medium_settings_type_content(self) -> SetSettingsDto:
        """Sends request to the board via settings bus to set setting of set gain medium type."""

        data = self.__send_settings_bus_request_content(
            SettingsBus.SettingsType.SetGainMedium)

        return SetSettingsDto(
            data.settingsBus.deviceId,
            SettingsTypeCompound.SET_GAIN_MEDIUM,
            data.settingsBus.result,
            data.settingsBus.nonce)

    def send_settings_bus_request_set_gain_high_settings_type_content(self) -> SetSettingsDto:
        """Sends request to the board via settings bus to set setting of set gain high type."""

        data = self.__send_settings_bus_request_content(
            SettingsBus.SettingsType.SetGainHigh)

        return SetSettingsDto(
            data.settingsBus.deviceId,
            SettingsTypeCompound.SET_GAIN_HIGH,
            data.settingsBus.result,
            data.settingsBus.nonce)

    def send_settings_bus_request_set_gain_max_settings_type_content(self) -> SetSettingsDto:
        """Sends request to the board via settings bus to set setting of set gain max type."""

        data = self.__send_settings_bus_request_content(
            SettingsBus.SettingsType.SetGainMax)

        return SetSettingsDto(
            data.settingsBus.deviceId,
            SettingsTypeCompound.SET_GAIN_MAX,
            data.settingsBus.result,
            data.settingsBus.nonce)

    def send_settings_bus_request_set_integral_time_first_settings_type_content(self) -> SetSettingsDto:
        """Sends request to the board via settings bus to set setting of set integral time first type."""

        data = self.__send_settings_bus_request_content(
            SettingsBus.SettingsType.SetIntegralTimeFirst)

        return SetSettingsDto(
            data.settingsBus.deviceId,
            SettingsTypeCompound.SET_INTEGRAL_TIME_FIRST,
            data.settingsBus.result,
            data.settingsBus.nonce)

    def send_settings_bus_request_set_integral_time_second_settings_type_content(self) -> SetSettingsDto:
        """Sends request to the board via settings bus to set setting of set integral time second type."""

        data = self.__send_settings_bus_request_content(
            SettingsBus.SettingsType.SetIntegralTimeSecond)

        return SetSettingsDto(
            data.settingsBus.deviceId,
            SettingsTypeCompound.SET_INTEGRAL_TIME_SECOND,
            data.settingsBus.result,
            data.settingsBus.nonce)

    def send_settings_bus_request_set_integral_time_third_settings_type_content(self) -> SetSettingsDto:
        """Sends request to the board via settings bus to set setting of set integral time third type."""

        data = self.__send_settings_bus_request_content(
            SettingsBus.SettingsType.SetIntegralTimeThird)

        return SetSettingsDto(
            data.settingsBus.deviceId,
            SettingsTypeCompound.SET_INTEGRAL_TIME_THIRD,
            data.settingsBus.result,
            data.settingsBus.nonce)

    def send_settings_bus_request_set_integral_time_forth_settings_type_content(self) -> SetSettingsDto:
        """Sends request to the board via settings bus to set setting of set integral time forth type."""

        data = self.__send_settings_bus_request_content(
            SettingsBus.SettingsType.SetIntegralTimeForth)

        return SetSettingsDto(
            data.settingsBus.deviceId,
            SettingsTypeCompound.SET_INTEGRAL_TIME_FORTH,
            data.settingsBus.result,
            data.settingsBus.nonce)

    def send_settings_bus_request_set_integral_time_fifth_settings_type_content(self) -> SetSettingsDto:
        """Sends request to the board via settings bus to set setting of set integral time fifth type."""

        data = self.__send_settings_bus_request_content(
            SettingsBus.SettingsType.SetIntegralTimeFifth)

        return SetSettingsDto(
            data.settingsBus.deviceId,
            SettingsTypeCompound.SET_INTEGRAL_TIME_FIFTH,
            data.settingsBus.result,
            data.settingsBus.nonce)

    def send_settings_bus_request_set_integral_time_sixth_settings_type_content(self) -> SetSettingsDto:
        """Sends request to the board via settings bus to set setting of set integral time sixth type."""

        data = self.__send_settings_bus_request_content(
            SettingsBus.SettingsType.SetIntegralTimeSixth)

        return SetSettingsDto(
            data.settingsBus.deviceId,
            SettingsTypeCompound.SET_INTEGRAL_TIME_SIXTH,
            data.settingsBus.result,
            data.settingsBus.nonce)

    def __exit__(self, exc_type, exc_val, exc_tb):
        """Closes client connection."""

        self.connection.close()
