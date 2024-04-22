/**
  ******************************************************************************
  * @file    iks01a3_conf.h
  * @author  MEMS Software Solutions Team
  * @brief   This file contains definitions for the MEMS components bus interfaces
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

#include "stm32l4xx_hal.h"
#include "custom_bus.h"
#include "custom_errno.h"

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __IKS01A3_CONF_H__
#define __IKS01A3_CONF_H__

#ifdef __cplusplus
extern "C" {
#endif

/* USER CODE BEGIN 1 */
#define USE_IKS01A3_ENV_SENSOR_HTS221_0                1U
#define USE_IKS01A3_ENV_SENSOR_LPS22HH_0               1U
#define USE_IKS01A3_ENV_SENSOR_STTS751_0               1U

#define USE_IKS01A3_MOTION_SENSOR_LSM6DSO_0            1U
#define USE_IKS01A3_MOTION_SENSOR_LIS2DW12_0           1U
#define USE_IKS01A3_MOTION_SENSOR_LIS2MDL_0            1U
/* USER CODE END 1 */

#define IKS01A3_I2C_Init BSP_I2C1_Init
#define IKS01A3_I2C_DeInit BSP_I2C1_DeInit
#define IKS01A3_I2C_ReadReg BSP_I2C1_ReadReg
#define IKS01A3_I2C_WriteReg BSP_I2C1_WriteReg
#define IKS01A3_GetTick BSP_GetTick
#define IKS01A3_Delay HAL_Delay

#define BUS_IKS01A3_INSTANCE BUS_I2C1_INSTANCE
#define BUS_IKS01A3_CLK_DISABLE() __HAL_RCC_I2C1_CLK_DISABLE()
#define BUS_IKS01A3_CLK_ENABLE() __HAL_RCC_I2C1_CLK_ENABLE()
#define BUS_IKS01A3_SCL_GPIO_PORT BUS_I2C1_SCL_GPIO_PORT
#define BUS_IKS01A3_SCL_GPIO_AF BUS_I2C1_SCL_GPIO_AF
#define BUS_IKS01A3_SCL_GPIO_CLK_ENABLE() BUS_I2C1_SCL_GPIO_CLK_ENABLE()
#define BUS_IKS01A3_SCL_GPIO_CLK_DISABLE() BUS_I2C1_SCL_GPIO_CLK_DISABLE()
#define BUS_IKS01A3_SCL_GPIO_PIN BUS_I2C1_SCL_GPIO_PIN
#define BUS_IKS01A3_SDA_GPIO_PIN BUS_I2C1_SDA_GPIO_PIN
#define BUS_IKS01A3_SDA_GPIO_CLK_DISABLE() BUS_I2C1_SDA_GPIO_CLK_DISABLE()
#define BUS_IKS01A3_SDA_GPIO_PORT BUS_I2C1_SDA_GPIO_PORT
#define BUS_IKS01A3_SDA_GPIO_AF BUS_I2C1_SDA_GPIO_AF
#define BUS_IKS01A3_SDA_GPIO_CLK_ENABLE() BUS_I2C1_SDA_GPIO_CLK_ENABLE()

#ifdef __cplusplus
}
#endif

#endif /* __IKS01A3_CONF_H__*/



//
//
///**
//  * @brief  Read component ID
//  * @param  pObj the device pObj
//  * @param  Id the WHO_AM_I value
//  * @retval 0 in case of success, an error code otherwise
//  */
//int32_t LIS2DW12_ReadID(LIS2DW12_Object_t *pObj, uint8_t *Id)
//{
//    if (lis2dw12_device_id_get(&(pObj->Ctx), Id) != LIS2DW12_OK)
//    {
//        return LIS2DW12_ERROR;
//    }
//
//    return LIS2DW12_OK;
//}


//lis2dw12_read_reg()


//int32_t LIS2DW12_ACC_GetAxes(LIS2DW12_Object_t *pObj, LIS2DW12_Axes_t *Acceleration)

/// SET POWER MODE TO LIS2DW12_SINGLE_LOW_LOW_NOISE_PWR_12bit


//int32_t lis2dw12_acceleration_raw_get(stmdev_ctx_t *ctx, int16_t *val)
//{
//    uint8_t buff[6];
//    int32_t ret;
//
//    ret = lis2dw12_read_reg(ctx, LIS2DW12_OUT_X_L, buff, 6);
//    val[0] = (int16_t)buff[1];
//    val[0] = (val[0] * 256) + (int16_t)buff[0];
//    val[1] = (int16_t)buff[3];
//    val[1] = (val[1] * 256) + (int16_t)buff[2];
//    val[2] = (int16_t)buff[5];
//    val[2] = (val[2] * 256) + (int16_t)buff[4];
//
//    return ret;
//}






//int32_t lis2dw12_power_mode_set(stmdev_ctx_t *ctx,
//                                lis2dw12_mode_t val)
//{
//    lis2dw12_ctrl1_t ctrl1;
//    lis2dw12_ctrl6_t ctrl6;
//    int32_t ret;
//
//    ret = lis2dw12_read_reg(ctx, LIS2DW12_CTRL1, (uint8_t *) &ctrl1, 1);
//
//    if (ret == 0)
//    {
//        ctrl1.mode = ((uint8_t) val & 0x0CU) >> 2;
//        ctrl1.lp_mode = (uint8_t) val & 0x03U ;
//        ret = lis2dw12_write_reg(ctx, LIS2DW12_CTRL1, (uint8_t *) &ctrl1, 1);
//    }
//
//    if (ret == 0)
//    {
//        ret = lis2dw12_read_reg(ctx, LIS2DW12_CTRL6, (uint8_t *) &ctrl6, 1);
//    }
//
//    if (ret == 0)
//    {
//        ctrl6.low_noise = ((uint8_t) val & 0x10U) >> 4;
//        ret = lis2dw12_write_reg(ctx, LIS2DW12_CTRL6, (uint8_t *) &ctrl6, 1);
//    }
//
//    return ret;
//}