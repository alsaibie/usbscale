#include <stdio.h>
#include <sys/types.h>
#include <stdint.h>
#include <math.h>
#include <iostream>
//
// This program uses libusb-1.0 (not the older libusb-0.1) for USB
// functionality.
//
#include <libusb-1.0/libusb.h>
// To enable a bunch of extra debugging data, simply define `#define DEBUG`
// here and recompile.
//
     #define DEBUG

//
// **NSCALES** should be kept updated with the length of the list.
//
#define NSCALES 9

//
// What is the number of the weighing result to show, as the first result may be incorrect (from the previous weighing)
//
#define WEIGH_COUNT 2

#define WEIGH_REPORT_SIZE 0x06

class USBScale{
  public:
    USBScale();
    ~USBScale();
    int open_scale_device(void);
    double get_measurement(void);

  private:

    libusb_device **devs;
    int r; // holds return codes
    ssize_t cnt;
    libusb_device* dev;
    libusb_device_handle* handle;
    int weigh_count{WEIGH_COUNT-1};
    unsigned char data[WEIGH_REPORT_SIZE];
    int len;
    int scale_result{-1};
    //
    // **find_scale** takes a libusb device list and finds the first USB device
    // that matches a device listed in scales.h.
    //
    libusb_device* find_scale(libusb_device**);

    //
    // **print_scale_data** takes the 6-byte output from the scale and interprets
    // it, printing out the result to the screen. It also returns a 1 if the
    // program should read again (i.e. continue looping).
    //
    int print_scale_data(unsigned char*);

    //
    // take device and fetch bEndpointAddress for the first endpoint
    //
    uint8_t get_first_endpoint_address(libusb_device* dev);


    //
    // **UNITS** is an array of all the unit abbreviations as set forth by *HID
    // Point of Sale Usage Tables*, version 1.02, by the USB Implementers' Forum.
    // The list is laid out so that the unit code returned by the scale is the
    // index of its corresponding string.
    //
    const char* UNITS[13] = {
          "units",        // unknown unit
          "mg",           // milligram
          "g",            // gram
          "kg",           // kilogram
          "cd",           // carat
          "taels",        // lian
          "gr",           // grain
          "dwt",          // pennyweight
          "tonnes",       // metric tons
          "tons",         // avoir ton
          "ozt",          // troy ounce
          "oz",           // ounce
          "lbs"           // pound
    };

    uint16_t scales[NSCALES][2] = {\
    // Stamps.com Model 510 5LB Scale
          {0x1446, 0x6a73},
          // USPS (Elane) PS311 "XM Elane Elane UParcel 30lb"
          {0x7b7c, 0x0100},
          // Stamps.com Stainless Steel 5 lb. Digital Scale
          {0x2474, 0x0550},
          // Stamps.com Stainless Steel 35 lb. Digital Scale
          {0x2474, 0x3550},
          // Mettler Toledo
          {0x0eb8, 0xf000},
          // SANFORD Dymo 10 lb USB Postal Scale
          {0x6096, 0x0158},
          // Fairbanks Scales SCB-R9000
          {0x0b67, 0x555e},
          // Dymo-CoStar Corp. M25 Digital Postal Scale
          {0x0922, 0x8004},
          // DYMO 1772057 Digital Postal Scale
          {0x0922, 0x8003}
  };

};