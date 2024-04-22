#include "response_buffer.h"

ResponseBuffer::ResponseBuffer(uint32_t size) : index(0) {
    set_max_size(size);
}

uint8_t *ResponseBuffer::get_raw_buffer() {
    return this->bytes;
}

void ResponseBuffer::clear() {
    this->index = 0;
}

uint32_t ResponseBuffer::get_size() const {
    return this->index;
}

uint32_t ResponseBuffer::get_max_size() const {
    return this->size;
}

void ResponseBuffer::set_max_size(uint32_t value) {
    this->size = value;
    this->bytes = (uint8_t *) malloc(sizeof(uint8_t) * value);
}

uint32_t ResponseBuffer::get_available_size() const {
    return -this->index;
}

bool ResponseBuffer::push(const uint8_t byte) {
    bool result = this->size > this->index;
    if (result) {
        this->bytes[this->index] = byte;
        ++this->index;
    }
    return result;
}

bool ResponseBuffer::push(const uint8_t *src, const uint32_t length) {
    bool result = this->size >= (this->index + length);
    if (result) {
        memcpy(this->bytes + this->index, src, length);
        this->index += length;
    }
    return result;
}