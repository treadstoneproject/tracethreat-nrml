INCLUDE_DIRECTORIES(/usr/local/include/)

ADD_LIBRARY(exa_utils SHARED ${utils_source_files})

MESSAGE( STATUS "PROJECT_SOURCE_DIR : " ${PROJECT_SOURCE_DIR} )

LINK_DIRECTORIES(/usr/local/lib)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")

SET( Flags.hpp
     Flags.cpp
     TestUtils.cpp)

ADD_LIBRARY(ttnrml_utils SHARED ${utils_source_files})

TARGET_LINK_LIBRARIES(ttnrml_utils PRIVATE folly glog gtest rocksdb)



