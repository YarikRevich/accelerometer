from enum import Enum
from typing import Union


class DataTypeCompound(Enum):
    """Represents data compound used to represent result data type."""

    # Represents 'raw' data type.
    RAW = 'Raw'


class RawDataTypeValue:
    """Represents data compound used to represent raw data type result value."""

    # Represents X value compound.
    x: int

    # Represents Y value compound.
    y: int

    # Represents Z value compound.
    z: int

    def __init__(self, x: int, y: int, z: int):
        self.x = x
        self.y = y
        self.z = z

    def __iter__(self):
        return iter([self.x, self.y, self.z])


class RetrievedDataDto:
    """Represents dto used to hold the result of a 'get_data' command."""

    # Represents remote device identification number.
    device_id: int

    # Represents data type of the received result.
    data_type: DataTypeCompound

    # Represents if remote application has been suspended.
    suspended: bool

    # Represents value of the received result.
    value: Union[RawDataTypeValue]

    # Represents nonce of the received result.
    nonce: int

    # Represents timestamp of the received result.
    timestamp: str

    def __init__(
            self,
            device_id: int,
            data_type: DataTypeCompound,
            suspended: bool,
            value: Union[RawDataTypeValue],
            nonce: int,
            timestamp: str):
        self.device_id = device_id
        self.data_type = data_type
        self.suspended = suspended
        self.value = value
        self.nonce = nonce
        self.timestamp = timestamp

    def __iter__(self):
        return iter([self.device_id, self.data_type, self.suspended, list(self.value), self.nonce, self.timestamp])
