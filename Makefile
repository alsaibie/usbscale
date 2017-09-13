LDLIBS=-lm -lusb-1.0
CFLAGS=-Os -Wall
DOCCO=docco

usbscale: src/usbscale.cpp include/scales.h
	$(CC) $(CFLAGS) $< $(LDLIBS) -o $@

lsusb: src/lsusb.c include/scales.h

docs: src/usbscale.cpp
	$(DOCCO) usbscale.c

clean:
	rm -f lsscale
	rm -f usbscale
