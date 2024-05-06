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


class RetrievedDataDto:
    """Represents dto used to hold the result of a 'get_data' command."""

    # Represents remote device identification number.
    device_id: int

    # Represents data type of the received result.
    data_type: DataTypeCompound

    # Represents value of the received result.
    value: Union[RawDataTypeValue]

    # Represents nonce of the received result.
    nonce: int

    def __init__(self, device_id: int, data_type: DataTypeCompound, value: Union[RawDataTypeValue], nonce: int):
        self.device_id = device_id
        self.data_type = data_type
        self.value = value
        self.nonce = nonce
