AC_INIT([libtracethreat_nrml], 1, rchatsiri@treadstone.systems)
AC_PREREQ([2.59])
AM_INIT_AUTOMAKE([1.10 -Wall no-define])

# This is used to help configure check whether the source code is actually present, and
# that it isn't being run from some random directory.
AC_CONFIG_SRCDIR([src/bin/TraceThreatNRML.cpp])

# Put M4 macros in the m4/ subdirectory.
AC_CONFIG_MACRO_DIR([m4])

# We're using automake, but we want to turn off complaints about missing README files
# etc., so we need the "foreign" option.
AM_INIT_AUTOMAKE([foreign])


# We need a C compiler
AC_PROG_CXX([g++-4.8])


LIBS="-lgtest -lglog -lgflags -lfolly -lthrift -lmongoclient -lrocksdb"

LT_INIT([disable-static])

# Find the tools etc. needed by libtool
AC_PROG_LIBTOOL

AC_SUBST([TRACETHREAT_NRML_SO_VERSION], [0:1:0])
AC_SUBST([TRACETHREAT_NRML_API_VERSION], [0.0.1])
AC_SUBST([AM_CXXFLAGS])

# configure needs to generate three Makefiles.
AC_CONFIG_FILES([src/bin/Makefile])
AC_CONFIG_FILES([src/connector/Makefile])
AC_CONFIG_FILES([src/utils/Makefile])
AC_CONFIG_FILES([src/services/Makefile])
AC_CONFIG_FILES([src/msg/Makefile])
AC_CONFIG_FILES([Makefile])
#AC_CONFIG_FILES([src/nrml/Makefile])

AC_OUTPUT
