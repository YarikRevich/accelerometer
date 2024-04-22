#include "request_buffer.h"

RequestBuffer::RequestBuffer() : index(0), size(0), bytes{nullptr} {
}

void RequestBuffer::set_raw_buffer(uint8_t* src) {
    this->bytes = src;
};

void RequestBuffer::clear() {
    this->index = 0;
}

uint32_t RequestBuffer::get_size() const {
    return index;
}

uint32_t RequestBuffer::get_max_size() const {
    return size;
}

void RequestBuffer::set_max_size(uint32_t value) {
    this->size = value;
}

bool RequestBuffer::peek(uint8_t &byte) const {
    bool result = this->index < this->size;
    if (result) {
        byte = this->bytes[this->index];
    }

    return result;
}


bool RequestBuffer::advance() {
    const bool result = this->index < this->size;
    if (result) {
        ++this->index;
    }
    return result;
}

bool RequestBuffer::advance(const uint32_t src) {
    this->index += src;
    const bool result = this->index < this->size;
    if (result) {
        this->index = this->size;
    }

    return result;
}

bool RequestBuffer::pop(uint8_t &byte) {
    bool result = this->index < this->size;
    if (result) {
        byte = this->bytes[this->index];
        ++this->index;
    }

    return result;
}
