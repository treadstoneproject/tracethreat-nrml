AM_CXXFLAGS   = -I$(top_srcdir)/src/  -std=c++11 @AM_CXXFLAGS@

ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS}

lib_LTLIBRARIES = libconnector.la

libconnector_la_SOURCES = RocksDBConnector.cpp 

include_HEADERS = RocksDBConnector.hpp

check_PROGRAMS = test_connector

test_connector_SOURCES  = $(libconnector_la_SOURCES) test_connector.cpp
test_connector_CXXFLAGS = $(libconnector_la_CXXFLAGS) -g -std=c++11
test_connector_LDADD    = libconnector.la \
                       -lgtest -lrocksdb

TESTS = test_connector

