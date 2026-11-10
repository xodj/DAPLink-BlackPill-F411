/**
 * @file    daplink_addr.h
 * @brief
 *
 * DAPLink Interface Firmware
 * Copyright (c) 2009-2016, ARM Limited, All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef DAPLINK_ADDR_H
#define DAPLINK_ADDR_H

/* Device sizes */
#define DAPLINK_ROM_START               0x08000000
#define DAPLINK_ROM_SIZE                0x00080000 // 512 KB Flash (STM32F411CE)

#define DAPLINK_RAM_START               0x20000000 // SRAM1 на STM32F411
#define DAPLINK_RAM_SIZE                0x00020000 // 128 KB RAM

/* Flash Programming Info */
#define DAPLINK_SECTOR_SIZE             0x00004000 // Макс. размер сектора (128 KB) для буфера
#define DAPLINK_MIN_WRITE_SIZE          0x00000400

/* ROM sizes */
#define DAPLINK_ROM_BL_START            0x08000000
#define DAPLINK_ROM_BL_SIZE             0x0000C000 // 48 KB (Сектора 0, 1, 2 по 16 KB)

#define DAPLINK_ROM_CONFIG_ADMIN_START  0x0800C000
#define DAPLINK_ROM_CONFIG_ADMIN_SIZE   0x00004000 // 16 KB (Сектор 3)

#define DAPLINK_ROM_IF_START            0x08010000
#define DAPLINK_ROM_IF_SIZE             0x00050000 // 320 KB (Сектор 4 [64KB] + Сектора 5, 6 [по 128KB])

#define DAPLINK_ROM_CONFIG_USER_START   0x08060000
#define DAPLINK_ROM_CONFIG_USER_SIZE    0x00020000 // 128 KB (Сектор 7)

/* RAM sizes */
#define DAPLINK_RAM_APP_START           DAPLINK_RAM_START
#define DAPLINK_RAM_APP_SIZE            (DAPLINK_RAM_SIZE - DAPLINK_MIN_WRITE_SIZE)

#define DAPLINK_RAM_SHARED_START        (DAPLINK_RAM_APP_START + DAPLINK_RAM_APP_SIZE)
#define DAPLINK_RAM_SHARED_SIZE         (DAPLINK_RAM_SIZE - DAPLINK_RAM_APP_SIZE)

/* Current build */
#if defined(DAPLINK_BL)
#define DAPLINK_ROM_APP_START            DAPLINK_ROM_BL_START
#define DAPLINK_ROM_APP_SIZE             DAPLINK_ROM_BL_SIZE
#define DAPLINK_ROM_UPDATE_START         DAPLINK_ROM_IF_START
#define DAPLINK_ROM_UPDATE_SIZE          DAPLINK_ROM_IF_SIZE
#elif defined(DAPLINK_IF)
#define DAPLINK_ROM_APP_START            DAPLINK_ROM_IF_START
#define DAPLINK_ROM_APP_SIZE             DAPLINK_ROM_IF_SIZE
#define DAPLINK_ROM_UPDATE_START         DAPLINK_ROM_BL_START
#define DAPLINK_ROM_UPDATE_SIZE          (DAPLINK_ROM_BL_SIZE + DAPLINK_ROM_CONFIG_ADMIN_SIZE)
#else
#error "Build must be either bootloader or interface"
#endif

#endif
