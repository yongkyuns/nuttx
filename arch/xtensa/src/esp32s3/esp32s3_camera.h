/****************************************************************************
 * arch/xtensa/src/esp32s3/esp32s3_camera.h
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

#ifndef __ARCH_XTENSA_SRC_ESP32S3_ESP32S3_CAMERA_H
#define __ARCH_XTENSA_SRC_ESP32S3_ESP32S3_CAMERA_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <stdint.h>

#ifndef __ASSEMBLY__

#undef EXTERN
#if defined(__cplusplus)
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Camera pixel formats */

#define ESP32S3_CAM_PIXFMT_RGB565    0
#define ESP32S3_CAM_PIXFMT_YUV422    1
#define ESP32S3_CAM_PIXFMT_GRAYSCALE 2
#define ESP32S3_CAM_PIXFMT_JPEG      3

/* Frame sizes */

#define ESP32S3_CAM_FRAMESIZE_QQVGA  0   /* 160x120 */
#define ESP32S3_CAM_FRAMESIZE_QCIF   1   /* 176x144 */
#define ESP32S3_CAM_FRAMESIZE_HQVGA  2   /* 240x176 */
#define ESP32S3_CAM_FRAMESIZE_QVGA   3   /* 320x240 */
#define ESP32S3_CAM_FRAMESIZE_CIF    4   /* 400x296 */
#define ESP32S3_CAM_FRAMESIZE_HVGA   5   /* 480x320 */
#define ESP32S3_CAM_FRAMESIZE_VGA    6   /* 640x480 */
#define ESP32S3_CAM_FRAMESIZE_SVGA   7   /* 800x600 */
#define ESP32S3_CAM_FRAMESIZE_XGA    8   /* 1024x768 */
#define ESP32S3_CAM_FRAMESIZE_HD     9   /* 1280x720 */
#define ESP32S3_CAM_FRAMESIZE_SXGA   10  /* 1280x1024 */
#define ESP32S3_CAM_FRAMESIZE_UXGA   11  /* 1600x1200 */

/****************************************************************************
 * Public Types
 ****************************************************************************/

/* Camera pin configuration */

struct esp32s3_camera_pins_s
{
  int8_t pin_pwdn;      /* Power down pin (-1 if not used) */
  int8_t pin_reset;     /* Reset pin (-1 if not used) */
  int8_t pin_xclk;      /* XCLK output pin */
  int8_t pin_siod;      /* I2C SDA pin (or -1 to use I2C bus) */
  int8_t pin_sioc;      /* I2C SCL pin (or -1 to use I2C bus) */
  int8_t pin_d7;        /* Data bit 7 */
  int8_t pin_d6;        /* Data bit 6 */
  int8_t pin_d5;        /* Data bit 5 */
  int8_t pin_d4;        /* Data bit 4 */
  int8_t pin_d3;        /* Data bit 3 */
  int8_t pin_d2;        /* Data bit 2 */
  int8_t pin_d1;        /* Data bit 1 */
  int8_t pin_d0;        /* Data bit 0 */
  int8_t pin_vsync;     /* VSYNC pin */
  int8_t pin_href;      /* HREF pin */
  int8_t pin_pclk;      /* PCLK pin */
};

/* Camera configuration */

struct esp32s3_camera_config_s
{
  struct esp32s3_camera_pins_s pins;
  uint32_t xclk_freq_hz;   /* XCLK frequency in Hz (typically 20MHz) */
  uint8_t pixel_format;    /* One of ESP32S3_CAM_PIXFMT_* */
  uint8_t frame_size;      /* One of ESP32S3_CAM_FRAMESIZE_* */
  uint8_t jpeg_quality;    /* 0-63, lower is higher quality */
  uint8_t fb_count;        /* Number of frame buffers (1-2) */
  int i2c_bus;             /* I2C bus number for sensor (-1 for bitbang) */
};

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Name: esp32s3_camera_initialize
 *
 * Description:
 *   Initialize the ESP32-S3 camera driver and register /dev/video0.
 *
 * Input Parameters:
 *   config - Camera configuration
 *
 * Returned Value:
 *   Zero (OK) on success; a negated errno value on failure.
 *
 ****************************************************************************/

int esp32s3_camera_initialize(FAR const struct esp32s3_camera_config_s *config);

/****************************************************************************
 * Name: esp32s3_camera_uninitialize
 *
 * Description:
 *   Uninitialize the camera driver.
 *
 * Returned Value:
 *   Zero (OK) on success; a negated errno value on failure.
 *
 ****************************************************************************/

int esp32s3_camera_uninitialize(void);

#undef EXTERN
#ifdef __cplusplus
}
#endif

#endif /* __ASSEMBLY__ */
#endif /* __ARCH_XTENSA_SRC_ESP32S3_ESP32S3_CAMERA_H */
