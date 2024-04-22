import logging
from typing import Optional

from middleware import is_device_available
from dto import SetSettingsDto
from client import Client
from tools import print_output


class SetSettingsCommand:
    """Represents 'set_settings' command."""

    # Represents 'reset' type of the setting(does not allow any value).
    RESET_TYPE: str = "reset"

    # Represents 'set_gain' type of the setting.
    SET_GAIN_TYPE: str = "set_gain"

    # Represents 'low' type of value for 'set_gain' type of setting.
    SET_GAIN_LOW_VALUE_TYPE: str = "low"

    # Represents 'medium' type of value for 'set_gain' type of setting.
    SET_GAIN_MEDIUM_VALUE_TYPE: str = "medium"

    # Represents 'high' type of value for 'set_gain' type of setting.
    SET_GAIN_HIGH_VALUE_TYPE: str = "high"

    # Represents 'max' type of value for 'set_gain' type of setting.
    SET_GAIN_MAX_VALUE_TYPE: str = "max"

    # Represents 'set_integral_time' type of the setting.
    SET_INTEGRAL_TIME_TYPE: str = "set_integral_time"

    # Represents 'first' type of value for 'set_integral_time' type of setting.
    SET_INTEGRAL_TIME_FIRST_VALUE_TYPE: str = "first"

    # Represents 'second' type of value for 'set_integral_time' type of setting.
    SET_INTEGRAL_TIME_SECOND_VALUE_TYPE: str = "second"

    # Represents 'third' type of value for 'set_integral_time' type of setting.
    SET_INTEGRAL_TIME_THIRD_VALUE_TYPE: str = "third"

    # Represents 'forth' type of value for 'set_integral_time' type of setting.
    SET_INTEGRAL_TIME_FORTH_VALUE_TYPE: str = "forth"

    # Represents 'fifth' type of value for 'set_integral_time' type of setting.
    SET_INTEGRAL_TIME_FIFTH_VALUE_TYPE: str = "fifth"

    # Represents 'sixth' type of value for 'set_integral_time' type of setting.
    SET_INTEGRAL_TIME_SIXTH_VALUE_TYPE: str = "sixth"

    @staticmethod
    def handle(device: str, baud_rate: int, type: str, value: Optional[str] = None) -> None:
        """Handles the execution of command wrapper."""

        if not is_device_available(device):
            logging.error("Selected device is not available")
            return

        data: SetSettingsDto

        match type:
            case SetSettingsCommand.RESET_TYPE:
                data = SetSettingsCommand.process_reset_settings(device, baud_rate)

            case SetSettingsCommand.SET_GAIN_TYPE:
                match value:
                    case SetSettingsCommand.SET_GAIN_LOW_VALUE_TYPE:
                        data = SetSettingsCommand.process_set_gain_low_settings(device, baud_rate)

                    case SetSettingsCommand.SET_GAIN_MEDIUM_VALUE_TYPE:
                        data = SetSettingsCommand.process_set_gain_medium_settings(device, baud_rate)

                    case SetSettingsCommand.SET_GAIN_HIGH_VALUE_TYPE:
                        data = SetSettingsCommand.process_set_gain_high_settings(device, baud_rate)

                    case SetSettingsCommand.SET_GAIN_MAX_VALUE_TYPE:
                        data = SetSettingsCommand.process_set_gain_max_settings(device, baud_rate)

                    case _:
                        logging.error("Given settings value type is not valid.")
                        return

            case SetSettingsCommand.SET_INTEGRAL_TIME_TYPE:
                match value:
                    case SetSettingsCommand.SET_INTEGRAL_TIME_FIRST_VALUE_TYPE:
                        data = SetSettingsCommand.process_set_integral_time_first_settings(
                            device, baud_rate)

                    case SetSettingsCommand.SET_INTEGRAL_TIME_SECOND_VALUE_TYPE:
                        data = SetSettingsCommand.process_set_integral_time_second_settings(
                            device, baud_rate)

                    case SetSettingsCommand.SET_INTEGRAL_TIME_THIRD_VALUE_TYPE:
                        data = SetSettingsCommand.process_set_integral_time_third_settings(
                            device, baud_rate)

                    case SetSettingsCommand.SET_INTEGRAL_TIME_FORTH_VALUE_TYPE:
                        data = SetSettingsCommand.process_set_integral_time_forth_settings(
                            device, baud_rate)

                    case SetSettingsCommand.SET_INTEGRAL_TIME_FIFTH_VALUE_TYPE:
                        data = SetSettingsCommand.process_set_integral_time_fifth_settings(
                            device, baud_rate)

                    case SetSettingsCommand.SET_INTEGRAL_TIME_SIXTH_VALUE_TYPE:
                        data = SetSettingsCommand.process_set_integral_time_sixth_settings(
                            device, baud_rate)

                    case _:
                        logging.error("Given settings value type is not valid.")
                        return

            case _:
                logging.error("Given settings type is not valid.")
                return

        print_output(data)
        logging.info("Settings has been successfully set.")

    @staticmethod
    def process_reset_settings(device: str, baud_rate: int) -> SetSettingsDto:
        """Processes request to set 'reset' setting to the device."""

        with Client(device, baud_rate) as client:
            return client.send_settings_bus_request_reset_settings_type_content()

    @staticmethod
    def process_set_gain_low_settings(device: str, baud_rate: int) -> SetSettingsDto:
        """Processes request to set 'set_gain' with 'low' value setting to the device."""

        with Client(device, baud_rate) as client:
            return client.send_settings_bus_request_set_gain_low_settings_type_content()

    @staticmethod
    def process_set_gain_medium_settings(device: str, baud_rate: int) -> SetSettingsDto:
        """Processes request to set 'set_gain' with 'medium' value setting to the device."""

        with Client(device, baud_rate) as client:
            return client.send_settings_bus_request_set_gain_medium_settings_type_content()

    @staticmethod
    def process_set_gain_high_settings(device: str, baud_rate: int) -> SetSettingsDto:
        """Processes request to set 'set_gain' with 'high' value setting to the device."""

        with Client(device, baud_rate) as client:
            return client.send_settings_bus_request_set_gain_high_settings_type_content()

    @staticmethod
    def process_set_gain_max_settings(device: str, baud_rate: int) -> SetSettingsDto:
        """Processes request to set 'set_gain' with 'max' value setting to the device."""

        with Client(device, baud_rate) as client:
            return client.send_settings_bus_request_set_gain_max_settings_type_content()

    @staticmethod
    def process_set_integral_time_first_settings(device: str, baud_rate: int) -> SetSettingsDto:
        """Processes request to set 'set_integral_time' with 'first' value setting to the device."""

        with Client(device, baud_rate) as client:
            return client.send_settings_bus_request_set_integral_time_first_settings_type_content()

    @staticmethod
    def process_set_integral_time_second_settings(device: str, baud_rate: int) -> SetSettingsDto:
        """Processes request to set 'set_integral_time' with 'second' value setting to the device."""

        with Client(device, baud_rate) as client:
            return client.send_settings_bus_request_set_integral_time_second_settings_type_content()

    @staticmethod
    def process_set_integral_time_third_settings(device: str, baud_rate: int) -> SetSettingsDto:
        """Processes request to set 'set_integral_time' with 'third' value setting to the device."""

        with Client(device, baud_rate) as client:
            return client.send_settings_bus_request_set_integral_time_third_settings_type_content()

    @staticmethod
    def process_set_integral_time_forth_settings(device: str, baud_rate: int) -> SetSettingsDto:
        """Processes request to set 'set_integral_time' with 'forth' value setting to the device."""

        with Client(device, baud_rate) as client:
            return client.send_settings_bus_request_set_integral_time_forth_settings_type_content()

    @staticmethod
    def process_set_integral_time_fifth_settings(device: str, baud_rate: int) -> SetSettingsDto:
        """Processes request to set 'set_integral_time' with 'fifth' value setting to the device."""

        with Client(device, baud_rate) as client:
            return client.send_settings_bus_request_set_integral_time_fifth_settings_type_content()

    @staticmethod
    def process_set_integral_time_sixth_settings(device: str, baud_rate: int) -> SetSettingsDto:
        """Processes request to set 'set_integral_time' with 'sixth' value setting to the device."""

        with Client(device, baud_rate) as client:
            return client.send_settings_bus_request_set_integral_time_sixth_settings_type_content()
