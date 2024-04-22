from google.protobuf.internal import enum_type_wrapper as _enum_type_wrapper
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from typing import ClassVar as _ClassVar, Optional as _Optional, Union as _Union

DESCRIPTOR: _descriptor.FileDescriptor

class SettingsType(int, metaclass=_enum_type_wrapper.EnumTypeWrapper):
    __slots__ = ()
    SettingsNone: _ClassVar[SettingsType]
    Reset: _ClassVar[SettingsType]
    SetGainLow: _ClassVar[SettingsType]
    SetGainMedium: _ClassVar[SettingsType]
    SetGainHigh: _ClassVar[SettingsType]
    SetGainMax: _ClassVar[SettingsType]
    SetIntegralTimeFirst: _ClassVar[SettingsType]
    SetIntegralTimeSecond: _ClassVar[SettingsType]
    SetIntegralTimeThird: _ClassVar[SettingsType]
    SetIntegralTimeForth: _ClassVar[SettingsType]
    SetIntegralTimeFifth: _ClassVar[SettingsType]
    SetIntegralTimeSixth: _ClassVar[SettingsType]
SettingsNone: SettingsType
Reset: SettingsType
SetGainLow: SettingsType
SetGainMedium: SettingsType
SetGainHigh: SettingsType
SetGainMax: SettingsType
SetIntegralTimeFirst: SettingsType
SetIntegralTimeSecond: SettingsType
SetIntegralTimeThird: SettingsType
SetIntegralTimeForth: SettingsType
SetIntegralTimeFifth: SettingsType
SetIntegralTimeSixth: SettingsType

class SettingsBusRequestContent(_message.Message):
    __slots__ = ("settingsType",)
    SETTINGSTYPE_FIELD_NUMBER: _ClassVar[int]
    settingsType: SettingsType
    def __init__(self, settingsType: _Optional[_Union[SettingsType, str]] = ...) -> None: ...

class SettingsBusResponseContent(_message.Message):
    __slots__ = ("deviceId", "settingsType", "result", "nonce")
    DEVICEID_FIELD_NUMBER: _ClassVar[int]
    SETTINGSTYPE_FIELD_NUMBER: _ClassVar[int]
    RESULT_FIELD_NUMBER: _ClassVar[int]
    NONCE_FIELD_NUMBER: _ClassVar[int]
    deviceId: int
    settingsType: SettingsType
    result: bool
    nonce: int
    def __init__(self, deviceId: _Optional[int] = ..., settingsType: _Optional[_Union[SettingsType, str]] = ..., result: bool = ..., nonce: _Optional[int] = ...) -> None: ...
