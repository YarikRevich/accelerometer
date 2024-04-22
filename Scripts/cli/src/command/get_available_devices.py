import logging
from serial.tools import list_ports

from middleware import is_manufacturer_allowed
from middleware import is_description_valid
from dto import AvailableDevicesDto
from tools import print_output


class GetAvailableDevicesCommand:
    """Represents 'get_available_devices' command."""

    @staticmethod
    def handle() -> None:
        """Handles the execution of command wrapper."""

        result = []

        for entity in list_ports.comports():
            if is_manufacturer_allowed(entity.manufacturer) and is_description_valid(entity.description):
                result.append(AvailableDevicesDto(entity.description, entity.manufacturer, entity.device))

        if len(result) > 0:
            print_output(result)

            logging.info("Available devices have been successfully retrieved.")
        else:
            logging.error("No available devices found.")
