#ifndef LIGHT_DETECTOR_RESPONSE_BUFFER_H
#define LIGHT_DETECTOR_RESPONSE_BUFFER_H

#include "WriteBufferInterface.h"

#include <cstdio>
#include <cstring>
#include <cstdlib>

/**
 * Represents response buffer implementation for protocol buffers serialization.
 */
class ResponseBuffer : public EmbeddedProto::WriteBufferInterface {
public:
    ResponseBuffer(uint32_t size);

    ~ResponseBuffer() override = default;

    /**
     * Retrieves raw buffer used for direct data injection.
     *
     * @return raw buffer reference.
     */
    uint8_t *get_raw_buffer();

    /**
     * @see EmbeddedProto::WriteBufferInterface
     */
    void clear() override;

    /**
     * @see EmbeddedProto::WriteBufferInterface
     */
    [[nodiscard]] uint32_t get_size() const override;

//    /**
//     * @see EmbeddedProto::WriteBufferInterface
//     */
//    [[nodiscard]] uint8_t get_size_small() const;

    /**
     * @see EmbeddedProto::WriteBufferInterface
     */
    [[nodiscard]] uint32_t get_max_size() const override;

    /**
     * Sets buffer max size.
     *
     * @param value - given buffer max size.
     */
    void set_max_size(uint32_t value);

    /**
     * @see EmbeddedProto::WriteBufferInterface
     */
    [[nodiscard]] uint32_t get_available_size() const override;

    /**
     * @see EmbeddedProto::WriteBufferInterface
     */
    bool push(const uint8_t byte) override;

    /**
     * @see EmbeddedProto::WriteBufferInterface
     */
    bool push(const uint8_t *src, const uint32_t length) override;

private:
    /**
     * Represents amount of currently used bytes by buffer.
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

#endif //LIGHT_DETECTOR_RESPONSE_BUFFER_H
