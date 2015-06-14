##############
#            #
# QT5WIDGETS #
#            #
##############

cmake_policy(SET CMP0020 NEW)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)

include_directories(${Qt5Widgets_INCLUDES})

add_definitions(${Qt5Widgets_DEFINITIONS})

set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

#############
#           #
# CSTOCKMGR #
#           #
#############

set(SRCS
  cstockmgr.cpp
  main_window.cpp
  )

qt5_wrap_ui(FORMS
  forms/main_window.ui
  )

include_directories(../libcstock)

add_executable(cstockmgr WIN32 ${SRCS} ${FORMS})

target_link_libraries(cstockmgr libcstock)
target_link_libraries(cstockmgr Qt5::Widgets)
