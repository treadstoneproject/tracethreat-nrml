INCLUDE_DIRECTORIES(/usr/local/include/)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/../../)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/../)
INCLUDE_DIRECTORIES(.)


MESSAGE( STATUS "PROJECT_SOURCE_DIR : " ${PROJECT_SOURCE_DIR}/)

LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/../arch/arm/build)
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/../common/build)
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/../input/elf/build)
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/../core/build)
LINK_DIRECTORIES(/usr/local/lib)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")

SET( nc_test_source_files
     ReadELFTest.hpp)


ADD_EXECUTABLE(DriverELFTest.elf
               ${nc_test_source_files}
               DriverELFTest.cpp)

TARGET_LINK_LIBRARIES(DriverELFTest.elf 
        ttnrml-nc-core
        ttnrml-nc-arch-arm
        ttnrml-nc-common
        ttnrml-nc-input-elf 
	boost_filesystem 
	boost_system 
	boost_iostreams 
	gtest 
	gtest_main 
	glog 
	gflags)

ADD_TEST(DriverELFTest DriverELFTest.elf)

