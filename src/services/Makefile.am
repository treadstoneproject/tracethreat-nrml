AM_CXXFLAGS   = -I$(top_srcdir)/src/  -std=c++11 @AM_CXXFLAGS@

ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS}

lib_LTLIBRARIES = libservices.la

libservices_la_SOURCES = AuthenticationHandler.cpp

include_HEADERS = AuthenticationHandler.hpp

#test
check_PROGRAMS = test_services

test_services_SOURCES  = $(libservices_la_SOURCES) test_services.cpp
test_services_CXXFLAGS = $(libservices_la_CXXFLAGS) -g -std=c++11
test_services_LDADD    = libservices.la \
                         ../utils/libutils.la \
                         -lgtest -lgflags -lthrift

TESTS = test_services

