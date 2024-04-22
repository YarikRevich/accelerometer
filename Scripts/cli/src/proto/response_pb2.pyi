from Content import data_pb2 as _data_pb2
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from typing import ClassVar as _ClassVar, Mapping as _Mapping, Optional as _Optional, Union as _Union

DESCRIPTOR: _descriptor.FileDescriptor

class ResponseContainer(_message.Message):
    __slots__ = ("dataBus",)
    DATABUS_FIELD_NUMBER: _ClassVar[int]
    dataBus: _data_pb2.DataBusResponseContent
    def __init__(self, dataBus: _Optional[_Union[_data_pb2.DataBusResponseContent, _Mapping]] = ...) -> None: ...
