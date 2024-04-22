#ifndef LIGHT_DETECTOR_REQUEST_BUFFER_H
#define LIGHT_DETECTOR_REQUEST_BUFFER_H

#include "ReadBufferInterface.h"

#include <cstdio>

/**
 * Represents request buffer implementation for protocol buffers serialization.
 */
class RequestBuffer : public EmbeddedProto::ReadBufferInterface {
public:
    RequestBuffer();

    ~RequestBuffer() override = default;

    /**
     * Sets raw buffer used for direct data injection.
     *
     * @param src - given buffer to be set.
     */
    void set_raw_buffer(uint8_t* src);

    /**
     * Resets index value for buffer.
     */
    void clear();

    /**
     * @see EmbeddedProto::ReadBufferInterface
     */
    [[nodiscard]] uint32_t get_size() const override;

    /**
     * @see EmbeddedProto::ReadBufferInterface
     */
    [[nodiscard]] uint32_t get_max_size() const override;

    /**
     * Sets buffer max size.
     *
     * @param value - given buffer max size.
     */
    void set_max_size(uint32_t value);

    /**
     * @see EmbeddedProto::ReadBufferInterface
     */
    bool peek(uint8_t &byte) const override;

    /**
     * @see EmbeddedProto::ReadBufferInterface
     */
    bool advance() override;

    /**
     * @see EmbeddedProto::ReadBufferInterface
     */
    bool advance(const uint32_t N) override;

    /**
     * @see EmbeddedProto::ReadBufferInterface
     */
    bool pop(uint8_t &byte) override;

private:
    /**
     * Represents current buffer cursor position.
     */
    uint32_t index;

    /**
     * Represents max size of the buffer.
     */
    uint32_t size;

    /**
     * Represents current buffer data.
     */
    uint8_t *bytes;
};

#endif //LIGHT_DETECTOR_REQUEST_BUFFER_H
