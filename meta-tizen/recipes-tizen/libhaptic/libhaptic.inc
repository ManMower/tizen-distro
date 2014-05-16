DESCRIPTION = "Haptic library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND += ""
PROVIDES = ""

#PROVIDES by libhaptic 


#PROVIDES by libhaptic-dev 


#PROVIDES by libhaptic-plugin-dev 


RDEPENDS = ""
#RDEPENDS of libhaptic-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "libhaptic"


DEPENDS = ""
#DEPENDS of libhaptic 
DEPENDS_append_class-native = " cmake-native"
DEPENDS_append_class-target = " cmake-native"
DEPENDS += "vconf"
DEPENDS += "dlog"
DEPENDS += "common"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 
 
}
do_patch_append() {
    bb.build.exec_func('do_prep', d)
}

do_configure() {
}

do_compile() {
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" ; export CFLAGS ; 
 CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
 FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
 LD_AS_NEEDED=1; export LD_AS_NEEDED ; 
 
 cp ${S}/packaging/libhaptic.manifest .
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export FFLAGS ; 
   cmake \
         -DCMAKE_VERBOSE_MAKEFILE=ON \
         -DCMAKE_INSTALL_PREFIX:PATH=${prefix} \
         -DCMAKE_INSTALL_LIBDIR:PATH=${prefix}/lib \
         -DINCLUDE_INSTALL_DIR:PATH=${prefix}/include \
         -DLIB_INSTALL_DIR:PATH=${prefix}/lib \
         -DSYSCONF_INSTALL_DIR:PATH=${sysconfdir} \
         -DSHARE_INSTALL_PREFIX:PATH=${prefix}/share \
         -DCMAKE_SKIP_RPATH:BOOL=ON \
         -DBUILD_SHARED_LIBS:BOOL=ON .
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 mkdir -p ${D}${prefix}/share/license
 
 
}

PACKAGES += " libhaptic-plugin-dev "

libhaptic_files = ""
libhaptic_files += "libhaptic.manifest"
libhaptic_files += "${prefix}/lib/libhaptic.so.*"
libhaptic_files += "${prefix}/share/license/haptic"

libhaptic-dev_files = ""
libhaptic-dev_files += "libhaptic.manifest"
libhaptic-dev_files += "${prefix}/include/haptic/haptic.h"
libhaptic-dev_files += "${prefix}/include/haptic/SLP_HAPTIC_PG.h"
libhaptic-dev_files += "${prefix}/lib/libhaptic.so"
libhaptic-dev_files += "${prefix}/lib/pkgconfig/haptic.pc"

libhaptic-plugin-dev_files = ""
libhaptic-plugin-dev_files += "libhaptic.manifest"
libhaptic-plugin-dev_files += "${prefix}/include/haptic/haptic_module.h"
libhaptic-plugin-dev_files += "${prefix}/include/haptic/haptic_plugin_intf.h"
libhaptic-plugin-dev_files += "${prefix}/lib/pkgconfig/haptic-plugin.pc"

FILES_${PN} = "${libhaptic_files}"
FILES_${PN}-dev = "${libhaptic-dev_files}"
FILES_${PN}-plugin-dev = "${libhaptic-plugin-dev_files}"

PKG_libhaptic= "libhaptic"
PKG_libhaptic-dev= "libhaptic-dev"
PKG_libhaptic-plugin-dev= "libhaptic-plugin-dev"

require libhaptic-extraconf.inc
