from google.protobuf.internal import enum_type_wrapper as _enum_type_wrapper
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from typing import ClassVar as _ClassVar, Optional as _Optional, Union as _Union

DESCRIPTOR: _descriptor.FileDescriptor

class DataType(int, metaclass=_enum_type_wrapper.EnumTypeWrapper):
    __slots__ = ()
    DataNone: _ClassVar[DataType]
    Raw: _ClassVar[DataType]
    Full: _ClassVar[DataType]
    Infrared: _ClassVar[DataType]
    Visible: _ClassVar[DataType]
DataNone: DataType
Raw: DataType
Full: DataType
Infrared: DataType
Visible: DataType

class DataBusRequestContent(_message.Message):
    __slots__ = ("dataType",)
    DATATYPE_FIELD_NUMBER: _ClassVar[int]
    dataType: DataType
    def __init__(self, dataType: _Optional[_Union[DataType, str]] = ...) -> None: ...

class DataBusResponseContent(_message.Message):
    __slots__ = ("deviceId", "dataType", "value")
    DEVICEID_FIELD_NUMBER: _ClassVar[int]
    DATATYPE_FIELD_NUMBER: _ClassVar[int]
    VALUE_FIELD_NUMBER: _ClassVar[int]
    deviceId: int
    dataType: DataType
    value: int
    def __init__(self, deviceId: _Optional[int] = ..., dataType: _Optional[_Union[DataType, str]] = ..., value: _Optional[int] = ...) -> None: ...
