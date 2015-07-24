AM_CXXFLAGS   = -I$(top_srcdir)/src/  -std=c++11 @AM_CXXFLAGS@

ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS}

lib_LTLIBRARIES = libauthen_thrift.la

libauthen_thrift_la_SOURCES = gen-cpp/Authentication.cpp \
                              gen-cpp/authenication_types.cpp \
                              gen-cpp/authenication_constants.cpp


include_HEADERS = gen-cpp/Authentication.h \
                  gen-cpp/authenication_constants.h \
                  gen-cpp/authenication_types.h
