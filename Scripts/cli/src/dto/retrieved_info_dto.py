from enum import Enum


class InfoTypeCompound(Enum):
    """Represents info compound used to represent result info type."""

    # Represents 'gain' info type.
    GAIN = 'Gain'

    # Represents 'integral_time' info type.
    INTEGRAL_TIME = 'IntegralTime'

    # Represents 'processed_requests' info type.
    PROCESSED_REQUESTS = 'ProcessedRequests'

    # Represents 'device_available' info type.
    DEVICE_AVAILABLE = 'DeviceAvailable'


class RetrievedInfoDto:
    """Represents dto used to hold the result of a 'get_info' command."""

    # Represents remote device identification number.
    device_id: int

    # Represents info type of the received result.
    info_type: InfoTypeCompound

    # Represents value of the received result.
    value: int

    # Represents nonce of the received result.
    nonce: int

    def __init__(self, device_id: int, info_type: InfoTypeCompound, value: int, nonce: int):
        self.device_id = device_id
        self.info_type = info_type
        self.value = value
        self.nonce = nonce
