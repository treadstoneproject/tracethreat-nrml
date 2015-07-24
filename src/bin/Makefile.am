AM_CXXFLAGS = -I$(top_srcdir)/src -std=c++11 @AM_CXXFLAGS@

bin_PROGRAMS = tracethreat_nrml

lib_LTLIBRARIES = libservices.la

tracethreat_nrml_SOURCES = TraceThreatNRML.cpp

tracethreat_nrml_LDADD = $(top_builddir)/src/services/libservices.la \
                         ../msg/libauthen_thrift.la \
                         -lgflags -lthrift 

libservices_la_SOURCES = $(top_builddir)/src/server/AuthenticationHandler.hpp

$(AM_LDFLAGS) 

