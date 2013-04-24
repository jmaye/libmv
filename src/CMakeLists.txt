if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  remake_find_library(mvDeviceManager mvDeviceManager/Include/mvDeviceManager.h
    PATHS ${CMAKE_SOURCE_DIR}/lib/x86_64
    ${CMAKE_SOURCE_DIR}/src/lib)
else()
  remake_find_library(mvDeviceManager mvDeviceManager/Include/mvDeviceManager.h
    PATHS ${CMAKE_SOURCE_DIR}/lib/i386
    ${CMAKE_SOURCE_DIR}/src/lib)
endif()
remake_find_package(wxWidgets COMPONENTS base core xrc)
remake_find_package(FLTK)

remake_include(${wxWidgets_INCLUDE_DIRS})

foreach(wxWidgets_DEFINITION ${wxWidgets_DEFINITIONS})
  add_definitions(-D${wxWidgets_DEFINITION})
endforeach(wxWidgets_DEFINITION)

remake_project_header(config.h.remake)

remake_add_directories(lib)
remake_add_directories(bin COMPONENT tools)
