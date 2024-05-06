from typing import Optional

from .get_available_devices import GetAvailableDevicesCommand
from .get_data import GetDataCommand
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
