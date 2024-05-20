from tkinter import Tk, TOP, BOTH
from matplotlib.backends.backend_tkagg import (FigureCanvasTkAgg)
import matplotlib.pyplot as plt

from dto import RetrievedDataDto


class LiveVisualizer:
    """Represents visualizer used to create figures from the given values in a live view."""

    # Represents a collection of values used for visualization generation.
    values: list[RetrievedDataDto] = []

    # Represents figure canvas instance.
    canvas: FigureCanvasTkAgg

    # Represents created figure plot.
    plot: plt.Axes

    def __init__(self):
        figure = plt.Figure(figsize=(10, 5), dpi=80)

        self.plot = figure.add_subplot(111)

        window = Tk()

        window.wm_title("accelerometer")

        self.canvas = FigureCanvasTkAgg(figure, master=window)
        self.canvas.draw()
        self.canvas.get_tk_widget().pack(side=TOP, fill=BOTH, expand=1)

    def set_values(self, values: list[RetrievedDataDto]) -> None:
        """Sets a set of values used for visualization."""

        self.values = values

    def select_plot(self) -> None:
        """Selects plot figure as the output visualization type."""

        self.plot.clear()
        self.plot.plot([unit.value.x for unit in self.values], 'r-', label='x')
        self.plot.plot([unit.value.y for unit in self.values], 'g-', label='y')
        self.plot.plot([unit.value.z for unit in self.values], 'b-', label='z')
        self.plot.set_title("Accelerometer")
        self.plot.legend(bbox_to_anchor=(0.9, 1.0), loc='upper left')
        plt.ylabel("Accelerometer value")
        plt.xlabel("Amount of measurements")

    def draw(self) -> None:
        """Draws selected figure."""

        self.canvas.draw()
        self.canvas.flush_events()

