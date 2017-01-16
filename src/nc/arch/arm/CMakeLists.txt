INCLUDE_DIRECTORIES(/usr/local/include/ ${PROJECT_SOURCE_DIR}/../../)


MESSAGE( STATUS "PROJECT_SOURCE_DIR : " ${PROJECT_SOURCE_DIR}/../../ )

set (CMAKE_CXX_FLAGS "-fPIC")

LINK_DIRECTORIES(/usr/local/lib /usr/lib)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")

set(SOURCES
    ArmArchitecture.cpp
    ArmArchitecture.h
    ArmDisassembler.cpp
    ArmDisassembler.h
    ArmInstruction.h
    ArmInstructionAnalyzer.cpp
    ArmInstructionAnalyzer.h
    ArmRegisters.cpp
    ArmRegisters.h
    CallingConventions.cpp
    CallingConventions.h
)

add_library(nc-arch-arm ${SOURCES})
target_link_libraries(nc-arch-arm nc-core nc-common capstone-static)

# vim:set et sts=4 sw=4 nospell:
