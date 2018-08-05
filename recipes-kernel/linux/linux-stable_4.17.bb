inherit kernel
require recipes-kernel/linux/linux-yocto.inc

SRC_URI = " \
	git://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git;protocol=git;nocheckout=1;name=machine;branch=linux-4.17.y \
	file://defconfig \
	file://add-dts-to-makefile.patch \
"

LIC_FILES_CHKSUM = "file://COPYING;md5=bbea815ee2795b2f4230826c0c6b8814"

LINUX_VERSION ?= "4.17.12"
# LINUX_VERSION_EXTENSION_append = "-custom"

# tag: v4.17.12 506f6fba269679b77f5e7b71df07ef0bb3013a36
SRCREV_machine="506f6fba269679b77f5e7b71df07ef0bb3013a36"

PV = "${LINUX_VERSION}+git${SRCPV}"

COMPATIBLE_MACHINE = "^(mx6|mx7)$"

do_patch_append() {
	cp ${THISDIR}/${PN}/imx6ull-mys6ulx.dts ${S}/arch/arm/boot/dts
}
