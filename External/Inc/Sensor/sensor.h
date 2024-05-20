#ifndef ACCELEROMETER_SENSOR_H
#define ACCELEROMETER_SENSOR_H

#include "stm32l4xx_hal.h"
#include <stdint.h>
#include <stdio.h>

#define LIS2DW12_ADDRESS       (0x32)

#define WHO_AM_I (0x0F)

#define LIS2DW12_CTRL1 0x20
#define LIS2DW12_CTRL3 0x22
#define LIS2DW12_CTRL6 0x25


#define LIS2DW12_HIGH_PERFORMANCE 0x04
#define LIS2DW12_XL_ODR_12Hz5 0x02

#define LIS2DW12_OUT_X_L (0x28)

#define I2C_TIMEOUT (0x20)

extern I2C_HandleTypeDef hi2c1;

/**
 * Represents driver implementation for LIS2DW12 accelerometer sensor.
 */
class LIS2DW12 {
public:
    /**
     * Initializes accelerometer sensor configuration.
     */
    static void init();

    /**
     * Checks if the device is available and thus can be configured.
     *
     * @return result of the check.
     */
    static bool is_available();

    /**
     * Retrieves device id of the sensor.
     *
     * @return read device id.
     */
    static uint8_t get_device_id();

    /**
     * Represents value definition for raw data type.
     */
    class RawDataTypeValue {
    public:
        /**
         * Sets X value compound.
         *
         * @param value given X value compound.
         */
        void set_x(int16_t value);

        /**
         * Sets Y value compound.
         *
         * @param value given Y value compound.
         */
        void set_y(int16_t value);

        /**
         * Sets Z value compound.
         *
         * @param value given Z value compound.
         */
        void set_z(int16_t value);

        /**
         * Retrieves X value compound.
         *
         * @return retrieved X value compound.
         */
        [[nodiscard]] int16_t get_x() const;

        /**
         * Retrieves Y value compound.
         *
         * @return retrieved Y value compound.
         */
        [[nodiscard]] int16_t get_y() const;

        /**
         * Retrieves Z value compound.
         *
         * @return retrieved Z value compound.
         */
        [[nodiscard]] int16_t get_z() const;
    private:
        /**
         * Represents X value compound.
         */
        int16_t x;

        /**
         * Represents Y value compound.
         */
        int16_t y;

        /**
         * Represents Z value compound.
         */
        int16_t z;
    };

    /**
     * Reads raw data type value.
     *
     * @return read raw data type value.
     */
    static RawDataTypeValue read_raw();
private:
    /**
     * Enables the sensor.
     */
    static void enable();

    /**
     * Reads single byte command using I2C bone.
     *
     * @param src - given command to be performed.
     * @return read value.
     */
    static uint8_t read_byte(uint8_t src);

//
//    /**
//     * Reads combined command by word using I2C bone.
//     *
//     * @param src - given command to be read.
//     * @return read value.
//     */
//    static uint16_t read_word(uint8_t src);
//
    /**
     * Writes combined command by bytes via I2C bone.
     *
     * @param command - given command to be written.
     * @param value - given value to be written to the given command.
     */
    static void write_byte(uint8_t src, uint8_t value);

    /**
     * Writes raw byte via I2C bone.
     *
     * @param command - given command to be written.
     * @param value - given value to be written to the given command.
     * @param size - given output buffer size.
     */
    static void write_byte_i2c(uint8_t command, uint8_t* buffer, uint16_t size);

    /**
     * Reads raw byte via I2C bone.
     *
     * @param command - given command to be read.
     * @param data - given output buffer.
     * @param size - given output buffer size.
     * @return read byte.
     */
    static void read_byte_i2c(uint8_t command, uint8_t* data, uint16_t size);
//
//    /**
//     * Reads raw word via I2C bone.
//     *
//     * @param command - given command to be read.
//     * @return read word.
//     */
//    static int read_word_i2c(uint8_t command);
};

#endif // ACCELEROMETER_SENSOR_H
