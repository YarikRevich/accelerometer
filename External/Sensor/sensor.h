#ifndef ACCELEROMETER_SENSOR_H
#define ACCELEROMETER_SENSOR_H

#include "stm32l4xx_hal.h"
#include <stdint.h>
#include <stdio.h>

#define LIS2DW12_ADDRESS       (0x32)

#define WHO_AM_I (0x0F)

#define LIS2DW12_CTRL1 0x20
#define LIS2DW12_CTRL6 0x25


#define LIS2DW12_SINGLE_LOW_LOW_NOISE_PWR_12bit 0x04
//#define LIS2DW12_SINGLE_LOW_LOW_NOISE_PWR_12bit 0x18

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
//
//    /**
//     * Resets light sensor to the default state, initializing device with default settings.
//     */
//    static void reset();
//
    /**
     * Reads raw data in general format.
     *
     * @return read raw data in general format.
     */
    static void read_data();

//
//    /**
//     * Sets raw interruption threshold.
//     *
//     * @param low - given low state.
//     * @param high - given high state.
//     */
//    static void invoke_raw_interrupt_threshold(uint16_t low, uint16_t high);
//
//    /**
//     * Sets LUX interruption configurations.
//     *
//     * @param low - given low state.
//     * @param high - given high state.
//     */
//    static void invoke_lux_interrupt(uint16_t low, uint16_t high);
//
//    /**
//     * Retrieves integral time option from the sensor.
//     *
//     * @return read value.
//     */
//    static uint8_t get_integral_time();
//
//    /**
//    * Sets integral time option to the sensor.
//    *
//    * @param src - given value to be set.
//    */
//    static void set_integral_time(uint8_t src);
//
//    /**
//    * Retrieves the value of gain option from the sensor.
//    *
//    * @return retrieved value.
//    */
//    static uint8_t get_gain();
//
//    /**
//     * Sets the value of gain option to the sensor.
//     *
//     * @param src - given value to be set.
//     */
//    static void set_gain(uint8_t src);
//
private:
    /**
     * Enables the sensor.
     */
    static void enable();
//
//    /**
//     * Disables the sensor.
//     */
//    static void disable();
//
//    /**
//    * Reads value from the zero channel.
//    *
//    * @return read value.
//    */
//    static uint16_t read_channel0();
//
//    /**
//     * Reads value from the first channel.
//     *
//     * @return read value.
//     */
//    static uint16_t read_channel1();
//
    /**
     * Reads combined command by bytes using I2C bone.
     *
     * @param src - given command to be read.
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
//    /**
//     * Writes combined command by bytes via I2C bone.
//     *
//     * @param command - given command to be written.
//     * @param value - given value to be written to the given command.
//     */
//    static void write_byte(uint8_t src, uint8_t value);

    /**
     * Writes raw byte via I2C bone.
     *
     * @param command - given command to be written.
     * @param value - given value to be written to the given command.
     */
    static void write_byte_i2c(uint8_t command, uint8_t* buffer);

//    static void read_bytes_i2c(uint8_t command, uint8_t* buffer, uint8_t size);

    /**
     * Reads raw byte via I2C bone.
     *
     * @param command - given command to be read.
     * @return read byte.
     */
    static int read_byte_i2c(uint8_t command);
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
