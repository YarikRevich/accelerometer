#ifndef LIGHT_DETECTOR_PROTO_CODEC_H
#define LIGHT_DETECTOR_PROTO_CODEC_H

#include "data.h"
#include "request.h"
#include "response.h"

#include "request_buffer.h"
#include "response_buffer.h"

#include "state.h"

/**
 * Represents codec used to decompose and composite request and response.
 */
class ProtoCodec {
public:
    /**
     * Retrieves common request buffer instance.
     *
     * @return common instance of request buffer.
     */
    static RequestBuffer* get_request_buffer();

    /**
     * Retrieves common response buffer instance.
     *
     * @return common instance of response buffer.
     */
    static ResponseBuffer* get_response_buffer();

    /**
     * Attempts to decode request container, looking for raw data from request buffer. If the decoding is
     * successful, then the result is pushed to the request container sequence.
     *
     * @return status of the decode operation.
     */
    static int decode_request_container();

    /**
     * Attempts to decode request container, looking for raw data from request buffer. If the decoding is
     * successful, then the result is pushed to the request container sequence.
     *
     * @param content - given response container.
     * @return status of the decode operation.
     */
    static int encode_response_container(const accelerometer::ResponseContainer& content);
private:
    /**
     * Represents common instance of request buffer.
     */
    static RequestBuffer request_buffer;

    /**
     * Represents common instance of response buffer.
     */
    static ResponseBuffer response_buffer;

    /**
     * Represents common request container instance.
     */
    static accelerometer::RequestContainer request_container;
};

#endif //LIGHT_DETECTOR_PROTO_CODEC_H
