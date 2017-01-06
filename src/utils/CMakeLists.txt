INCLUDE_DIRECTORIES(/usr/local/include/)


MESSAGE( STATUS "PROJECT_SOURCE_DIR : " ${PROJECT_SOURCE_DIR} )

LINK_DIRECTORIES(/usr/local/lib /usr/lib)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")

SET( utils_source_files
     Flags.hpp
     Flags.cpp )

ADD_LIBRARY(ttnrml_utils SHARED ${utils_source_files})

TARGET_LINK_LIBRARIES(ttnrml_utils PRIVATE folly glog gtest rocksdb)

ADD_EXECUTABLE(UtilsTest
               TestUtils.cpp)

TARGET_LINK_LIBRARIES(UtilsTest  gtest gtest_main glog gflags)

ADD_TEST(UtilsTest UtilsTest)

