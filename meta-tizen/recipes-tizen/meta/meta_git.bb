require meta.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/common/meta;tag=b135c154bf0f82a07c2610bffe01fd705fed6c17;nobranch=1"

BBCLASSEXTEND += " native "

