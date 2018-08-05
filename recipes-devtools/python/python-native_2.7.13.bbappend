# Fix issue with GCC 8 on x86_64, see
# https://mail.python.org/pipermail/python-dev/2018-January/152011.html

FILESEXTRAPATHS_prepend := "${THISDIR}/files:"
SRC_URI += "file://fix-gc-alignment.patch"
