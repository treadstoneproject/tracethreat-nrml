INCLUDE_DIRECTORIES(/usr/local/include/ ${PROJECT_SOURCE_DIR}/../../ .)


MESSAGE( STATUS "PROJECT_SOURCE_DIR : " ${PROJECT_SOURCE_DIR}/../../ )

set (CMAKE_CXX_FLAGS "-fPIC")

LINK_DIRECTORIES(/usr/local/lib /usr/lib)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")

set(MOC_HEADERS
    Context.h
)

#    MasterAnalyzer.cpp
#    MasterAnalyzer.h

set(SOURCES
    Context.cpp
    Driver.cpp
    Driver.h
    arch/Architecture.cpp
    arch/Architecture.h
    arch/ArchitectureRepository.cpp
    arch/ArchitectureRepository.h
    arch/CapstoneInstruction.h
    arch/Capstone.h
    arch/Disassembler.cpp
    arch/Disassembler.h
    arch/Instruction.cpp
    arch/Instruction.h
    arch/Instructions.cpp
    arch/Instructions.h
    arch/Register.h
    arch/Registers.h
    image/ByteSource.h
    image/Image.cpp
    image/Image.h
    image/Platform.h
    image/Platform.cpp
    image/Reader.cpp
    image/Reader.h
    image/Relocation.h
    image/Section.cpp
    image/Section.h
    image/Symbol.cpp
    image/Symbol.h
    input/ParseError.cpp
    input/ParseError.h
    input/Parser.cpp
    input/Parser.h
    input/ParserRepository.cpp
    input/ParserRepository.h
    input/Utils.h
    mangling/DefaultDemangler.cpp
    mangling/DefaultDemangler.h
    mangling/Demangler.h
    ${MOC_HEADERS}
)

#qt4_wrap_cpp(SOURCES ${MOC_HEADERS} OPTIONS -DQ_MOC_RUN)

ADD_LIBRARY(ttnrml-nc-core SHARED ${SOURCES})
#target_link_libraries(nc-core nc-common nc-arch-arm nc-arch-x86 nc-input-elf nc-input-mach-o nc-input-pe
#    ${Boost_LIBRARIES} ${QT_LIBRARIES} iberty undname)

# target_link_libraries(nc-core nc-common nc-arch-arm nc-arch-x86 nc-input-elf glog)

TARGET_LINK_LIBRARIES(ttnrml-nc-core ttnrml-nc-common ttnrml-nc-arch-arm ttnrml-nc-input-elf glog)


# vim:set et sts=4 sw=4 nospell:
