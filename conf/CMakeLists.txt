remake_project_set(RUNTIME_DESTINATION /opt/libmv
  CACHE PATH "Runtime destination")
remake_project_set(TEMP_DESTINATION /tmp
  CACHE PATH "Temp destination")

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  remake_add_configurations(libmv64.conf.remake INSTALL /etc/ld.so.conf.d)
  remake_add_configurations(libmv64.sh.remake INSTALL /etc/profile.d)
else()
  remake_add_configurations(libmv32.conf.remake INSTALL /etc/ld.so.conf.d)
  remake_add_configurations(libmv32.sh.remake INSTALL /etc/profile.d)
endif()
