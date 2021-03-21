//#ifndef PCF8591D_H_
//#define PCF8591D_H_

#define PCF8591_INTERFACE_ADDR       1
#define PCF8591_DEFAULT_ADDR         0x48
#define PCF8591_READ_SERIALNO        0x3780
#define PCF8591_MEAS_HIGHREP_STRETCH 0x2C06 // Doesn't work on PI
#define PCF8591_MEAS_MEDREP_STRETCH  0x2C0D // Seems to work on PI but shouldn't
#define PCF8591_MEAS_LOWREP_STRETCH  0x2C10 // Seems to work on PI but shouldn't
#define PCF8591_MEAS_HIGHREP         0x2400 // Doesn't work on PI
#define PCF8591_MEAS_MEDREP          0x240B
#define PCF8591_MEAS_LOWREP          0x2416
#define PCF8591_READSTATUS           0xF32D
#define PCF8591_CLEARSTATUS          0x3041
#define PCF8591_SOFTRESET            0x30A2
#define PCF8591_HEATER_ENABLE        0x306D
#define PCF8591_HEATER_DISABLE       0x3066

#define SHT32_DEFAULT_READ         PCF8591_MEAS_MEDREP

// Tempoary measure to fix the first write fail
#define PCF8591D_FIX_INITIAL_FAIL 1

typedef enum
{
  PCF8591_OK = 0,
  PCF8591_CRC_CHECK_FAILED = 1,
  PCF8591_BAD = 2,
  PCF8591_READ_FAILED = 3, 
  PCF8591_WRITE_FAILED = 4
} pcf8591rtn;

int PCF8591_open(int i2c_address, uint8_t PCF8591_address);
int PCF8591_close(int file);

void delay (unsigned int howLong);
uint8_t crc8(const uint8_t *data, int len);

pcf8591rtn writeandread(int fd, uint16_t sndword, uint8_t *buffer, int readsize);
pcf8591rtn gettempandhumidity(int file, float *temp, float *hum);
pcf8591rtn getstatus(int file, uint16_t *rtnbuf);
//pcf8591rtn getserialnum(int file, uint8_t *buf);
pcf8591rtn getserialnum(int file, uint32_t *serialNo);
pcf8591rtn clearstatus(int file);
pcf8591rtn softreset(int file);
pcf8591rtn enableheater(int file);
pcf8591rtn disableheater(int file);

//#endif /* PCF8591D_H_ */
