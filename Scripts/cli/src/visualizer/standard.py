import matplotlib.pyplot as plt

from dto import RetrievedDataDto
from dto import StandardVisualizerMetadataDto


class StandardVisualizer:
    """Represents visualizer used to create figures from the given values in a standard view."""

    # Represents a path where generated visualization will be saved.
    location: str

    # Represents a collection of values used for visualization generation.
    values: list[RetrievedDataDto]

    # Represents metadata used for diagram drawing.
    metadata: StandardVisualizerMetadataDto

    # Represents a base plot figure.
    figure: plt.Figure

    # Represents created figure plot.
    plot: plt.Axes

    def __init__(self, location: str, values: list[RetrievedDataDto], metadata: StandardVisualizerMetadataDto):
        self.location = location
        self.values = values
        self.metadata = metadata

        self.figure = plt.figure()

        self.plot = self.figure.add_subplot(111)

    def select_scatter(self) -> None:
        """Selects scatter figure as the output visualization type."""

        data = [value.value for value in self.values]

        self.plot.scatter(data[:-1], data[1:], s=100, alpha=0.5)

        plt.title(f'series = {self.metadata.series}; data type = {self.metadata.data_type}')
        plt.ylabel("Accelerometer value")
        plt.xlabel("Accelerometer value")

    def select_stairs(self) -> None:
        """Selects stairs figure as the output visualization type."""

        self.plot.stairs([value.value for value in self.values], linewidth=1)

        plt.title(f'series = {self.metadata.series}; data type = {self.metadata.data_type}')
        plt.ylabel("Accelerometer value")
        plt.xlabel("Amount of measurements")

    def select_plot(self) -> None:
        """Selects plot figure as the output visualization type."""

        self.plot.plot([value.value for value in self.values])

        plt.title(f'series = {self.metadata.series}; data type = {self.metadata.data_type}')
        plt.ylabel("Accelerometer value")
        plt.xlabel("Amount of measurements")

    def save(self) -> None:
        """Saves select figure in the given location."""

        self.figure.savefig(self.location)
        plt.close(self.figure)