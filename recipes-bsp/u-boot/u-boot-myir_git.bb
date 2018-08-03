# Copyright (C) 2013-2016 Freescale Semiconductor
# Copyright 2017 NXP
# Copyright (C) 2018 Sven Schwermer

DESCRIPTION = "i.MX U-Boot for MYiR boards"
require recipes-bsp/u-boot/u-boot.inc

PROVIDES += "u-boot"
DEPENDS_append = "dtc-native"

LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://Licenses/gpl-2.0.txt;md5=b234ee4d69f5fce4486a80fdaf4a4263"

FILESEXTRAPATHS_prepend := "${THISDIR}/files:"
SRCREV = "b87f4bf09f6a608bd913e1c671cc4ed26cd4c325"
SRC_URI = " \
	git://github.com/amarula/u-boot-amarula.git;protocol=https;branch=imx-clk \
	file://add-mys6ulx-board.patch \
	file://myir;subdir=${S}/board \
	file://mys6ulx.h;subdir=${S}/include/configs \
	file://mys6ulx_defconfig;subdir=${S}/configs \
	file://imx6ull-mys6ulx.dts;subdir=${S}/arch/arm/dts \
"

S = "${WORKDIR}/git"

PACKAGE_ARCH = "${MACHINE_ARCH}"
COMPATIBLE_MACHINE = "(mx6|mx7)"
