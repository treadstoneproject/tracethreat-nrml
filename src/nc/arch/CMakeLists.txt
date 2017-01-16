INCLUDE_DIRECTORIES(/usr/local/include/ .)


MESSAGE( STATUS "PROJECT_SOURCE_DIR : " ${PROJECT_SOURCE_DIR} )

set (CMAKE_CXX_FLAGS "-fPIC")

LINK_DIRECTORIES(/usr/local/lib /usr/lib)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")



add_subdirectory(arm)
add_subdirectory(x86)

# vim:set et sts=4 sw=4 nospell:
