##########
#        #
# BOOOST #
#        #
##########

set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME     OFF)

find_package(Boost 1.57 REQUIRED system filesystem thread iostreams)

add_definitions(-DBOOST_DATE_TIME_NO_LIB)
add_definitions(-DBOOST_REGEX_NO_LIB)
add_definitions(-DBOOST_CHRONO_NO_LIB)

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
endif()

message(STATUS "INCLUDE DIRECTORIES : ${Boost_INCLUDE_DIRS}")

###########
#         #
# LIBRARY #
#         #
###########

set(SRC
  cstock.cpp
  citem.cpp
)

add_library(libcstock ${SRC})

target_link_libraries(libcstock ${Boost_SYSTEM_LIBRARIES} ${Boost_FILESYSTEM_LIBRARIES})
