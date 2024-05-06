from google.protobuf.internal import enum_type_wrapper as _enum_type_wrapper
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from typing import ClassVar as _ClassVar, Mapping as _Mapping, Optional as _Optional, Union as _Union

DESCRIPTOR: _descriptor.FileDescriptor

class DataType(int, metaclass=_enum_type_wrapper.EnumTypeWrapper):
    __slots__ = ()
    DataNone: _ClassVar[DataType]
    Raw: _ClassVar[DataType]
DataNone: DataType
Raw: DataType

class RawDataTypeValue(_message.Message):
    __slots__ = ("x", "y", "z")
    X_FIELD_NUMBER: _ClassVar[int]
    Y_FIELD_NUMBER: _ClassVar[int]
    Z_FIELD_NUMBER: _ClassVar[int]
    x: int
    y: int
    z: int
    def __init__(self, x: _Optional[int] = ..., y: _Optional[int] = ..., z: _Optional[int] = ...) -> None: ...

class DataBusRequestContent(_message.Message):
    __slots__ = ("dataType",)
    DATATYPE_FIELD_NUMBER: _ClassVar[int]
    dataType: DataType
    def __init__(self, dataType: _Optional[_Union[DataType, str]] = ...) -> None: ...

class DataBusResponseContent(_message.Message):
    __slots__ = ("deviceId", "dataType", "nonce", "raw")
    DEVICEID_FIELD_NUMBER: _ClassVar[int]
    DATATYPE_FIELD_NUMBER: _ClassVar[int]
    NONCE_FIELD_NUMBER: _ClassVar[int]
    RAW_FIELD_NUMBER: _ClassVar[int]
    deviceId: int
    dataType: DataType
    nonce: int
    raw: RawDataTypeValue
    def __init__(self, deviceId: _Optional[int] = ..., dataType: _Optional[_Union[DataType, str]] = ..., nonce: _Optional[int] = ..., raw: _Optional[_Union[RawDataTypeValue, _Mapping]] = ...) -> None: ...
