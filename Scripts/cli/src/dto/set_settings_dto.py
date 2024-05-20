from enum import Enum


class SettingsTypeCompound(Enum):
    """Represents settings compound used to represent result settings type."""

    # Represents 'set_suspend' setting type.
    SET_SUSPEND = 'SetSuspend'

    # Represents 'set_serve' setting type.
    SET_SERVE = 'SetServe'


class SetSettingsDto:
    """Represents dto used to hold the result of a 'set_settings' command."""

    # Represents remote device identification number.
    device_id: int

    # Represents settings type of the received result.
    settings_type: SettingsTypeCompound

    # Represents result of the received result.
    result: bool

    # Represents nonce of the received result.
    nonce: int

    def __init__(self, device_id: int, settings_type: SettingsTypeCompound, result: bool, nonce: int):
        self.device_id = device_id
        self.settings_type = settings_type
        self.result = result
        self.nonce = nonce
