require tizen-platform-config.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/tizen-platform-config;tag=4367f56cdcd5dea828e2fa17a2b781e6395a9ee9;nobranch=1"

BBCLASSEXTEND += " native "

