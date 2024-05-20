import os
from pathlib import Path


class Config:
    """Represents a set of helpful functions for application state management."""

    # Represents application configuration files location.
    ACCELEROMETER_CONFIG_LOCATION: str = ".accelerometer"

    # Represents process identification file.
    ACCELEROMETER_GET_PROCESS_FILE_LOCATION: str = "get_process"

    # Represents default memory file location.
    ACCELEROMETER_DEFAULT_MEMORY_FILE_LOCATION: str = "memory.out"

    @staticmethod
    def is_get_process_exist() -> bool:
        """Checks if 'get' process exists."""

        return os.path.exists(
            os.path.join(Path.home(),
                         Config.ACCELEROMETER_CONFIG_LOCATION,
                         Config.ACCELEROMETER_GET_PROCESS_FILE_LOCATION))

    @staticmethod
    def create_get_process_file() -> None:
        """Creates new get process file."""

        if not os.path.exists(Config.ACCELEROMETER_CONFIG_LOCATION):
            os.makedirs(Config.ACCELEROMETER_CONFIG_LOCATION)

        with open(os.path.join(Path.home(),
                               Config.ACCELEROMETER_CONFIG_LOCATION,
                               Config.ACCELEROMETER_GET_PROCESS_FILE_LOCATION), 'w+') as file:
            file.write(str(os.getpid()))

    @staticmethod
    def remove_get_process_file() -> None:
        """Creates new get process file."""

        os.remove(os.path.join(Path.home(),
                               Config.ACCELEROMETER_CONFIG_LOCATION,
                               Config.ACCELEROMETER_GET_PROCESS_FILE_LOCATION))

    @staticmethod
    def get_get_process_file_content() -> int:
        """Read get process file content."""

        with open(os.path.join(Path.home(),
                               Config.ACCELEROMETER_CONFIG_LOCATION,
                               Config.ACCELEROMETER_GET_PROCESS_FILE_LOCATION), 'r') as file:
            return int(file.readline())

    @staticmethod
    def get_default_memory_file_location() -> str:
        """Retrieves default memory file location."""

        return os.path.join(Path.home(),
                            Config.ACCELEROMETER_CONFIG_LOCATION,
                            Config.ACCELEROMETER_DEFAULT_MEMORY_FILE_LOCATION)