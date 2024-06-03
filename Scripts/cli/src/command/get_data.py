import logging
import time

from middleware import is_device_available
from middleware import is_export_valid

import visualizer
from visualizer import LiveVisualizer
from visualizer import StandardVisualizer

from memory import Common
from memory import CSVMemory

from dto import RetrievedDataDto
from dto import StandardVisualizerMetadataDto
from client import Client

from tools import print_output
from tools import perform_request_await

from threading import Thread


class GetDataCommand:
    """Represents 'get_data' command."""

    RAW_TYPE: str = "raw"

    @staticmethod
    def handle(device: str, baud_rate: int, memory_path: str, memorize: bool, memory: str, memory_shift: int,
               memory_shift_interrupt: int, memory_interrupt: int, interruption: int, type: str, series: int, live: bool,
               export: str, figure: str) -> None:
        """Handles the execution of command wrapper."""

        if not is_device_available(device):
            logging.error("Selected device is not available")
            return

        if live:
            GetDataCommand.__handle_live(
                device, baud_rate, memory_path, memorize, memory, memory_shift, memory_shift_interrupt, memory_interrupt,
                interruption, type, figure)
        else:
            GetDataCommand.__handle_standard(
                device, baud_rate, memory_path, memorize, memory, interruption, type, series, export, figure)

    @staticmethod
    def __handle_standard(device: str, baud_rate: int, memory_path: str, memorize: bool, memory: str,
                          interruption: int, type: str, series: int, export: str, figure: str) -> None:
        """Handles the execution of command in a standard view."""

        data: list[RetrievedDataDto] = []

        for _ in range(series):
            match type:
                case GetDataCommand.RAW_TYPE:
                    unit = GetDataCommand.__process_get_raw_data(device, baud_rate, interruption)

                    if unit.suspended == 1:
                        logging.error("Remote application is suspended.")
                        return

                    data.append(unit)

                case _:
                    logging.error("Given data type is not valid.")
                    return

        print_output(data)
        logging.info("Data has been successfully retrieved.")

        if series > 1 and is_export_valid(export):
            view = StandardVisualizer(export, data, StandardVisualizerMetadataDto(type, series))

            match figure:
                case visualizer.Common.SCATTER_FIGURE:
                    view.select_scatter()

                case visualizer.Common.PLOT_FIGURE:
                    view.select_plot()

                case visualizer.Common.STAIRS_FIGURE:
                    view.select_stairs()

                case _:
                    logging.error("Given figure type is not valid with standard view.")
                    return

            view.save()

        if memorize:
            match memory:
                case Common.CSV_MEMORY:
                    memorizer = CSVMemory(memory_path)

                case _:
                    logging.error("Given memory type is not valid with.")
                    return

            memorizer.export(data)

    @staticmethod
    def __handle_live(device: str, baud_rate: int, memory_path: str, memorize: bool, memory: str, memory_shift: int,
                      memory_shift_interrupt: int, memory_interrupt: int, interruption: int, type: str, figure: str) -> None:
        """Handles the execution of command in a live view."""

        data: list[RetrievedDataDto] = []

        view = LiveVisualizer(data)

        Thread(
            target=GetDataCommand.__process_get_raw_data_concurrent,
            args=([device, baud_rate, memory_path, memorize, memory, memory_shift, memory_shift_interrupt,
                   memory_interrupt, type, interruption, data])).start()

        while True:
            perform_request_await()

            match figure:
                case visualizer.Common.PLOT_FIGURE:
                    view.select_plot()

                case _:
                    logging.error("Given figure type is not valid with live view.")
                    return

            view.draw()

    @staticmethod
    def __process_get_raw_data_concurrent(
            device: str, baud_rate: int, memory_path: str, memorize: bool, memory: str, memory_shift: int,
            memory_shift_interrupt: int, memory_interrupt: int, type: str, interruption: int, data: list[RetrievedDataDto]) -> None:
        """Processes request to retrieve 'raw' data from the device in a concurrent way."""

        while True:
            time.sleep(memory_interrupt)

            perform_request_await()

            if memorize:
                if len(data) != 0 and len(data) % memory_shift == 0:
                    match memory:
                        case Common.CSV_MEMORY:
                            memorizer = CSVMemory(memory_path)

                        case _:
                            logging.error("Given memory type is not valid with.")
                            return

                    memorizer.export(data)

                    time.sleep(memory_shift_interrupt)

            unit: RetrievedDataDto

            match type:
                case GetDataCommand.RAW_TYPE:
                    unit = GetDataCommand.__process_get_raw_data(device, baud_rate, interruption)

                    if unit.suspended == 1:
                        logging.error("Remote application is suspended.")
                        return

                    data.append(unit)

                case _:
                    logging.error("Given data type is not valid.")
                    return

    @staticmethod
    def __process_get_raw_data(device: str, baud_rate: int, interruption: int) -> RetrievedDataDto:
        """Processes request to retrieve 'raw' data from the device"""

        with Client(device, baud_rate, interruption) as client:
            return client.send_data_bus_request_raw_data_type_content()
