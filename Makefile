CC = gcc
CFLAGS = -std=c99 -Wall
SFLAGS = -fPIC -shared
CFG = config.h

filters:
	$(CC) $(SFLAGS) $(CFG) dsp_filters/src/filters.c dsp_filters/inc/filters.h -o test/lib/libfilters.so -I . -I dsp_filters/inc