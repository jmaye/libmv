cmake_minimum_required(VERSION 2.6)

include(ReMake)

remake_project(
  libmv
  VERSION 2.5.4
  RELEASE beta
  SUMMARY "Matrix Vision camera driver"
  AUTHOR "Jerome Maye"
  CONTACT "jerome.maye@mavt.ethz.ch"
  HOME "https://github.com/jmaye/libmv"
  LICENSE "GNU Lesser General Public License (LGPL)"
  PREFIX mv-
  INSTALL /usr/
)

remake_add_directories(
  bin lib xml
)

remake_doc(
  html
  latex
)

remake_pack_deb(
  DESCRIPTION "Main library"
)

remake_pack_deb(
  COMPONENT dev
  DESCRIPTION "Development headers"
  DEPENDS libmv
)

remake_pack_deb(
  COMPONENT tools
  DESCRIPTION "Tools"
  DEPENDS libmv libwxgtk2.8-0 libfltk[0-9.]*
)

remake_pack_deb(
  COMPONENT doc
  DESCRIPTION "Documentation"
  DEPENDS libmv
)

remake_distribute_deb(
  DISTRIBUTION lucid
  SECTION libs
  UPLOAD ppa:jmaye/ethz
  DEPENDS remake doxygen libfltk1.1-dev libwxgtk2.8-dev
  PASS CMAKE_BUILD_TYPE LIBMV_GIT_REVISION
)

remake_distribute_deb(
  DISTRIBUTION precise
  SECTION libs
  UPLOAD ppa:jmaye/ethz
  DEPENDS remake doxygen libfltk1.3-dev libwxgtk2.8-dev
  PASS CMAKE_BUILD_TYPE LIBMV_GIT_REVISION
)
