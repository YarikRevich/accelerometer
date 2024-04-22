#include "sensor.h"
#include "custom.h"

typedef struct
{
    uint8_t lp_mode                    : 2;
    uint8_t mode                       : 2;
    uint8_t odr                        : 4;
} lis2dw12_ctrl1_t;

typedef struct
{
    uint8_t not_used_01                : 2;
    uint8_t low_noise                  : 1;
    uint8_t fds                        : 1;
    uint8_t fs                         : 2;
    uint8_t bw_filt                    : 2;
} lis2dw12_ctrl6_t;

void LIS2DW12::init() {
    // TODO: set power mode.
    enable();
//
//    set_gain(MEDIUM_AGAIN);
//    set_integral_time(ATIME_200MS);
//    write_byte(PERSIST_REGISTER, 0x01);
//
//    disable();
}

bool LIS2DW12::is_available() {
    return HAL_I2C_IsDeviceReady(&hi2c1, LIS2DW12_ADDRESS, 1u, 10u) == HAL_OK;
}

uint8_t LIS2DW12::get_device_id() {
    return read_byte(WHO_AM_I);
};

void LIS2DW12::enable() {
    lis2dw12_ctrl1_t ctrl1;

        ctrl1.mode = ((uint8_t) LIS2DW12_SINGLE_LOW_LOW_NOISE_PWR_12bit & 0x0CU) >> 2;
        ctrl1.lp_mode = (uint8_t) LIS2DW12_SINGLE_LOW_LOW_NOISE_PWR_12bit & 0x03U ;
        write_byte_i2c(LIS2DW12_CTRL1, (uint8_t *) &ctrl1);

    lis2dw12_ctrl6_t ctrl6;

        ctrl6.low_noise = ((uint8_t) LIS2DW12_SINGLE_LOW_LOW_NOISE_PWR_12bit & 0x10U) >> 4;
    write_byte_i2c(LIS2DW12_CTRL6, (uint8_t *) &ctrl6);

//    write_byte(ENABLE_REGISTER, ENABLE_AIEN | ENABLE_POWERON | ENABLE_AEN | ENABLE_NPIEN);
}
//
//void TSL2591X::disable() {
//    write_byte(ENABLE_REGISTER, ENABLE_POWEROFF);
//}
//
//void TSL2591X::reset() {
//    write_byte(CONTROL_REGISTER, SRESET);
//
//    init();
//}
//
void LIS2DW12::read_data() {
    int16_t val[6];

    uint8_t buff[6];

    HAL_I2C_Mem_Read(
            &hi2c1, LIS2DW12_ADDRESS + 1, LIS2DW12_OUT_X_L, I2C_MEMADD_SIZE_8BIT, buff, 6, I2C_TIMEOUT);

    val[0] = (int16_t)buff[1];
    val[0] = (val[0] * 256) + (int16_t)buff[0];
    val[1] = (int16_t)buff[3];
    val[1] = (val[1] * 256) + (int16_t)buff[2];
    val[2] = (int16_t)buff[5];
    val[2] = (val[2] * 256) + (int16_t)buff[4];

    char* text1[6];

    sprintf((char *)text1, "%d %d %d\n\r", (int)val[0], (int)val[1], (int)val[2]);

    HAL_UART_Transmit(&huart2, (const uint8_t*)text1, sizeof(text1), 25);
}
//
//uint16_t TSL2591X::read_full() {
//    uint16_t result;
//
//    enable();
//
//    uint8_t externalIntegralTime = get_integral_time();
//
//    for (uint8_t i = 0; i < externalIntegralTime + 2; i++) {
//        HAL_Delay(100);
//    }
//
//    result = (read_channel1() << 16) | read_channel0();
//
//    disable();
//
//    return result;
//}
//
//uint16_t TSL2591X::read_infrared() {
//    uint16_t result;
//
//    enable();
//
//    uint8_t externalIntegralTime = get_integral_time();
//
//    for (uint8_t i = 0; i < externalIntegralTime + 2; i++) {
//        HAL_Delay(100);
//    }
//
//    result = read_channel0();
//
//    disable();
//
//    return result;
//}
//
//uint16_t TSL2591X::read_visible() {
//    enable();
//
//    uint8_t externalIntegralTime = get_integral_time();
//
//    for (uint8_t i = 0; i < externalIntegralTime + 2; i++) {
//        HAL_Delay(100);
//    }
//
//    uint16_t channel1 = read_channel1();
//    uint16_t channel0 = read_channel0();
//
//    disable();
//
//    return ((channel1 << 16) | channel0) - channel1;
//}
//
//void TSL2591X::invoke_raw_interrupt_threshold(uint16_t low, uint16_t high) {
//    enable();
//
//    write_byte(AILTL_REGISTER, low & 0xFF);
//    write_byte(AILTH_REGISTER, low >> 8);
//
//    write_byte(AIHTL_REGISTER, high & 0xFF);
//    write_byte(AIHTH_REGISTER, high >> 8);
//
//    write_byte(NPAILTL_REGISTER, 0);
//    write_byte(NPAILTH_REGISTER, 0);
//
//    write_byte(NPAIHTL_REGISTER, 0xff);
//    write_byte(NPAIHTH_REGISTER, 0xff);
//
//    disable();
//}
//
//void TSL2591X::invoke_lux_interrupt(uint16_t low, uint16_t high) {
//    double gain = 1.0;
//
//    uint8_t externalGain = get_gain();
//
//    if (externalGain == MEDIUM_AGAIN) {
//        gain = 25.0;
//    } else if (externalGain == HIGH_AGAIN) {
//        gain = 428.0;
//    } else if (externalGain == MAX_AGAIN) {
//        gain = 9876.0;
//    }
//
//    uint8_t externalIntegralTime = get_integral_time();
//
//    double cpl = ((100 * externalIntegralTime + 100) * gain) / LUX_DF;
//
//    uint16_t channel1 = read_channel1();
//
//    uint16_t highLux = (int) (cpl * high) + 2 * channel1 - 1;
//    uint16_t lowLux = (int) (cpl * low) + 2 * channel1 + 1;
//
//    enable();
//
//    write_byte(AILTL_REGISTER, lowLux & 0xFF);
//    write_byte(AILTH_REGISTER, lowLux >> 8);
//
//    write_byte(AIHTL_REGISTER, highLux & 0xFF);
//    write_byte(AIHTH_REGISTER, highLux >> 8);
//
//    write_byte(NPAILTL_REGISTER, 0);
//    write_byte(NPAILTH_REGISTER, 0);
//
//    write_byte(NPAIHTL_REGISTER, 0xff);
//    write_byte(NPAIHTH_REGISTER, 0xff);
//
//    disable();
//}
//
//uint16_t TSL2591X::read_channel0() {
//    return read_word(CHAN0_LOW);
//}
//
//uint16_t TSL2591X::read_channel1() {
//    return read_word(CHAN1_LOW);
//}
//
//uint8_t TSL2591X::get_integral_time() {
//    return read_byte(CONTROL_REGISTER) & 0x07;
//}
//
//void TSL2591X::set_integral_time(uint8_t src) {
//    if (src < 0x06) {
//        uint8_t control = read_byte(CONTROL_REGISTER);
//        control &= 0xf8;
//        control |= src;
//        write_byte(CONTROL_REGISTER, control);
//    }
//}
//
//uint8_t TSL2591X::get_gain() {
//    return read_byte(CONTROL_REGISTER) & 0x30;
//}
//
//void TSL2591X::set_gain(uint8_t src) {
//    if (src == LOW_AGAIN || src == MEDIUM_AGAIN || src == HIGH_AGAIN || src == MAX_AGAIN) {
//        uint8_t control = read_byte(CONTROL_REGISTER);
//        control &= 0xCf;
//        control |= src;
//        write_byte(CONTROL_REGISTER, control);
//    }
//}
//
uint8_t LIS2DW12::read_byte(uint8_t src) {
    return read_byte_i2c(src);
}
//
//uint16_t TSL2591X::read_word(uint8_t src) {
//    return read_word_i2c(src | COMMAND_BIT);
//}
//
//void LIS2DW12::write_byte(uint8_t src, uint8_t value) {
//    write_byte_i2c(src, value);
//}

void LIS2DW12::write_byte_i2c(uint8_t command, uint8_t* buffer) {
//    uint8_t buffer[1] = {value};

    HAL_I2C_Mem_Write(
            &hi2c1, LIS2DW12_ADDRESS, command, I2C_MEMADD_SIZE_8BIT, buffer, 1, I2C_TIMEOUT);
}

//void LIS2DW12::read_bytes_i2c(uint8_t command, uint8_t* buffer, uint8_t size) {
////    HAL_I2C_Mem_Read(
////            &hi2c1, LIS2DW12_ADDRESS + 1, command, I2C_MEMADD_SIZE_8BIT, (uint8_t*)buffer, size, I2C_TIMEOUT);
//}

int LIS2DW12::read_byte_i2c(uint8_t command) {
    uint8_t buffer[1] = {0};

    HAL_I2C_Mem_Read(
            &hi2c1, LIS2DW12_ADDRESS + 1, command, I2C_MEMADD_SIZE_8BIT, buffer, 1, I2C_TIMEOUT);

    return buffer[0];
}

//int TSL2591X::read_word_i2c(uint8_t command) {
//    uint8_t buffer[2] = {0, 0};
//
//    HAL_I2C_Mem_Read(&hi2c1, TSL2591X_ADDRESS + 1, command, I2C_MEMADD_SIZE_8BIT, buffer, 2, I2C_TIMEOUT);
//
//    return ((buffer[1] << 8) | (buffer[0] & 0xff));
//}
//
