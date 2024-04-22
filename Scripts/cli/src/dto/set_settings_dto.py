from enum import Enum


class SettingsTypeCompound(Enum):
    """Represents settings compound used to represent result settings type."""

    # Represents 'reset' setting type.
    RESET = 'Reset'

    # Represents 'set_gain' setting type with 'low' value.
    SET_GAIN_LOW = 'SetGainLow'

    # Represents 'set_gain' setting type with 'medium' value.
    SET_GAIN_MEDIUM = 'SetGainMedium'

    # Represents 'set_gain' setting type with 'high' value.
    SET_GAIN_HIGH = 'SetGainHigh'

    # Represents 'set_gain' setting type with 'max' value.
    SET_GAIN_MAX = 'SetGainMax'

    # Represents 'set_integral_time' setting type with 'first' value.
    SET_INTEGRAL_TIME_FIRST = 'SetIntegralTimeFirst'

    # Represents 'set_integral_time' setting type with 'second' value.
    SET_INTEGRAL_TIME_SECOND = 'SetIntegralTimeSecond'

    # Represents 'set_integral_time' setting type with 'third' value.
    SET_INTEGRAL_TIME_THIRD = 'SetIntegralTimeThird'

    # Represents 'set_integral_time' setting type with 'forth' value.
    SET_INTEGRAL_TIME_FORTH = 'SetIntegralTimeForth'

    # Represents 'set_integral_time' setting type with 'fifth' value.
    SET_INTEGRAL_TIME_FIFTH = 'SetIntegralTimeFifth'

    # Represents 'set_integral_time' setting type with 'sixth' value.
    SET_INTEGRAL_TIME_SIXTH = 'SetIntegralTimeSixth'


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
