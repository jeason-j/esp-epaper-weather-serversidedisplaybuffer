const unsigned char PROGMEM message[24] ={ /* 0X01,0X01,0X0C,0X00,0X0C,0X00, */
0X00,0X00,0X1F,0X80,0X00,0X00,0X1F,0X80,0X3F,0XC0,0X7F,0XE0,0X00,0X00,0X10,0X80,
0X4F,0X20,0X20,0X40,0X1F,0X80,0X00,0X00,};

const unsigned char PROGMEM aqi_icon[24] ={ /* 0X01,0X01,0X0C,0X00,0X0C,0X00, */
0X1F,0X00,0X20,0XC0,0X6B,0XE0,0X60,0XE0,0XFF,0XF0,0XF1,0XF0,0XEE,0XF0,0XED,0XF0,
0X72,0XE0,0X7F,0XE0,0X20,0XC0,0X1F,0X00,};

const unsigned char PROGMEM night[24] = { /* 0X01,0X01,0X0C,0X00,0X0C,0X00, */
0X00,0X00,0X01,0X80,0X00,0XC0,0X00,0XC0,0X00,0XE0,0X01,0XE0,0X43,0XE0,0X7F,0XE0,
0X3F,0XC0,0X1F,0XC0,0X0F,0X00,0X00,0X00,};

const unsigned char PROGMEM city_icon[24] = { /* 0X01,0X01,0X0C,0X00,0X0C,0X00, */
0X00,0X00,0X1C,0X00,0X77,0X00,0X41,0X80,0X9C,0X60,0XA2,0X30,0XA2,0X30,0X9C,0XC0,
0X41,0X80,0X77,0X00,0X1C,0X00,0X00,0X00,};

const unsigned char PROGMEM batt_5[]  = { /* 0X01,0X01,0X14,0X00,0X10,0X00, */
0X1E,0X00,0XFF,0XC0,0X80,0X40,0XBF,0X40,0XBF,0X40,0X80,0X40,0XBF,0X40,0XBF,0X40,
0X80,0X40,0XBF,0X40,0XBF,0X40,0X80,0X40,0XBF,0X40,0XBF,0X40,0X80,0X40,0XBF,0X40,
0XBF,0X40,0X80,0X40,0XFF,0XC0,0X00,0X00,};
const unsigned char PROGMEM batt_4[] ={ /* 0X01,0X01,0X14,0X00,0X0A,0X00, */
0X1E,0X00,0XFF,0XC0,0X80,0X40,0X80,0X40,0X80,0X40,0X80,0X40,0XBF,0X40,0XBF,0X40,
0X80,0X40,0XBF,0X40,0XBF,0X40,0X80,0X40,0XBF,0X40,0XBF,0X40,0X80,0X40,0XBF,0X40,
0XBF,0X40,0X80,0X40,0XFF,0XC0,0X00,0X00,};
const unsigned char PROGMEM batt_3[] ={ /* 0X01,0X01,0X14,0X00,0X0A,0X00, */
0X1E,0X00,0XFF,0XC0,0X80,0X40,0X80,0X40,0X80,0X40,0X80,0X40,0X80,0X40,0X80,0X40,
0X80,0X40,0XBF,0X40,0XBF,0X40,0X80,0X40,0XBF,0X40,0XBF,0X40,0X80,0X40,0XBF,0X40,
0XBF,0X40,0X80,0X40,0XFF,0XC0,0X00,0X00,};
const unsigned char PROGMEM batt_2[] ={ /* 0X01,0X01,0X14,0X00,0X0A,0X00, */
0X1E,0X00,0XFF,0XC0,0X80,0X40,0X80,0X40,0X80,0X40,0X80,0X40,0X80,0X40,0X80,0X40,
0X80,0X40,0X80,0X40,0X80,0X40,0X80,0X40,0XBF,0X40,0XBF,0X40,0X80,0X40,0XBF,0X40,
0XBF,0X40,0X80,0X40,0XFF,0XC0,0X00,0X00,};
const unsigned char PROGMEM batt_1[] ={ /* 0X01,0X01,0X14,0X00,0X0A,0X00, */
0X1E,0X00,0XFF,0XC0,0X80,0X40,0X80,0X40,0X80,0X40,0X80,0X40,0X80,0X40,0X80,0X40,
0X80,0X40,0X80,0X40,0X80,0X40,0X80,0X40,0X80,0X40,0X80,0X40,0X80,0X40,0XBF,0X40,
0XBF,0X40,0X80,0X40,0XFF,0XC0,0X00,0X00,};
const unsigned char PROGMEM batt_0[]= { /* 0X01,0X01,0X14,0X00,0X0A,0X00, */
0X1E,0X00,0XFF,0XC0,0X80,0X40,0X80,0X40,0X80,0X40,0X80,0X40,0X80,0X40,0X80,0X40,
0X80,0X40,0XBD,0X40,0X80,0X40,0X80,0X40,0X80,0X40,0X80,0X40,0X80,0X40,0X80,0X40,
0X80,0X40,0X80,0X40,0XFF,0XC0,0X00,0X00,};
const unsigned char PROGMEM one[]={ /* 0X01,0X01,0X20,0X00,0X20,0X00, */
0X00,0X00,0X00,0X00,0X00,0X0F,0XE0,0X00,0X00,0X78,0X3C,0X00,0X01,0XC0,0X07,0X00,
0X03,0X00,0X01,0X80,0X06,0X00,0X00,0XC0,0X08,0X00,0X00,0X60,0X18,0X00,0X00,0X30,
0X10,0X00,0X00,0X10,0X20,0X00,0X00,0X08,0X20,0X00,0X00,0X08,0X40,0X00,0X00,0X04,
0X40,0X80,0X00,0X04,0X40,0X80,0X01,0X04,0X40,0X80,0X01,0X04,0X41,0XFF,0XFF,0X04,
0X41,0XFF,0XFF,0X04,0X40,0X00,0X01,0X04,0X40,0X00,0X01,0X04,0X40,0X00,0X00,0X04,
0X40,0X00,0X00,0X04,0X60,0X00,0X00,0X08,0X20,0X00,0X00,0X08,0X30,0X00,0X00,0X10,
0X10,0X00,0X00,0X10,0X08,0X00,0X00,0X20,0X04,0X00,0X00,0X40,0X03,0X00,0X01,0X80,
0X01,0X80,0X03,0X00,0X00,0X70,0X3C,0X00,0X00,0X0F,0XE0,0X00,0X00,0X00,0X00,0X00,
};
const unsigned char PROGMEM two[]= { /* 0X01,0X01,0X20,0X00,0X20,0X00, */
0X00,0X00,0X00,0X00,0X00,0X0F,0XE0,0X00,0X00,0X70,0X1C,0X00,0X01,0X80,0X03,0X00,
0X03,0X00,0X01,0X80,0X04,0X00,0X00,0X40,0X08,0X00,0X00,0X20,0X10,0X00,0X00,0X30,
0X30,0X00,0X00,0X10,0X20,0X30,0X03,0X08,0X20,0XF8,0X07,0X08,0X41,0X98,0X05,0X04,
0X41,0X00,0X09,0X04,0X41,0X00,0X11,0X04,0X43,0X00,0X31,0X04,0X42,0X00,0X61,0X04,
0X43,0X00,0XC1,0X04,0X41,0X01,0X81,0X04,0X41,0X83,0X01,0X04,0X40,0XFE,0X01,0X04,
0X40,0XFC,0X01,0X04,0X60,0X00,0X03,0X08,0X20,0X00,0X1F,0X08,0X30,0X00,0X00,0X10,
0X10,0X00,0X00,0X10,0X08,0X00,0X00,0X20,0X04,0X00,0X00,0XC0,0X03,0X00,0X01,0X80,
0X01,0XC0,0X07,0X00,0X00,0X78,0X3C,0X00,0X00,0X0F,0XC0,0X00,0X00,0X00,0X00,0X00,
};
const unsigned char PROGMEM three[]= { /* 0X01,0X01,0X20,0X00,0X20,0X00, */
0X00,0X00,0X00,0X00,0X00,0X0F,0XE0,0X00,0X00,0X70,0X1C,0X00,0X01,0X80,0X03,0X00,
0X03,0X00,0X01,0X80,0X04,0X00,0X00,0X40,0X08,0X00,0X00,0X20,0X10,0X00,0X00,0X30,
0X30,0X00,0X00,0X10,0X20,0X00,0X1C,0X08,0X20,0X70,0X3E,0X08,0X40,0XB0,0X12,0X04,
0X41,0X00,0X01,0X04,0X41,0X01,0X01,0X04,0X41,0X01,0X01,0X04,0X41,0X01,0X01,0X04,
0X41,0X01,0X01,0X04,0X41,0X03,0X01,0X04,0X41,0X83,0X01,0X04,0X41,0XEC,0X83,0X04,
0X40,0XFC,0XFE,0X04,0X60,0X78,0X7C,0X08,0X20,0X00,0X10,0X08,0X30,0X00,0X00,0X10,
0X10,0X00,0X00,0X10,0X08,0X00,0X00,0X20,0X04,0X00,0X00,0XC0,0X03,0X00,0X01,0X80,
0X01,0XC0,0X07,0X00,0X00,0X78,0X3C,0X00,0X00,0X0F,0XC0,0X00,0X00,0X00,0X00,0X00,
};

const unsigned char PROGMEM needcharge[700] = { /* 0X01,0X01,0X64,0X00,0X32,0X00, */
0X00,0X01,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X01,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X01,
0XFF,0XFF,0XE0,0X00,0X00,0X00,0X01,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X01,0XFF,0XFF,
0XE0,0X00,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XC0,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,
0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,
0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,
0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,
0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,
0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,
0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,
0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,
0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,
0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,
0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,
0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,
0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,
0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,
0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,
0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X3F,0XFF,0XFC,0X1F,
0X07,0XC0,0XF8,0X3F,0XFF,0XFC,0X1F,0X07,0XC0,0XF8,0X3F,0XFF,0XFC,0X1F,0X07,0XC0,
0XF8,0X3F,0XFF,0XFC,0X1F,0X07,0XC0,0XF8,0X3F,0XFF,0XFC,0X1F,0X07,0XC0,0XF8,0X00,
0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,
0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,
0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,
0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,
0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,
0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,
0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,
0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,
0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,
0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,
0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,
0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,
0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,
0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,
0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,
0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,
0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,0X00,0X00,0X00,0X00,0X07,0XC0,0XF8,
0X00,0X00,0X00,0X00,0X07,0XC0,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XC0,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XC0,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,};

const unsigned char PROGMEM phone[]= { /* 0X01,0X01,0X46,0X00,0X74,0X00, */
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X07,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0X1F,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X3C,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0XC0,0X70,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XE0,0X60,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X60,0XE0,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X70,0XC0,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X30,0XC0,0X3F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X30,0XC0,0X30,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X01,0X80,0X30,0XC0,0X30,0X02,0X00,0X80,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X01,0X8E,0X30,0XC0,0X33,0X02,0X01,0X20,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X01,0X88,0X30,0XC0,0X30,0XE2,0X02,0X40,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X01,0X8A,0X30,0XC0,0X30,0X1A,0X02,0X88,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,
0X8A,0X30,0XC0,0X30,0XE2,0X04,0X90,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X88,
0X30,0XC0,0X33,0X02,0X04,0X92,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X8E,0X30,
0XC0,0X30,0XE2,0X04,0X90,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X80,0X30,0XC0,
0X30,0X1A,0X02,0X88,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X80,0X30,0XC0,0X30,
0XE2,0X02,0X40,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X80,0X30,0XC0,0X33,0X02,
0X01,0X20,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X80,0X30,0XC0,0X30,0X02,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X80,0X30,0XC0,0X33,0XFA,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X80,0X30,0XC0,0X30,0X02,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X80,0X30,0XC0,0X30,0X02,0X18,0X0C,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X01,0X80,0X30,0XC0,0X33,0XFA,0X07,0X03,0X80,0X00,0X00,
0X00,0X00,0X00,0X00,0X01,0X80,0X30,0XC4,0X32,0X42,0X1E,0X0F,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X01,0X80,0X30,0XC4,0X32,0X42,0X07,0X03,0X80,0X00,0X00,0X00,0X00,
0X00,0X00,0X01,0X80,0X30,0XC4,0X32,0X42,0X18,0X0C,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X01,0X80,0X30,0XC4,0X30,0X02,0X0E,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X01,0X80,0X30,0XC4,0X30,0X02,0X15,0X08,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X01,
0X8C,0X30,0XC4,0X33,0XFA,0X15,0X2F,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X92,
0X30,0XC4,0X30,0X02,0X0D,0X00,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0XA1,0X30,
0XC4,0X30,0X02,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0XA1,0X30,0XC4,
0X30,0X02,0X0B,0X07,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0XA1,0X30,0XC4,0X30,
0X02,0X15,0X08,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0XA1,0X30,0XC4,0X30,0X02,
0X15,0X28,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0XA1,0X30,0XC4,0X30,0X02,0X1F,
0X3F,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0XA1,0X30,0XC4,0X30,0X02,0X01,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0XA1,0X30,0XC4,0X30,0X02,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X01,0XA1,0X30,0XC4,0X30,0X02,0X10,0X0F,0XC0,0X00,
0X00,0X00,0X00,0X00,0X00,0X01,0XA1,0X30,0XC4,0X30,0X02,0X7F,0X0D,0X40,0X00,0X00,
0X00,0X00,0X00,0X00,0X01,0X92,0X30,0XC4,0X30,0X02,0X11,0X0C,0XC0,0X00,0X00,0X00,
0X00,0X00,0X00,0X01,0X8C,0X30,0XC4,0X30,0X02,0X00,0X08,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X01,0X80,0X30,0XC4,0X30,0X02,0X41,0X07,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X01,0X80,0X30,0XC4,0X30,0X02,0X7F,0X0A,0X80,0X00,0X00,0X00,0X00,0X00,0X00,
0X01,0X80,0X30,0XC4,0X30,0X02,0X11,0X0A,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X01,
0X80,0X30,0XC0,0X30,0X02,0X1F,0X06,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X80,
0X30,0XC0,0X30,0X02,0X01,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X80,0X30,
0XC0,0X30,0X02,0X0E,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X80,0X30,0XC0,
0X30,0X02,0X15,0X08,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X80,0X30,0XC0,0X30,
0X02,0X15,0X3F,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X80,0X30,0XC0,0X30,0X02,
0X0D,0X08,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X80,0X30,0XC0,0X30,0X02,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X80,0X30,0XC0,0X30,0X02,0X11,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X89,0X30,0XC0,0X30,0X02,0X1F,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X9D,0X30,0XC0,0X30,0X02,0X11,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X01,0X89,0X30,0XC0,0X30,0X02,0X10,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X01,0X89,0X30,0XC0,0X30,0X02,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X01,0X8F,0X30,0XC0,0X30,0X02,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X01,0X80,0X30,0XC6,0X30,0X02,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X01,0X80,0X30,0XC0,0X30,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X01,0X80,0X30,0XC0,0X30,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,
0X80,0X30,0XC0,0X3F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,
0X30,0XC0,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X30,
0XE0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X70,0X60,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X60,0X70,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XE0,0X3C,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0XC0,0X1F,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X07,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,};
