import logging
from typing import Optional

from middleware import is_device_available
from dto import SetSettingsDto
from client import Client
from tools import print_output

class SetSettingsCommand:
    """Represents 'set_settings' command."""

    # Represents 'reset' type of the setting(does not allow any value).
    SET_SUSPEND_TYPE: str = "set_suspend"

    # Represents 'reset' type of the setting(does not allow any value).
    SET_SERVE_TYPE: str = "set_serve"

    @staticmethod
    def handle(device: str, baud_rate: int, interruption: int, type: str, value: Optional[str] = None) -> None:
        """Handles the execution of command wrapper."""

        if not is_device_available(device):
            logging.error("Selected device is not available")
            return

        data: SetSettingsDto

        match type:
            case SetSettingsCommand.SET_SUSPEND_TYPE:
                data = SetSettingsCommand.process_set_suspend_settings(device, baud_rate, interruption)

            case SetSettingsCommand.SET_SERVE_TYPE:
                data = SetSettingsCommand.process_set_serve_settings(device, baud_rate, interruption)

            case _:
                logging.error("Given settings type is not valid.")
                return

        print_output(data)
        logging.info("Settings has been successfully set.")

    @staticmethod
    def process_set_suspend_settings(device: str, baud_rate: int, interruption: int) -> SetSettingsDto:
        """Processes request to set 'set_suspend' setting to the device."""

        with Client(device, baud_rate, interruption) as client:
            return client.send_settings_bus_request_set_suspend_settings_type_content()

    @staticmethod
    def process_set_serve_settings(device: str, baud_rate: int, interruption: int) -> SetSettingsDto:
        """Processes request to set 'set_serve' setting to the device."""

        with Client(device, baud_rate, interruption) as client:
            return client.send_settings_bus_request_set_serve_settings_type_content()
