FILESEXTRAPATHS_prepend := "${THISDIR}/linux-imx:"
SRC_URI += " \
	file://imx6ull-mys6ulx.dts;subdir=${S}/arch/arm/boot/dts \
	file://add-dts-to-makefile.patch \
	"
