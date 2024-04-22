from google.protobuf.internal import enum_type_wrapper as _enum_type_wrapper
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from typing import ClassVar as _ClassVar, Optional as _Optional, Union as _Union

DESCRIPTOR: _descriptor.FileDescriptor

class InfoType(int, metaclass=_enum_type_wrapper.EnumTypeWrapper):
    __slots__ = ()
    InfoNone: _ClassVar[InfoType]
    Gain: _ClassVar[InfoType]
    IntegralTime: _ClassVar[InfoType]
    ProcessedRequests: _ClassVar[InfoType]
    DeviceAvailable: _ClassVar[InfoType]
InfoNone: InfoType
Gain: InfoType
IntegralTime: InfoType
ProcessedRequests: InfoType
DeviceAvailable: InfoType

class InfoBusRequestContent(_message.Message):
    __slots__ = ("infoType",)
    INFOTYPE_FIELD_NUMBER: _ClassVar[int]
    infoType: InfoType
    def __init__(self, infoType: _Optional[_Union[InfoType, str]] = ...) -> None: ...

class InfoBusResponseContent(_message.Message):
    __slots__ = ("deviceId", "infoType", "value", "nonce")
    DEVICEID_FIELD_NUMBER: _ClassVar[int]
    INFOTYPE_FIELD_NUMBER: _ClassVar[int]
    VALUE_FIELD_NUMBER: _ClassVar[int]
    NONCE_FIELD_NUMBER: _ClassVar[int]
    deviceId: int
    infoType: InfoType
    value: int
    nonce: int
    def __init__(self, deviceId: _Optional[int] = ..., infoType: _Optional[_Union[InfoType, str]] = ..., value: _Optional[int] = ..., nonce: _Optional[int] = ...) -> None: ...
