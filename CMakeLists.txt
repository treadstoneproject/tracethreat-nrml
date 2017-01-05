cmake_minimum_required(VERSION 3.0.2)
project(tracethreat-nrml)

add_subdirectory(src/utils)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/utils)
#add_library(exa_service SHARED src/service/ThreadWarFileUpload.hpp)

add_executable(tracethreat-nrml src/bin/TraceThreatNRML.cpp)
target_link_libraries(tracethreat-nrml ttnrml_utils)

install(TARGETS tracethreat-nrml DESTINATION src/bin)
