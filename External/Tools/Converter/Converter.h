#ifndef LIGHT_DETECTOR_CONVERTER_H
#define LIGHT_DETECTOR_CONVERTER_H

#include <cstdint>

/**
 * Represents a set of available data converters.
 */
class Converter {
public:
    /**
     * Represents result of uint32 to uint8 conversion.
     */
    struct Uint32ToUint8Result {
        uint8_t data[3];
    };

    /**
     * Converts given uint32 value into uint8.
     *
     * @param value - given uint32 value.
     * @return result of conversion.
     */
    static Uint32ToUint8Result convertUint32ToUint8(uint32_t value);
};

#endif //LIGHT_DETECTOR_CONVERTER_H
