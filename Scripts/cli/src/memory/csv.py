import csv

from typing import Any


class CSVMemory:
    """Represents CSV memory exporter."""

    # Represents location for the export of generated memory file.
    location: str

    def __init__(self, location: str) -> None:
        self.location = location

    def export(self, values: Any) -> None:
        """Exports given values to the previously given location."""

        with open(self.location, 'w+') as csv_file:
            wr = csv.writer(csv_file, delimiter=',')
            for value in values:
                wr.writerow(list(value))
