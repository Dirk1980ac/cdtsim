## Process this file with automake to produce Makefile.in

## Created by Anjuta



AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(CDTSIM_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = cdtsim

cdtsim_SOURCES = \
	main.c \
	cdtsim.h \
	cdtsim.c \
	callbacks.c \
	helpers.c \
	helpers.h	


cdtsim_LDFLAGS =

cdtsim_LDADD = $(CDTSIM_LIBS)


if PLATFORM_WIN32
cdtsim_LDFLAGS += -Wl,--export-all-symbols
else
cdtsim_LDFLAGS += -Wl,--export-dynamic
endif

if NATIVE_WIN32
cdtsim_LDFLAGS += -mwindows
endif


