#include "sensor.h"

typedef struct {
    uint8_t lp_mode: 2;
    uint8_t mode: 2;
    uint8_t odr: 4;
} lis2dw12_ctrl1_t;

typedef struct {
    uint8_t slp_mode: 2;
    uint8_t not_used_01: 1;
    uint8_t h_lactive: 1;
    uint8_t lir: 1;
    uint8_t pp_od: 1;
    uint8_t st: 2;
} lis2dw12_ctrl3_t;

typedef struct {
    uint8_t not_used_01: 2;
    uint8_t low_noise: 1;
    uint8_t fds: 1;
    uint8_t fs: 2;
    uint8_t bw_filt: 2;
} lis2dw12_ctrl6_t;

void LIS2DW12::init() {
    enable();
}

bool LIS2DW12::is_available() {
    return HAL_I2C_IsDeviceReady(&hi2c1, LIS2DW12_ADDRESS, 1u, 10u) == HAL_OK;
}

uint8_t LIS2DW12::get_device_id() {
    return read_byte(WHO_AM_I);
};

void LIS2DW12::enable() {
    lis2dw12_ctrl1_t ctrl1;
    lis2dw12_ctrl3_t ctrl3;

    read_byte_i2c(LIS2DW12_CTRL1, (uint8_t *) &ctrl1, 1);

    ctrl1.odr = (uint8_t) LIS2DW12_XL_ODR_12Hz5;

    write_byte_i2c(LIS2DW12_CTRL1, (uint8_t *) &ctrl1, 1);

    read_byte_i2c(LIS2DW12_CTRL3, (uint8_t *) &ctrl3, 1);

    ctrl3.slp_mode = ((uint8_t) LIS2DW12_XL_ODR_12Hz5 & 0x30U) >> 4;
    write_byte_i2c(LIS2DW12_CTRL3, (uint8_t *) &ctrl3, 1);


    lis2dw12_ctrl1_t ctrll1;
    lis2dw12_ctrl6_t ctrl6;

    read_byte_i2c(LIS2DW12_CTRL1, (uint8_t *) &ctrll1, 1);

    ctrll1.mode = ((uint8_t) LIS2DW12_HIGH_PERFORMANCE & 0x0CU) >> 2;
    ctrll1.lp_mode = (uint8_t) LIS2DW12_HIGH_PERFORMANCE & 0x03U;
    write_byte_i2c(LIS2DW12_CTRL1, (uint8_t *) &ctrll1, 1);

    read_byte_i2c(LIS2DW12_CTRL6, (uint8_t *) &ctrl6, 1);

    ctrl6.low_noise = ((uint8_t) LIS2DW12_HIGH_PERFORMANCE & 0x10U) >> 4;
    write_byte_i2c(LIS2DW12_CTRL6, (uint8_t *) &ctrl6, 1);
}

void LIS2DW12::RawDataTypeValue::set_x(int16_t value) {
    this->x = value;
}

void LIS2DW12::RawDataTypeValue::set_y(int16_t value) {
    this->y = value;
}

void LIS2DW12::RawDataTypeValue::set_z(int16_t value) {
    this->z = value;
}

int16_t LIS2DW12::RawDataTypeValue::get_x() const {
    return x;
}

int16_t LIS2DW12::RawDataTypeValue::get_y() const {
    return y;
}

int16_t LIS2DW12::RawDataTypeValue::get_z() const {
    return z;
}

LIS2DW12::RawDataTypeValue LIS2DW12::read_raw() {
    RawDataTypeValue result{};

    uint8_t buff[6];
    read_byte_i2c(LIS2DW12_OUT_X_L, buff, 6);

    result.set_x((int16_t) (((int16_t) buff[1] * 256) + (int16_t) buff[0]));
    result.set_y((int16_t) (((int16_t) buff[3] * 256) + (int16_t) buff[2]));
    result.set_z((int16_t) (((int16_t) buff[5] * 256) + (int16_t) buff[4]));

    return result;
}

uint8_t LIS2DW12::read_byte(uint8_t src) {
    uint8_t buffer[1] = {0};

    read_byte_i2c(src, buffer, 1);

    return buffer[0];
}

void LIS2DW12::write_byte(uint8_t src, uint8_t value) {
    uint8_t buffer[1] = {value};

    write_byte_i2c(src, buffer, 1);
}

void LIS2DW12::write_byte_i2c(uint8_t command, uint8_t *buffer, uint16_t size) {
    HAL_I2C_Mem_Write(
            &hi2c1, LIS2DW12_ADDRESS, command, I2C_MEMADD_SIZE_8BIT, buffer, size, I2C_TIMEOUT);
}

void LIS2DW12::read_byte_i2c(uint8_t command, uint8_t *data, uint16_t size) {
    HAL_I2C_Mem_Read(
            &hi2c1, LIS2DW12_ADDRESS + 1, command, I2C_MEMADD_SIZE_8BIT, data, size, I2C_TIMEOUT);
}
