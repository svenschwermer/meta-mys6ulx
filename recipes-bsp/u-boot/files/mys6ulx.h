/*
 * Copyright (C) 2016 Freescale Semiconductor, Inc.
 * Copyright (C) 2018 Sven Schwermer
 *
 * Configuration settings for the MYiR MYS-6ULX board.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */
#ifndef __MYS6ULX_CONFIG_H
#define __MYS6ULX_CONFIG_H

#include "mx6_common.h"

#ifdef CONFIG_MXC_UART
#define CONFIG_MXC_UART_BASE       UART1_BASE
#endif

#define CONFIG_SYS_LOAD_ADDR       CONFIG_LOADADDR

#define CONFIG_NR_DRAM_BANKS       1
#define CONFIG_SYS_MALLOC_LEN      (16 * SZ_1M)
#define PHYS_SDRAM                 MMDC0_ARB_BASE_ADDR
#define CONFIG_SYS_SDRAM_BASE      PHYS_SDRAM

#define CONFIG_SYS_INIT_RAM_ADDR   IRAM_BASE_ADDR
#define CONFIG_SYS_INIT_RAM_SIZE   IRAM_SIZE
#define CONFIG_SYS_INIT_SP_OFFSET  (CONFIG_SYS_INIT_RAM_SIZE - GENERATED_GBL_DATA_SIZE)
#define CONFIG_SYS_INIT_SP_ADDR    (CONFIG_SYS_INIT_RAM_ADDR + CONFIG_SYS_INIT_SP_OFFSET)

#define CONFIG_ENV_SIZE            SZ_8K

/* This should actually be handled using Kconfig */
#ifdef CONFIG_FEC_MXC
#define CONFIG_MII
#endif

#define CONFIG_IOMUX_LPSR

#endif

