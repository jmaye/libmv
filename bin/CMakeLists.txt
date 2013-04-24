remake_project_set(RUNTIME_DESTINATION /opt/libmv
  CACHE PATH "Runtime destination")
remake_project_set(TEMP_DESTINATION /tmp
  CACHE PATH "Temp destination")

if(${CMAKE_SYSTEM_PROCESSOR} STREQUAL x86_64)
  remake_add_directories(Linux64_x64)
else()
  remake_add_directories(Linux32_i86)
endif()
