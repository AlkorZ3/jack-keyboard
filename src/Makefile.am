bin_PROGRAMS = jack-keyboard
jack_keyboard_SOURCES = jack-keyboard.c pianokeyboard.c pianokeyboard.h
jack_keyboard_LDADD = $(GTK_LIBS) $(GLIB_LIBS) $(GTHREAD_LIBS) $(X11_LIBS) $(JACK_LIBS) $(LASH_LIBS)
jack_keyboard_CFLAGS = $(GTK_CFLAGS) $(GLIB_CFLAGS) $(GTHREAD_CFLAGS) $(X11_CFLAGS) $(JACK_CFLAGS) $(LASH_CFLAGS) \
	-DG_LOG_DOMAIN=\"jack-keyboard\"

desktopdir = $(datadir)/applications
desktop_DATA = jack-keyboard.desktop
EXTRA_DIST = $(desktop_DATA)

