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

#define CONFIG_EXTRA_ENV_SETTINGS \
	"script=boot.scr\0" \
	"image=zImage\0" \
	"console=ttymxc0\0" \
	"fdt_high=0xffffffff\0" \
	"initrd_high=0xffffffff\0" \
	"fdt_file=imx6ull-mys6ulx.dtb\0" \
	"fdt_addr=0x83000000\0" \
	"boot_fdt=try\0" \
	"ip_dyn=yes\0" \
	"mmcdev=0\0" \
	"mmcpart=1\0" \
	"mmcroot=/dev/mmcblk0p2 rootwait rw\0" \
	"mmcautodetect=yes\0" \
	"mmcargs=" \
		"setenv bootargs console=${console},${baudrate} root=${mmcroot}\0" \
	"loadbootscript=" \
		"fatload mmc ${mmcdev}:${mmcpart} ${loadaddr} ${script};\0" \
	"bootscript=" \
		"echo Running bootscript from mmc ...; " \
		"source\0" \
	"loadimage=" \
		"fatload mmc ${mmcdev}:${mmcpart} ${loadaddr} ${image}\0" \
	"loadfdt=" \
		"fatload mmc ${mmcdev}:${mmcpart} ${fdt_addr} ${fdt_file}\0" \
	"mmcboot=" \
		"echo Booting from mmc ...; " \
		"run mmcargs; " \
		"if test ${boot_fdt} = yes || test ${boot_fdt} = try; then " \
			"if run loadfdt; then " \
				"bootz ${loadaddr} - ${fdt_addr}; " \
			"else " \
				"if test ${boot_fdt} = try; then " \
					"bootz; " \
				"else " \
					"echo WARN: Cannot load the DT; " \
				"fi; " \
			"fi; " \
		"else " \
			"bootz; " \
		"fi;\0" \
	"netargs=" \
		"setenv bootargs console=${console},${baudrate} root=/dev/nfs " \
		"ip=dhcp nfsroot=${serverip}:${nfsroot},v3,tcp\0" \
	"netboot=" \
		"echo Booting from net ...; " \
		"run netargs; " \
		"if test ${ip_dyn} = yes; then " \
			"setenv get_cmd dhcp; " \
		"else " \
			"setenv get_cmd tftp; " \
		"fi; " \
		"${get_cmd} ${image}; " \
		"if test ${boot_fdt} = yes || test ${boot_fdt} = try; then " \
			"if ${get_cmd} ${fdt_addr} ${fdt_file}; then " \
				"bootz ${loadaddr} - ${fdt_addr}; " \
			"else " \
				"if test ${boot_fdt} = try; then " \
					"bootz; " \
				"else " \
					"echo WARN: Cannot load the DT; " \
				"fi; " \
			"fi; " \
		"else " \
			"bootz; " \
		"fi;\0" \
	"bootcmd=" \
		"mmc dev ${mmcdev};" \
		"mmc dev ${mmcdev}; " \
		"if mmc rescan; then " \
			"if run loadbootscript; then " \
				"run bootscript; " \
			"else " \
				"if run loadimage; then " \
					"run mmcboot; " \
				"else " \
					"run netboot; " \
				"fi; " \
			"fi; " \
		"else " \
			"run netboot; " \
		"fi;\0"

#endif
