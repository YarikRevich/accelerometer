import logging

from middleware import is_device_available
from dto import RetrievedInfoDto
from client import Client
from tools import print_output


class GetInfoCommand:
    """Represents 'get_info' command."""

    GAIN_TYPE: str = "gain"
    INTEGRAL_TIME_TYPE: str = "integral_time"
    PROCESSED_REQUESTS_TYPE: str = "processed_requests"
    DEVICE_AVAILABLE_TYPE: str = "device_available"

    @staticmethod
    def handle(device: str, baud_rate: int, type: str) -> None:
        """Handles the execution of command wrapper."""

        if not is_device_available(device):
            logging.error("Selected device is not available")
            return

        data: RetrievedInfoDto

        match type:
            case GetInfoCommand.GAIN_TYPE:
                data = GetInfoCommand.process_get_gain_info(device, baud_rate)

            case GetInfoCommand.INTEGRAL_TIME_TYPE:
                data = GetInfoCommand.process_get_integral_time_info(device, baud_rate)

            case GetInfoCommand.PROCESSED_REQUESTS_TYPE:
                data = GetInfoCommand.process_get_processed_requests_info(device, baud_rate)

            case GetInfoCommand.DEVICE_AVAILABLE_TYPE:
                data = GetInfoCommand.process_get_device_available_info(device, baud_rate)

            case _:
                logging.error("Given info type is not valid.")
                return

        print_output(data)
        logging.info("Info has been successfully retrieved.")

    @staticmethod
    def process_get_gain_info(device: str, baud_rate: int) -> RetrievedInfoDto:
        """Processes request to retrieve 'gain' metadata info from the device"""

        with Client(device, baud_rate) as client:
            return client.send_info_bus_request_gain_info_type_content()

    @staticmethod
    def process_get_integral_time_info(device: str, baud_rate: int) -> RetrievedInfoDto:
        """Processes request to retrieve 'integral_time' metadata info from the device"""

        with Client(device, baud_rate) as client:
            return client.send_info_bus_request_integral_time_info_type_content()

    @staticmethod
    def process_get_processed_requests_info(device: str, baud_rate: int) -> RetrievedInfoDto:
        """Processes request to retrieve 'processed_requests' metadata info from the device"""

        with Client(device, baud_rate) as client:
            return client.send_info_bus_request_processed_requests_info_type_content()

    @staticmethod
    def process_get_device_available_info(device: str, baud_rate: int) -> RetrievedInfoDto:
        """Processes request to retrieve 'device_available' metadata info from the device"""

        with Client(device, baud_rate) as client:
            return client.send_info_bus_request_device_available_info_type_content()
