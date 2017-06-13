dnl Process this file with autoconf to produce a configure script.

AC_INIT(cdtsim, 1.0.0)
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([1.11])
AM_SILENT_RULES([yes])
AM_MAINTAINER_MODE([enable])
AC_PROG_CC

dnl ***************************************************************************
dnl Check for Windows
dnl ***************************************************************************
AC_CANONICAL_HOST

case $host_os in
  *mingw*)
    platform_win32=yes
    native_win32=yes
    ;;
  pw32* | *cygwin*)
    platform_win32=yes
    native_win32=no
    ;;
  *)
    platform_win32=no
    native_win32=no
    ;;
esac
AM_CONDITIONAL(PLATFORM_WIN32, test x"$platform_win32" = "xyes")
AM_CONDITIONAL(NATIVE_WIN32, test x"$native_win32" = "xyes")

PKG_CHECK_MODULES(CDTSIM, [gtk+-3.0 >= 2.90.3 ])
AC_OUTPUT([Makefile src/Makefile rpm/Makefile])
