#include "proto_codec.h"

RequestBuffer ProtoCodec::request_buffer = RequestBuffer();

ResponseBuffer ProtoCodec::response_buffer = ResponseBuffer(300);

accelerometer::RequestContainer ProtoCodec::request_container =
        accelerometer::RequestContainer();

RequestBuffer* ProtoCodec::get_request_buffer() {
    return &request_buffer;
}

ResponseBuffer* ProtoCodec::get_response_buffer() {
    return &response_buffer;
}

int ProtoCodec::decode_request_container() {
    request_container.clear();

    if (request_container.deserialize(request_buffer) == ::EmbeddedProto::Error::NO_ERRORS) {
        State::get_request_container_sequence()->add(request_container);

        request_buffer.clear();

        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}

int ProtoCodec::encode_response_container(const accelerometer::ResponseContainer& content) {
    if (content.serialize(response_buffer) == ::EmbeddedProto::Error::NO_ERRORS) {
        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
};