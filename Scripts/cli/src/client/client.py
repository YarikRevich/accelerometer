import logging
import time
from datetime import datetime

from serial import Serial
from serial import SerialException
from serial import EIGHTBITS

from proto.Content import data_pb2 as DataBus
from proto.Content import settings_pb2 as SettingsBus
from proto import request_pb2 as Request
from proto import response_pb2 as Response

from dto import DataTypeCompound
from dto import RetrievedDataDto
from dto import RawDataTypeValue
from dto import SettingsTypeCompound
from dto import SetSettingsDto


class Client:
    """Represents client used to connect to remote device via serial port."""

    # Represents chosen device location.
    device: str

    # Represents chosen device baud rate.
    baud_rate: int

    # Represents interruption duration between requests.
    interruption: int

    # Represents a connection with serial device.
    connection: Serial

    def __init__(self, device: str, baud_rate: int, interruption: int):
        self.device = device
        self.baud_rate = baud_rate
        self.interruption = interruption

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

        time.sleep(self.interruption)

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
            data.dataBus.suspended,
            RawDataTypeValue(
                data.dataBus.raw.x, data.dataBus.raw.y, data.dataBus.raw.z),
            data.dataBus.nonce)

    def __send_settings_bus_request_content(self, type: SettingsBus.SettingsType) -> Response.ResponseContainer:
        """Sends request to the board via settings bus to set settings."""

        request_container = Request.RequestContainer()

        settings_bus_request = SettingsBus.SettingsBusRequestContent()
        settings_bus_request.settingsType = type

        request_container.settingsBus.CopyFrom(settings_bus_request)

        data_length = request_container.ByteSize().to_bytes(1, "big")
        data = request_container.SerializeToString()

        self.connection.write(data_length)

        time.sleep(self.interruption)

        self.connection.write(data)

        result_length_raw = self.connection.read(3)

        result_length = int.from_bytes(result_length_raw, 'big')

        result = self.connection.read(result_length)

        response_container = Response.ResponseContainer()
        response_container.ParseFromString(result)

        return response_container

    def send_settings_bus_request_set_suspend_settings_type_content(self) -> SetSettingsDto:
        """Sends request to the board via settings bus to set setting of reset type."""

        data = self.__send_settings_bus_request_content(SettingsBus.SettingsType.SetSuspend)

        return SetSettingsDto(
            data.settingsBus.deviceId,
            SettingsTypeCompound.SET_SUSPEND,
            data.settingsBus.result,
            data.settingsBus.nonce)

    def send_settings_bus_request_set_serve_settings_type_content(self) -> SetSettingsDto:
        """Sends request to the board via settings bus to set setting of set gain low type."""

        data = self.__send_settings_bus_request_content(
            SettingsBus.SettingsType.SetServe)

        return SetSettingsDto(
            data.settingsBus.deviceId,
            SettingsTypeCompound.SET_SERVE,
            data.settingsBus.result,
            data.settingsBus.nonce)

    def __exit__(self, exc_type, exc_val, exc_tb):
        """Closes client connection."""

        self.connection.close()
