remake_project_set(RUNTIME_DESTINATION /opt/libmv
  CACHE PATH "Runtime destination")
remake_project_set(TEMP_DESTINATION /tmp
  CACHE PATH "Temp destination")

remake_add_configurations(*.sh.remake INSTALL /etc/profile.d)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  remake_add_configurations(libmv64.conf.remake INSTALL /etc/ld.so.conf.d)
else()
  remake_add_configurations(libmv32.conf.remake INSTALL /etc/ld.so.conf.d)
endif()
