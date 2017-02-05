INCLUDE_DIRECTORIES(/usr/local/include/)
INCLUDE_DIRECTORIES(../../../ /home/rchatsiri/sdb2/workspacecpp/Qt5.8.0/5.8/gcc_64/include/ .)


MESSAGE( STATUS "PROJECT_SOURCE_DIR : " ${PROJECT_SOURCE_DIR}/../../ )

SET (CMAKE_CXX_FLAGS "-fPIC")

LINK_DIRECTORIES(/usr/local/lib)
LINK_DIRECTORIES(/usr/lib) 
LINK_DIRECTORIES(../../../common/build)
LINK_DIRECTORIES(/home/rchatsiri/sdb2/workspacecpp/Qt5.8.0/5.8/gcc_64/lib)

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")


SET(SOURCES
    ElfParser.cpp
    ElfParser.h
    elf32.h
    elf64.h
    elf_common.h
)

#add_library(nc-input-elf ${SOURCES})
#target_link_libraries(nc-input-elf nc-core nc-common ${Boost_LIBRARIES} ${QT_LIBRARIES})

ADD_LIBRARY(ttnrml-nc-input-elf SHARED ${SOURCES})

TARGET_LINK_LIBRARIES(ttnrml-nc-input-elf ttnrml-nc-common)



# vim:set et sts=4 sw=4 nospell:
