import time
from typing import Optional
import os
import signal

from .get_available_devices import GetAvailableDevicesCommand
from .get_data import GetDataCommand
from .set_settings import SetSettingsCommand

import memory

import visualizer

from config import Config

from tools import perform_shutdown_await


class BaseCommand:
    """Represents base command handler."""

    @staticmethod
    def get_available_devices() -> None:
        """Returns all the available compatible devices connected to serial ports."""

        GetAvailableDevicesCommand.handle()

    @staticmethod
    def get_data(device: str, baud_rate: int, type: str, memory_path: str = os.getenv("HOME"), memorize: bool = True,
                 memory: str = memory.Common.CSV_MEMORY, memory_shift: int = 10, interruption: int = 0.3, series: int = 1,
                 live: bool = False, export: str = None, figure: str = visualizer.Common.PLOT_FIGURE) -> None:
        """
        Returns sensor data of selected type. The available data types are 'raw', 'full', 'infrared', 'visible'.
        Allows to perform a series of measurements and export that data to a graph view. The available figure types are
        'scatter', 'plot', 'stairs' and 'bar'.
        """

        Config.create_get_process_file()

        GetDataCommand.handle(device, baud_rate, memory_path, memorize, memory, memory_shift, interruption, type, series,
                              live, export, figure)

        Config.remove_get_process_file()

    @staticmethod
    def set_settings(device: str, baud_rate: int, type: str, interruption: int = 0.3, value: Optional[str] = None) -> None:
        """
        Sets given settings to the board.
        The available settings types are 'set_suspend', 'set_serve'.
        """

        if Config.is_get_process_exist():
            os.kill(Config.get_get_process_file_content(), signal.SIGTERM)

            Config.remove_get_process_file()

            perform_shutdown_await()

        SetSettingsCommand.handle(device, baud_rate, interruption, type, value)
