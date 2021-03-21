/*
 * Simple example 
 * 
 */
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "pcf8591.h"

#define CHECK_BIT(var,pos) (((var)>>(pos)) & 1)

int outlight(void)
{
  int file;
  int i;
  uint8_t buf[4] = {0};
  int buf1;
  
    file = PCF8591_open(PCF8591_INTERFACE_ADDR, PCF8591_DEFAULT_ADDR);
    for (i = 0; i < 4; i++) {
      // (Channel 3) 0x40 P6 Switch
      // (Channel 0) 0x41 P5 Light
      // (Channel 1) 0x42 P4 Hot
      // (Channel 2) 0x43 NULL
     writeandread (file, 0x40 + i, &(buf[i]), 1);
     delay (100);
    }
    buf1 = (int)buf[1];
    PCF8591_close(file);
  
  return buf1;
}


