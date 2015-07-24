SUBDIR =server nrml

ACLOCAL_AMFLAGS = -I m4

lib_LTLIBRARIES = libtracethreat_nrml-@TRACETHREATNRML_API_VERSION@.la

libtracethreat_nrml_@TRACETHREATNRML_API_VERSION@_la_SOURCES = src/server/TraceThreatNRML.cpp

libtracethreat_nrml_@TRACETHREATNRML_API_VERSION@_la_LDFLAGS = -version-info $(TRACETHREATDB_SO_VERSION)

tracethreatdb_includedir = $(includedir)/tracethreatdb-$(TRACETHREATNRML_API_VERSION)  

nobase_tracethreatdb_include_HEADERS = src/server/TraceThreatNRML.hpp


tracethreatdb_libincludedir = $(libdir)/tracethreat_nrml-$(TRACETHREATNRML_API_VERSION)/include

dist_noinst_SCRIPTS = autogen.sh




