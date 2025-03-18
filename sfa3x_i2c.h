/*
 * THIS FILE IS AUTOMATICALLY GENERATED
 *
 * Generator:     sensirion-driver-generator 1.1.2
 * Product:       sfa3x
 * Model-Version: 1.1.0
 */
/*
 * Copyright (c) 2025, Sensirion AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of Sensirion AG nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef SFA3X_I2C_H
#define SFA3X_I2C_H

#ifdef __cplusplus
extern "C" {
#endif

#include "sensirion_config.h"
#define SFA3X_I2C_ADDR_5D 0x5d

typedef enum {
    SFA3X_START_CONTINUOUS_MEASUREMENT_CMD_ID = 0x6,
    SFA3X_STOP_MEASUREMENT_CMD_ID = 0x104,
    SFA3X_READ_MEASURED_VALUES_AS_INTEGERS_CMD_ID = 0x327,
    SFA3X_GET_DEVICE_MARKING_CMD_ID = 0xd060,
    SFA3X_DEVICE_RESET_CMD_ID = 0xd304,
} SFA3X_CMD_ID;

/**
 * @brief Initialize i2c address of driver
 *
 * @param[in] i2c_address Used i2c address
 *
 */
void sfa3x_init(uint8_t i2c_address);

/**
 * @brief sfa3x_signal_hcho
 *
 * @param[in] hcho_raw
 *
 * @return Measured formaldehyde concentration in ppb.
 */
float sfa3x_signal_hcho(int16_t hcho_raw);

/**
 * @brief sfa3x_signal_humidity
 *
 * @param[in] humidity_raw
 *
 * @return Measured humidity in %RH
 */
float sfa3x_signal_humidity(int16_t humidity_raw);

/**
 * @brief sfa3x_signal_temperature
 *
 * @param[in] temperature_raw
 *
 * @return Measured temperature in degrees Celsius
 */
float sfa3x_signal_temperature(int16_t temperature_raw);

/**
 * @brief Read measured values and apply scaling
 *
 * @param[out] hcho Formaldehyde concentration in ppb
 * @param[out] humidity Relative humidity in %RH
 * @param[out] temperature Temperature in degrees Celsius
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfa3x_read_measured_values(float* hcho, float* humidity,
                                   float* temperature);

/**
 * @brief Starts continuous measurement
 *
 * Starts the continuous measurement. After power-up, the sensor module is in
 * idle-mode. Before any measurement values can be read, the measurement mode
 * needs to be started using this command. Only available in idle mode, i.e.
 * when no measurement is running. If a measurement is already running, stop it
 * first with the stop_measurement command.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfa3x_start_continuous_measurement();

/**
 * @brief Stop continuous measurement
 *
 * Stops the continuous measurement and returns to idle mode. This command is
 * only available in measurement mode. Returns error 67 (hex 0x43) if no
 * measurement is running.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfa3x_stop_measurement();

/**
 * @brief Read measured values
 *
 * Reads the measured values from the module. The sensor will always return the
 * latest available measurement. If a read measured value command is issued
 * before a new measurement is available, the last available measurement will be
 * sent again in the reply. Before the first sensor reading is available after
 * starting the continuous measurement, the sensor returns an empty frame and
 * error code 32 (hex 0x20).
 *
 * @param[out] hcho Formaldehyde concentration in ppb with a scaling of 5.
 * @param[out] humidity Relative humidity in %RH with a scaling of 100.
 * @param[out] temperature Temperature in degrees Celsius with a scaling of 200.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfa3x_read_measured_values_as_integers(int16_t* hcho, int16_t* humidity,
                                               int16_t* temperature);

/**
 * @brief sfa3x_get_device_marking
 *
 * Read the device marking string from the device.
 *
 * @param[out] device_marking Null-terminated ASCII string containing the serial
 * number (same as barcode on sensor module). Up to 32 characters can be read
 * from the device.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfa3x_get_device_marking(int8_t* device_marking,
                                 uint16_t device_marking_size);

/**
 * @brief Soft reset
 *
 * After calling this command, the module is in the same state as after a
 * Power-Reset. The reset is executed after sending the MISO response frame.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfa3x_device_reset();

#ifdef __cplusplus
}
#endif
#endif  // SFA3X_I2C_H
