INCLUDE_DIRECTORIES(/usr/local/include/ ../../../ .)


MESSAGE( STATUS "PROJECT_SOURCE_DIR : " ${PROJECT_SOURCE_DIR}/../../ )

set (CMAKE_CXX_FLAGS "-fPIC")

LINK_DIRECTORIES(/usr/local/lib /usr/lib)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")


set(SOURCES
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
