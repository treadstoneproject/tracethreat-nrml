#set(MOC_HEADERS
#    SignalLogger.h
#)
INCLUDE_DIRECTORIES(/usr/local/include/ ../../ .)


MESSAGE( STATUS "PROJECT_SOURCE_DIR : " ${PROJECT_SOURCE_DIR} )

set (CMAKE_CXX_FLAGS "-fPIC")

LINK_DIRECTORIES(/usr/local/lib /usr/lib)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")


#    LogToken.h
#    Logger.cpp
#    Logger.h
#    StreamLogger.cpp
#    StreamLogger.h
#    SignalLogger.cpp
#    SignalLogger.h
#    CancellationToken.cpp
#    CancellationToken.h

set(SOURCES
    BitTwiddling.h
    Branding.cpp
    Branding.h
    ByteOrder.h
    CheckedCast.h
    DisjointSet.h
    Escaping.cpp
    Escaping.h
    Exception.cpp
    Exception.h
    Foreach.h
    PrintCallback.h
    Printable.h
    Range.h
    RangeClass.h
    SizedValue.h
    StringToInt.cpp
    StringToInt.h
    Subclass.h
    Types.h
    Unreachable.h
    Unused.h
    Version.h
    ilist.h
    make_unique.h
    CancellationToken.cpp
    CancellationToken.h


)

# qt4_wrap_cpp(SOURCES ${MOC_HEADERS} OPTIONS -DQ_MOC_RUN)

# Find out current revision.
#include(GetGitRevisionDescription)
#get_git_head_revision(GIT_REFSPEC GIT_SHA1)
#git_describe(GIT_DESCRIPTION)

#if (GIT_DESCRIPTION)
#    set(NC_VERSION "${GIT_DESCRIPTION}")
#else()
#    string(SUBSTRING ${GIT_SHA1} 1 7 NC_VERSION)
#endif()

#set(NC_REPORT_BUGS_TO "https://github.com/yegord/snowman/issues" CACHE STRING "Address for reporting bugs.")
#set(NC_LICENSE_NAME "GNU General Public License, version 3 or any later version" CACHE STRING "License name.")
#set(NC_LICENSE_URL "https://github.com/yegord/snowman/blob/master/doc/licenses.asciidoc" CACHE STRING "License URL.")

#configure_file("${CMAKE_CURRENT_SOURCE_DIR}/Version.cpp.in" "${CMAKE_CURRENT_BINARY_DIR}/Version.cpp" @ONLY)
#list(APPEND SOURCES "${CMAKE_CURRENT_BINARY_DIR}/Version.cpp")

ADD_LIBRARY(ttnrml-nc-common SHARED ${SOURCES})

TARGET_LINK_LIBRARIES(ttnrml-nc-common folly)
#target_link_libraries(nc-common folly ${Boost_LIBRARIES}) 

# vim:set et sts=4 sw=4 nospell:
