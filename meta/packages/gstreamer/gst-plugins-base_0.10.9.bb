require gst-plugins.inc
DEPENDS += "virtual/libx11 alsa-lib freetype gnome-vfs liboil libogg libvorbis"
RDEPENDS += "gnome-vfs-plugin-file gnome-vfs-plugin-http gnome-vfs-plugin-ftp \
             gnome-vfs-plugin-sftp"
PROVIDES_${PN} += "gst-plugins"
PR = "r3"

EXTRA_OECONF += "--disable-freetypetest --disable-pango --disable-theora"

