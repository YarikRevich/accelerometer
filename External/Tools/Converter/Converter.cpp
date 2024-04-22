#include "converter.h"

Converter::Uint32ToUint8Result Converter::convertUint32ToUint8(uint32_t value) {
    Uint32ToUint8Result result;

    result.data[0] = (uint8_t)(value >> 16 & 0xFF);
    result.data[1] = (uint8_t)(value >> 8 & 0xFF);
    result.data[2] = (uint8_t)(value & 0xFF);

    return result;
}