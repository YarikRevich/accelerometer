import logging
import time

from middleware import is_device_available
from middleware import is_export_valid

from visualizer import Common
from visualizer import LiveVisualizer
from visualizer import StandardVisualizer

from dto import RetrievedDataDto
from dto import StandardVisualizerMetadataDto
from client import Client
from tools import print_output

from tools import perform_request_await

class GetDataCommand:
    """Represents 'get_data' command."""

    RAW_TYPE: str = "raw"

    @staticmethod
    def handle(device: str, baud_rate: int, interruption: int, type: str, series: int, live: bool, export: str,
               figure: str) -> None:
        """Handles the execution of command wrapper."""

        if not is_device_available(device):
            logging.error("Selected device is not available")
            return

        if live:
            GetDataCommand.__handle_live(device, baud_rate, interruption, type, figure)
        else:
            GetDataCommand.__handle_standard(device, baud_rate, interruption, type, series, export, figure)

    @staticmethod
    def __handle_standard(device: str, baud_rate: int, interruption: int, type: str, series: int, export: str,
                          figure: str) -> None:
        """Handles the execution of command in a standard view."""

        data: list[RetrievedDataDto] = []

        for _ in range(series):
            match type:
                case GetDataCommand.RAW_TYPE:
                    unit = GetDataCommand.process_get_raw_data(device, baud_rate, interruption)

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
            visualizer = StandardVisualizer(export, data, StandardVisualizerMetadataDto(type, series))

            match figure:
                case Common.SCATTER_FIGURE:
                    visualizer.select_scatter()

                case Common.PLOT_FIGURE:
                    visualizer.select_plot()

                case Common.STAIRS_FIGURE:
                    visualizer.select_stairs()

                case _:
                    logging.error("Given figure type is not valid with standard view.")
                    return

            visualizer.save()

    @staticmethod
    def __handle_live(device: str, baud_rate: int, interruption: int, type: str, figure: str) -> None:
        """Handles the execution of command in a live view."""

        visualizer = LiveVisualizer()

        while True:
            unit: RetrievedDataDto

            match type:
                case GetDataCommand.RAW_TYPE:
                    unit = GetDataCommand.process_get_raw_data(device, baud_rate, interruption)

                    if unit.suspended == 1:
                        logging.error("Remote application is suspended.")
                        return

                case _:
                    logging.error("Given data type is not valid.")
                    return

            visualizer.alter_values(unit)

            match figure:
                case Common.PLOT_FIGURE:
                    visualizer.select_plot()

                case _:
                    logging.error("Given figure type is not valid with live view.")
                    return

            visualizer.draw()

            perform_request_await()

    @staticmethod
    def process_get_raw_data(device: str, baud_rate: int, interruption: int) -> RetrievedDataDto:
        """Processes request to retrieve 'raw' data from the device"""

        with Client(device, baud_rate, interruption) as client:
            return client.send_data_bus_request_raw_data_type_content()
