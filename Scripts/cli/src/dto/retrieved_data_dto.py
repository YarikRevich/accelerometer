from enum import Enum


class DataTypeCompound(Enum):
    """Represents data compound used to represent result data type."""

    # Represents 'raw' data type.
    RAW = 'Raw'

    # Represents 'full' data type.
    FULL = 'Full'

    # Represents 'infrared' data type.
    INFRARED = 'Infrared'

    # Represents 'visible' data type.
    VISIBLE = 'Visible'


class RetrievedDataDto:
    """Represents dto used to hold the result of a 'get_data' command."""

    # Represents remote device identification number.
    device_id: int

    # Represents data type of the received result.
    data_type: DataTypeCompound

    # Represents value of the received result.
    value: int

    # Represents nonce of the received result.
    nonce: int

    def __init__(self, device_id: int, data_type: DataTypeCompound, value: int, nonce: int):
        self.device_id = device_id
        self.data_type = data_type
        self.value = value
        self.nonce = nonce
