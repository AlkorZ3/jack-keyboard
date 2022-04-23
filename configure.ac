#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.61)
AC_INIT([jack-keyboard], [2.8], [alkorz3@rx3.net])
AM_INIT_AUTOMAKE([-Wall foreign])
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdlib.h string.h sys/time.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_HEADER_TIME
AC_C_VOLATILE

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_STRTOD
AC_CHECK_FUNCS([gettimeofday memset strcasecmp strdup])

PKG_CHECK_MODULES(GTK, gtk+-2.0 >= 2.2)
AC_SUBST(GTK_CFLAGS)
AC_SUBST(GTK_LIBS)

PKG_CHECK_MODULES(GLIB, glib-2.0 >= 2.2)
AC_SUBST(GLIB_CFLAGS)
AC_SUBST(GLIB_LIBS)

PKG_CHECK_MODULES(GTHREAD, gthread-2.0 >= 2.2)
AC_SUBST(GTHREAD_CFLAGS)
AC_SUBST(GTHREAD_LIBS)

AC_ARG_WITH([x11],
	    [AS_HELP_STRING([--with-x11],
	    [support keyboard grabbing @<:@default=check@:>@])],
	    [],
	    [with_x11=check])

AS_IF([test "x$with_x11" != xno],
      [PKG_CHECK_MODULES(X11, x11, AC_DEFINE([HAVE_X11], [], [Defined if we have X11 support.]),
      [if test "x$with_x11" != xcheck; then
       AC_MSG_FAILURE([--with-x11 was given, but x11 was not found])
       fi
       ])])

AC_SUBST(X11_CFLAGS)
AC_SUBST(X11_LIBS)

PKG_CHECK_MODULES(JACK, jack >= 0.102.0)
AC_SUBST(JACK_CFLAGS)
AC_SUBST(JACK_LIBS)

PKG_CHECK_MODULES(JACK_MIDI_NEEDS_NFRAMES, jack < 0.105.00, AC_DEFINE(JACK_MIDI_NEEDS_NFRAMES, 1, [whether or not JACK routines need nframes parameter]), true)

AC_ARG_WITH([lash],
	    [AS_HELP_STRING([--with-lash],
	    [support LASH @<:@default=check@:>@])],
	    [],
	    [with_lash=check])

AS_IF([test "x$with_lash" != xno],
      [PKG_CHECK_MODULES(LASH, lash-1.0, AC_DEFINE([HAVE_LASH], [], [Defined if we have LASH support.]),
      [if test "x$with_lash" != xcheck; then
       AC_MSG_FAILURE([--with-lash was given, but LASH was not found])
       fi
       ])])

AC_SUBST(LASH_CFLAGS)
AC_SUBST(LASH_LIBS)

AC_CONFIG_FILES([Makefile src/Makefile man/Makefile pixmaps/Makefile])
AC_OUTPUT

