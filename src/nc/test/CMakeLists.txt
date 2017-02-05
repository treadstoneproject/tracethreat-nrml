INCLUDE_DIRECTORIES(/usr/local/include/)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/../../)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/../)
INCLUDE_DIRECTORIES(.)
INCLUDE_DIRECTORIES(/home/rchatsiri/sdb2/workspacecpp/Qt5.8.0/5.8/gcc_64/include/)

MESSAGE( STATUS "PROJECT_SOURCE_DIR : " ${PROJECT_SOURCE_DIR}/)

LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/../arch/arm/build)
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/../common/build)
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/../input/elf/build)
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/../core/build)
LINK_DIRECTORIES(/usr/local/lib)
LINK_DIRECTORIES(/home/rchatsiri/sdb2/workspacecpp/Qt5.8.0/5.8/gcc_64/lib)
LINK_DIRECTORIES(/home/rchatsiri/workspacecpp-sdc1/gflags/build/lib)

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -fPIC -Wall -std=gnu++0x")

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
	gflags
	folly
        Qt5Core)

ADD_TEST(DriverELFTest DriverELFTest.elf)

