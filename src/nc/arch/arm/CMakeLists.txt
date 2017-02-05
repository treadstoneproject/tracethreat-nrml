INCLUDE_DIRECTORIES(/usr/local/include/ ../../../ /home/rchatsiri/sdb2/workspacecpp/capstone/ .)


MESSAGE( STATUS "PROJECT_SOURCE_DIR : " ${PROJECT_SOURCE_DIR}/../../ )

set (CMAKE_CXX_FLAGS "-fPIC")

LINK_DIRECTORIES(/usr/local/lib)
LINK_DIRECTORIES(/usr/lib)
LINK_DIRECTORIES(/home/rchatsiri/sdb2/workspacecpp/capstone/build)
LINK_DIRECTORIES(../../../core/build)
LINK_DIRECTORIES(../../../common/build)

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")

#    ArmInstructionAnalyzer.cpp
#    ArmInstructionAnalyzer.h

set(SOURCES
    ArmArchitecture.cpp
    ArmArchitecture.h
    ArmDisassembler.cpp
    ArmDisassembler.h
    ArmInstruction.h
    ArmRegisters.cpp
    ArmRegisters.h
    CallingConventions.cpp
    CallingConventions.h
)

#add_library(ttnrml-nc-arch-arm ${SOURCES})
#target_link_libraries(ttnrml-nc-arch-arm ttnrml-nc-core ttnrml-nc-common capstone-static)

ADD_LIBRARY(ttnrml-nc-arch-arm SHARED ${SOURCES})

TARGET_LINK_LIBRARIES(ttnrml-nc-arch-arm ttnrml-nc-core ttnrml-nc-common capstone)

# vim:set et sts=4 sw=4 nospell:
