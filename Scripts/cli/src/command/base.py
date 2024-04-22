from typing import Optional

from .get_available_devices import GetAvailableDevicesCommand
from .get_data import GetDataCommand
from .get_info import GetInfoCommand
from .set_settings import SetSettingsCommand
from visualizer import Visualizer


class BaseCommand:
    """Represents base command handler."""

    @staticmethod
    def get_available_devices() -> None:
        """Returns all the available compatible devices connected to serial ports."""

        GetAvailableDevicesCommand.handle()

    @staticmethod
    def get_data(device: str, baud_rate: int, type: str, series: int = 1, export: str = None, generate: bool = False,
                 figure: str = Visualizer.PLOT_FIGURE) -> None:
        """
        Returns sensor data of selected type. The available data types are 'raw', 'full', 'infrared', 'visible'.
        Allows to perform a series of measurements and export that data to a graph view. The available figure types are
        'scatter', 'plot', 'stairs' and 'bar'.
        """

        GetDataCommand.handle(device, baud_rate, type, series, export, generate, figure)

    @staticmethod
    def get_info(device: str, baud_rate: int, type: str) -> None:
        """
        Returns selected metadata info retrieved from the board.
        The available info types are 'gain'('0'(low), '16'(medium), '32'(high), '48'(max)),
        'integral_time'('0'(100ms), '1'(200ms), '2'(300ms), '3'(400ms), '4'(500ms), '5'(600ms)), 'processed_requests'
        """

        GetInfoCommand.handle(device, baud_rate, type)

    @staticmethod
    def set_settings(device: str, baud_rate: int, type: str, value: Optional[str] = None) -> None:
        """
        Sets given settings to the board.
        The available settings types are 'reset', 'set_gain'(with values 'low', 'medium', 'high', 'max'),
        'set_integral_time'(with values 'first'(100ms), 'second'(200ms), 'third'(300ms), 'forth'(400ms), 'fifth'(500mx),
        'sixth'(600ms)).
        """

        SetSettingsCommand.handle(device, baud_rate, type, value)
