AM_CXXFLAGS   = -I$(top_srcdir)/src/  -std=c++11 @AM_CXXFLAGS@

ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS}

lib_LTLIBRARIES = libutils.la

libutils_la_SOURCES = Flags.cpp 

include_HEADERS = Flags.hpp

check_PROGRAMS = test_utils

test_utils_SOURCES  = $(libutils_la_SOURCES) TestUtils.cpp
test_utils_CXXFLAGS = $(libutils_la_CXXFLAGS) -g -std=c++11
test_utils_LDADD    = libutils.la \
                       -lgtest -lrocksdb

TESTS = test_utils

