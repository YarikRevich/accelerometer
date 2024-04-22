class VisualizerMetadataDto:
    """Represents dto used to hold the metadata for visualizer."""

    # Represents data type of the received result.
    data_type: str

    # Represents series of measurements to receive the result.
    series: int

    def __init__(self, data_type: str, series: int):
        self.data_type = data_type
        self.series = series
