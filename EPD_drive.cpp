#include "FS.h"
#include "EPD_drive.h"
#include "EPD_drive_gpio.h"


unsigned char UNICODEbuffer[200];

//////////////////////////////////////full screen update LUT////////////////////////////////////////////
const unsigned char lut_vcomDC[] ={
0x00	,0x08	,0x00	,0x00	,0x00	,0x02,	
0x60	,0x28	,0x28	,0x00	,0x00	,0x01,	
0x00	,0x14	,0x00	,0x00	,0x00	,0x01,	
0x00	,0x12	,0x12	,0x00	,0x00	,0x01,	
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,	
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,	
0x00	,0x00	,0x00	,0x00	,0x00	,0x00	
,0x00	,0x00,					};
const unsigned char lut_ww[] ={	
0x40	,0x08	,0x00	,0x00	,0x00	,0x02,	
0x90	,0x28	,0x28	,0x00	,0x00	,0x01,	
0x40	,0x14	,0x00	,0x00	,0x00	,0x01,	
0xA0	,0x12	,0x12	,0x00	,0x00	,0x01,	
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,	
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,	
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,	};
const unsigned char lut_bw[] ={	
0x40	,0x17	,0x00	,0x00	,0x00	,0x02	,
0x90	,0x0F	,0x0F	,0x00	,0x00	,0x03	,
0x40	,0x0A	,0x01	,0x00	,0x00	,0x01	,
0xA0	,0x0E	,0x0E	,0x00	,0x00	,0x02	,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00	,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00	,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00	,					};
const unsigned char lut_wb[] ={	
0x80	,0x08	,0x00	,0x00	,0x00	,0x02,	
0x90	,0x28	,0x28	,0x00	,0x00	,0x01,	
0x80	,0x14	,0x00	,0x00	,0x00	,0x01,	
0x50	,0x12	,0x12	,0x00	,0x00	,0x01,	
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,	
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,	
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,	};
const unsigned char lut_bb[] ={	
0x80	,0x08	,0x00	,0x00	,0x00	,0x02,	
0x90	,0x28	,0x28	,0x00	,0x00	,0x01,	
0x80	,0x14	,0x00	,0x00	,0x00	,0x01,	
0x50	,0x12	,0x12	,0x00	,0x00	,0x01,	
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,	
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,	
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,	};

//////////////////////////////////////partial screen update LUT////////////////////////////////////////////
const unsigned char lut_vcomDC1[] ={
0x00  ,0x19 ,0x01 ,0x00 ,0x00 ,0x01,
0x00  ,0x00 ,0x00 ,0x00 ,0x00 ,0x00,
0x00  ,0x00 ,0x00 ,0x00 ,0x00 ,0x00,
0x00  ,0x00 ,0x00 ,0x00 ,0x00 ,0x00,
0x00  ,0x00 ,0x00 ,0x00 ,0x00 ,0x00,
0x00  ,0x00 ,0x00 ,0x00 ,0x00 ,0x00,
0x00  ,0x00 ,0x00 ,0x00 ,0x00 ,0x00
  ,0x00 ,0x00,          };
const unsigned char lut_ww1[] ={
0x00  ,0x19 ,0x01 ,0x00 ,0x00 ,0x01,
0x00  ,0x00 ,0x00 ,0x00 ,0x00 ,0x00,
0x00  ,0x00 ,0x00 ,0x00 ,0x00 ,0x00,
0x00  ,0x00 ,0x00 ,0x00 ,0x00 ,0x00,
0x00  ,0x00 ,0x00 ,0x00 ,0x00 ,0x00,
0x00  ,0x00 ,0x00 ,0x00 ,0x00 ,0x00,
0x00  ,0x00 ,0x00 ,0x00 ,0x00 ,0x00,};
const unsigned char lut_bw1[] ={
0x80  ,0x19 ,0x01 ,0x00 ,0x00 ,0x01,  
0x00  ,0x00 ,0x00 ,0x00 ,0x00 ,0x00,  
0x00  ,0x00 ,0x00 ,0x00 ,0x00 ,0x00,  
0x00  ,0x00 ,0x00 ,0x00 ,0x00 ,0x00,  
0x00  ,0x00 ,0x00 ,0x00 ,0x00 ,0x00,  
0x00  ,0x00 ,0x00 ,0x00 ,0x00 ,0x00,  
0x00  ,0x00 ,0x00 ,0x00 ,0x00 ,0x00,  };
const unsigned char lut_wb1[] ={
0x40  ,0x19 ,0x01 ,0x00 ,0x00 ,0x01,  
0x00  ,0x00 ,0x00 ,0x00 ,0x00 ,0x00,  
0x00  ,0x00 ,0x00 ,0x00 ,0x00 ,0x00,  
0x00  ,0x00 ,0x00 ,0x00 ,0x00 ,0x00,  
0x00  ,0x00 ,0x00 ,0x00 ,0x00 ,0x00,  
0x00  ,0x00 ,0x00 ,0x00 ,0x00 ,0x00,  
0x00  ,0x00 ,0x00 ,0x00 ,0x00 ,0x00,  };
const unsigned char lut_bb1[] ={
0x00  ,0x19 ,0x01 ,0x00 ,0x00 ,0x01,  
0x00  ,0x00 ,0x00 ,0x00 ,0x00 ,0x00,  
0x00  ,0x00 ,0x00 ,0x00 ,0x00 ,0x00,  
0x00  ,0x00 ,0x00 ,0x00 ,0x00 ,0x00,  
0x00  ,0x00 ,0x00 ,0x00 ,0x00 ,0x00,  
0x00  ,0x00 ,0x00 ,0x00 ,0x00 ,0x00,  
0x00  ,0x00 ,0x00 ,0x00 ,0x00 ,0x00,  };

String fontname;


/***********************************************************************************************************************
			------------------------------------------------------------------------
			|\\\																///|
			|\\\						Drive layer					///|
			------------------------------------------------------------------------
***********************************************************************************************************************/
/*******************************************************************************
Constructor
*******************************************************************************/
 WaveShare_EPD::WaveShare_EPD(){
 
}
/*******************************************************************************
function：
			read busy
*******************************************************************************/
void WaveShare_EPD::SetFont(byte fontindex)
{
     FontIndex=fontindex;
     switch (fontindex)
     {
     case 0:
     fontname="/font16";fontwidth=16;fontheight=16;break;
     case 1:
     fontname="/font32";fontwidth=32;fontheight=32;break;
     case 2:
     fontname="/font10";fontwidth=10;fontheight=10;break;
     case 3:
     fontname="/font12";fontwidth=12;fontheight=12;break;
      case 4:
     fontname="/font56";fontwidth=56;fontheight=56;break;
     case 5:
     fontname="/font70";fontwidth=70;fontheight=70;break;
     case 11:
     fontname="/weathericon";fontwidth=32;fontheight=32;break;
     case 12:
     fontname="/weathericon80";fontwidth=80;fontheight=80;break;
      case 13:
     fontname="/weathericon32";fontwidth=32;fontheight=32;break;
     }
  }
 void WaveShare_EPD::DrawXline(int start,int end, byte x)
  {
    for(int i=start;i<=end;i++)
    {
      SetPixel(x,i);
      }
  }
   void WaveShare_EPD::DrawYline(byte start,byte end,  byte y)
  {
    for(int i=start;i<=end;i++)
    {
      SetPixel(i,y);
      }
  }
void WaveShare_EPD::DrawUTF(byte x,int16_t y,byte width,byte height,String code)
{
  char buffer[200];
  code.toCharArray(buffer,200);
  DrawUTF(x,y,width,height,(unsigned char *)buffer);
  }
void WaveShare_EPD::DrawUTF(byte x,int16_t y,byte width,byte height,unsigned char *code)
{
  int charcount;
  charcount=UTFtoUNICODE((unsigned char*)code);
  DrawUnicodeStr(x,y,width,height,charcount,(unsigned char *)UNICODEbuffer);
  
  }
int WaveShare_EPD::UTFtoUNICODE(unsigned char *code)
{ 
  int i=0;int charcount=0;
  while(code[i]!='\0')
  { 
    //////Serial.println("current codei");
      //////Serial.println(code[i],HEX);
      //  ////Serial.println(code[i]&0xf0,HEX);
    if(code[i]<=0x7f)  //ascii
    {
      
      UNICODEbuffer[charcount*2]=0x00;
      UNICODEbuffer[charcount*2+1]=code[i];
        // ////Serial.println("english or number");
      // ////Serial.println(UNICODEbuffer[charcount*2],HEX);
       //  ////Serial.println(UNICODEbuffer[charcount*2+1],HEX);
      i++;charcount++;
   
      }
    else if((code[i]&0xe0)==0xc0)
    {
    
      UNICODEbuffer[charcount*2+1]=(code[i]<<6)+(code[i+1]&0x3f);
      UNICODEbuffer[charcount*2]=(code[i]>>2)&0x07;
      i+=2;charcount++;
     // ////Serial.println("two bits utf-8");
      }
     else if((code[i]&0xf0)==0xe0)
    {
      
      UNICODEbuffer[charcount*2+1]=(code[i+1]<<6)+(code[i+2]&0x7f);
      UNICODEbuffer[charcount*2]=(code[i]<<4)+((code[i+1]>>2)&0x0f);
      
       //////Serial.println("three bits utf-8");
       // ////Serial.println(UNICODEbuffer[charcount*2],HEX);
        // ////Serial.println(UNICODEbuffer[charcount*2+1],HEX);
        i+=3;charcount++;
      }
     else
     {
      return 0;}
  }
  UNICODEbuffer[charcount*2]='\0';
  return charcount;
  }
void WaveShare_EPD::DrawUnicodeChar(byte x,int16_t y,byte width,byte height,unsigned char *code)
 { 
  SPIFFS.begin();
  int offset;
  int sizeofsinglechar;
  if (height%8==0) sizeofsinglechar=(height/8)*width;
  else sizeofsinglechar=(height/8+1)*width;
 offset=(code[0]*0x100+code[1])*sizeofsinglechar;
  // ////Serial.println("code[1]");
  // ////Serial.println(code[1]);
   // ////Serial.println("sizeofsinglechar");
  // ////Serial.println(sizeofsinglechar);
  File f=SPIFFS.open(fontname,"r");
  f.seek(offset,SeekSet);
  char zi[sizeofsinglechar];
  f.readBytes(zi,sizeofsinglechar);
 /*for(int i=0;i<32;i++)
  {
     
   ////Serial.println(zi[i],HEX);
    }*/
  // ////Serial.println("offset");
   //////Serial.println(offset);
   if (offset<0xff*sizeofsinglechar && FontIndex<10) 
   {drawXbm(x,y,width,height,(unsigned char *)zi); }
   else  {drawXbm(x,y,width,height,(unsigned char *)zi);}
  
SPIFFS.end();
}

void WaveShare_EPD::DrawUnicodeStr(byte x,int16_t y,byte width,byte height,byte strlength,unsigned char *code)
{
  CurrentCursor=0;
   byte sizeofsinglechar;
  if (height%8==0) sizeofsinglechar=(height/8)*width;
  else sizeofsinglechar=(height/8+1)*width;
  int ymove=0;
  int xmove=0;
  strlength*=2;
  int i=0;
  while(i<strlength)
  {
      int offset;
      offset=(code[i]*0x100+code[i+1])*sizeofsinglechar;
      if (offset<0xff*sizeofsinglechar) 
      {
      
      DrawUnicodeChar(x+xmove,y+ymove,width,height,(unsigned char *)code+i);
      ymove+=CurrentCursor+1;
     // if((y+ymove+width)>=yDot-1) {xmove+=height+1;ymove=0;CurrentCursor=0;}
    }
    else if(fontscale==2)
    {
      DrawUnicodeChar(x+xmove,y+ymove,width,height,(unsigned char *)code+i);
      ymove+=width*2;
     // if((y+ymove+width*2)>=yDot-1) {xmove+=height+1;ymove=0;CurrentCursor=0;}
      }
    else
    {
      DrawUnicodeChar(x+xmove,y+ymove,width,height,(unsigned char *)code+i);
      ymove+=width;
     // if((y+ymove+width)>=yDot-1) {xmove+=height+1;ymove=0;CurrentCursor=0;}
      }
    i++;i++;
    }
  
  }
void WaveShare_EPD::drawXbm(int16_t xMove, int16_t yMove, int16_t width, int16_t height,unsigned char *xbm) {
  int16_t heightInXbm = (height + 7) / 8;
  uint8_t data;
  for(int16_t x = 0; x < width; x++) {
    for(int16_t y = 0; y < height; y++ ) {
      if (y & 7) {
        data <<= 1; // Move a bit
      } else {  // Read new data every 8 bit
        data = xbm[(y / 8) + x * heightInXbm];
      }
      // if there is a bit draw it
      if (((data & 0x80)>>7)) {
       if(fontscale==1) {SetPixel(xMove + y, yMove + x);CurrentCursor=x;}
       if(fontscale==2) {SetPixel(xMove + y*2, yMove + x*2);SetPixel(xMove + y*2+1, yMove + x*2);SetPixel(xMove + y*2, yMove + x*2+1);SetPixel(xMove + y*2+1, yMove + x*2+1);}
      }
    }
  }
}

void WaveShare_EPD::DrawXbm_P(int16_t xMove, int16_t yMove, int16_t width, int16_t height,const unsigned char *xbm) {
 int16_t heightInXbm = (height + 7) / 8;
 uint8_t data;
 //unsigned char temp[heightInXbm*width];
 //memcpy_P(temp, xbm, heightInXbm*width);
  
  for(int16_t x = 0; x < width; x++) {
    for(int16_t y = 0; y < height; y++ ) {
      if (y & 7) {
        data <<= 1; // Move a bit
      } else {  // Read new data every 8 bit
        data = pgm_read_byte(xbm+(y / 8) + x * heightInXbm);
      }
      // if there is a bit draw it
      if (((data & 0x80)>>7)) {
       if(fontscale==1) {SetPixel(xMove + y, yMove + x);CurrentCursor=x;}
       if(fontscale==2) {SetPixel(xMove + y*2, yMove + x*2);SetPixel(xMove + y*2+1, yMove + x*2);SetPixel(xMove + y*2, yMove + x*2+1);SetPixel(xMove + y*2+1, yMove + x*2+1);}
      }
    }
  }
}
void WaveShare_EPD::SetPixel(char x, int y)
{ 
    if(x<xDot&&y<yDot)  EPDbuffer[x/8+y*xDot/8]&=~(0x80>>x%8) ;
   
 
  }
void WaveShare_EPD::clearbuffer()
{
  for(int i=0;i<(xDot*yDot/8);i++) EPDbuffer[i]=0xff;
  
  }
void WaveShare_EPD::clearshadows()
{
 //unsigned char c0[]={0x00};
 //unsigned char c1[]={0xff};
 //EPD_Dis_Part(0,xDot-1,0,yDot-1,(unsigned char *)c1,(unsigned char *)c0,0,0);
 //delay(1000);
 //EPD_Dis_Part(0,xDot-1,0,yDot-1,(unsigned char *)c0,(unsigned char *)c1,0,0);
 //delay(1000);
  }
unsigned char WaveShare_EPD::ReadBusy(void)
{
  unsigned long i=0;
  for(i=0;i<400;i++){
	
      if(isEPD_BUSY!=EPD_BUSY_LEVEL) {
				//Serial.println("not Busy \r\n");
      	return 1;
      }
      //Serial.println("Busy \r\n");
	    driver_delay_xms(10);
  }
  return 0;
}
/*******************************************************************************
function：
		write command
*******************************************************************************/
void WaveShare_EPD::EPD_WriteCMD(unsigned char command)
{        
  EPD_CS_0;	
	EPD_DC_0;		// command write
	SPI_Write(command);
	EPD_CS_1;
}
void WaveShare_EPD::EPD_WriteData (unsigned char data)
{
  EPD_CS_0; 
    //delay_us(10);
  EPD_DC_1;
  SPI_Write(data);
  //delay_us(10);
  EPD_CS_1;
}

void WaveShare_EPD::deepsleep(void)
{
 EPD_WriteCMD(0x50); 
 EPD_WriteData (0xf7);//border floating
 EPD_WriteCMD(0x02);//power off
 EPD_WriteCMD(0x07);//sleep
 EPD_WriteData(0xa5);
  //EPD_WriteCMD(0xff);
}

//上传波形

void WaveShare_EPD::LUT_Upload(void)
{
	unsigned int count;
	EPD_WriteCMD(0x20);
	for(count=0;count<44;count++)	     
		{EPD_WriteData(lut_vcomDC[count]);}

	EPD_WriteCMD(0x21);
	for(count=0;count<42;count++)	     
		{EPD_WriteData(lut_ww[count]);}   
	
	EPD_WriteCMD(0x22);
	for(count=0;count<42;count++)	     
		{EPD_WriteData(lut_bw[count]);} 

	EPD_WriteCMD(0x23);
	for(count=0;count<42;count++)	     
		{EPD_WriteData(lut_wb[count]);} 

	EPD_WriteCMD(0x24);
	for(count=0;count<42;count++)	     
		{EPD_WriteData(lut_bb[count]);} 
}

void WaveShare_EPD::LUT_Upload1(void)
{
  unsigned int count;
  EPD_WriteCMD(0x20);
  for(count=0;count<44;count++)      
    {EPD_WriteData(lut_vcomDC1[count]);}

  EPD_WriteCMD(0x21);
  for(count=0;count<42;count++)      
    {EPD_WriteData(lut_ww1[count]);}   
  
  EPD_WriteCMD(0x22);
  for(count=0;count<42;count++)      
    {EPD_WriteData(lut_bw1[count]);} 

  EPD_WriteCMD(0x23);
  for(count=0;count<42;count++)      
    {EPD_WriteData(lut_wb1[count]);} 

  EPD_WriteCMD(0x24);
  for(count=0;count<42;count++)      
    {EPD_WriteData(lut_bb1[count]);} 
}
/*******************************************************************************
function：
		The first byte is written with the command value
		Remove the command value, 
		the address after a shift, 
		the length of less than one byte	
*******************************************************************************/

/*******************************************************************************
Function: Write the display buffer
Parameters: 
		XSize x the direction of the direction of 128 points, adjusted to an 
		integer multiple of 8 times YSize y direction quantity Dispbuff displays 
		the data storage location. The data must be arranged in a correct manner
********************************************************************************/
void WaveShare_EPD::EPD_WriteDispRam(unsigned char XSize,unsigned int YSize,
							unsigned char *Dispbuff)
{
	int i = 0,j = 0;
	if(XSize%8 != 0){
		XSize = XSize+(8-XSize%8);
	}
	XSize = XSize/8;
	ReadBusy();	
	EPD_CS_0;	
	EPD_DC_0;		//command write   newdata
	SPI_Write(0x13);
	EPD_DC_1;		//data write
	for(i=0;i<YSize;i++){
		for(j=0;j<XSize;j++){
			SPI_Write(*Dispbuff);
			Dispbuff++;
		}
	}
 
 EPD_CS_0;
 EPD_DC_0;   //command write   olddata
  SPI_Write(0x10);
  EPD_DC_1;   //data write
  for(int i=0;i<4736;i++)
  {
    EPD_WriteData (0x00); 
  }
  
	EPD_CS_1;
}

/*******************************************************************************
Function: Write the display buffer to write a certain area to the same display.
Parameters: XSize x the direction of the direction of 128 points,adjusted to 
			an integer multiple of 8 times YSize y direction quantity  Dispdata 
			display data.
********************************************************************************/
void WaveShare_EPD::EPD_WriteDispRamMono(unsigned char XSize,unsigned int YSize,
							unsigned char dispdata)
{
	int i = 0,j = 0;
	if(XSize%8 != 0){
		XSize = XSize+(8-XSize%8);
	}
	XSize = XSize/8;
	
	ReadBusy();	    
	EPD_CS_0;
	EPD_DC_0;		// command write
	SPI_Write(0x13);
	EPD_DC_1;		// data write
	for(i=0;i<YSize;i++){
		for(j=0;j<XSize;j++){
		 SPI_Write(dispdata);
		}
	}
 
	EPD_CS_0;
  EPD_DC_0;   //command write   olddata
  SPI_Write(0x10);
  EPD_DC_1;   //data write
  for(int i=0;i<4736;i++)
  {
    EPD_WriteData (0x00); 
  }
  
  EPD_CS_1;
}





//=========================functions============================
/*******************************************************************************
Initialize the register
********************************************************************************/
void WaveShare_EPD::EPD_Init(void)
{
	//1.reset driver
	EPD_RST_0;		// Module reset
	driver_delay_xms(100);
	EPD_RST_1;
	driver_delay_xms(100);
	
	//2. set register
	//Serial.println("***********set register Start**********");
 EPD_WriteCMD(0x01);     
 EPD_WriteData (0x03);
 EPD_WriteData (0x00);
 EPD_WriteData (0x26);//default26 max2b
 EPD_WriteData (0x26);//default26 max2b
 EPD_WriteData (0x03);
 
 EPD_WriteCMD(0x06);
 EPD_WriteData (0x17);
 EPD_WriteData (0x17);
 
 EPD_WriteCMD(0x04);
 ReadBusy(); 
 
 EPD_WriteCMD(0x00); 
 EPD_WriteData (0xb7);
  
 EPD_WriteCMD(0x30);  //PLL
 EPD_WriteData (0x3a);
 
 EPD_WriteCMD(0x61); //resolution
 EPD_WriteData (0x80);
 EPD_WriteData (0x01);
 EPD_WriteData (0x28);
 
 EPD_WriteCMD(0X82);
 EPD_WriteData (0x20);
 
 EPD_WriteCMD(0X50);
 EPD_WriteData (0x97);
  
 


  
	//Serial.println("***********set register  end**********");
}

/********************************************************************************
Display data updates
********************************************************************************/
void WaveShare_EPD::EPD_Update(void)
{
//三色屏幕没用到第三色，此处第三色刷为全空以供显示黑白
 	driver_delay_xms(200);
	LUT_Upload();
	EPD_WriteCMD(0x12);
}

/*******************************************************************************
write the waveform to the dirver's ram
********************************************************************************/

/*******************************************************************************
Full screen initialization
********************************************************************************/
void WaveShare_EPD::EPD_init_Full(void)
{		
	EPD_Init();			// Reset and set register 
  //driver_delay_xms(100000); 		
}


/********************************************************************************
parameter:
	Label  :
       		=1 Displays the contents of the DisBuffer
	   		=0 Displays the contents of the first byte in DisBuffer,
********************************************************************************/
void WaveShare_EPD::EPD_Dis_Full(unsigned char *DisBuffer,unsigned char Label)
{
   
	if(Label == 0){
		EPD_WriteDispRamMono(xDot, yDot, 0xff);	// white	
	}else{
		EPD_WriteDispRam(xDot, yDot, (unsigned char *)DisBuffer);	// white
	}	
	EPD_Update();	
	  
}
void WaveShare_EPD::EPD_Dis_Part(unsigned char Xstart,unsigned char Xend,unsigned int Ystart,unsigned int Yend,unsigned char* olddata, unsigned char* newdata,unsigned char old_label,unsigned char new_label)
{
  //Serial.println("partial refresh begin");
  ReadBusy(); 
  EPD_WriteCMD(0x50); 
  EPD_WriteData (0xb7);
  //Serial.println("lut upload begin");
  LUT_Upload1();
  //Serial.println("lut upload end");
  unsigned int Xsize=Xend-Xstart;
  unsigned int Ysize=Yend-Ystart+1;
 if(Xsize%8 != 0){
    Xsize = Xsize+(8-Xsize%8);
  }
  Xsize = Xsize/8;
  unsigned int offset=Ystart*16+Xstart/8;
  unsigned int temp=Ystart;
  //Ystart=295-Yend;Yend=295-temp;
  
//Serial.println("enter partial mode begin");
  EPD_WriteCMD(0x91); //enter partial refresh mode
  EPD_WriteCMD(0x90); 
  EPD_WriteData (Xstart);
  EPD_WriteData (Xend);
  EPD_WriteData (Ystart/256);
  EPD_WriteData (Ystart%256);
  EPD_WriteData (Yend/256);
  EPD_WriteData (Yend%256);
  EPD_WriteData (0x0);
 // Serial.println("enter partial mode end");
 
 // ReadBusy();  
  EPD_CS_0;  
  EPD_DC_0;   //command write
  SPI_Write(0x10);
  EPD_DC_1;   //data write
   //Serial.println("olddata");
  if(old_label==0)
  {
    for(int i=0;i<Ysize;i++){
    for(int j=0;j<Xsize;j++){
      SPI_Write(*olddata);
     }
    }
  }
  else
  {
  olddata+=offset;
  for(int i=0;i<Ysize;i++){
    for(int j=0;j<Xsize;j++){
      SPI_Write(*olddata);
      olddata++;
       }
       newdata+=16-Xsize;
   }
  }
  EPD_CS_1;
  //Serial.println("newdata");
  ReadBusy();  
  EPD_CS_0;  
  EPD_DC_0;   //command write
  SPI_Write(0x13);
  EPD_DC_1;   //data write
  if(new_label==0)
  {
    for(int i=0;i<Ysize;i++){
    for(int j=0;j<Xsize;j++){
     SPI_Write(*newdata);
         }
      }
  }
  else
  {
  newdata+=offset;
  for(int i=0;i<Ysize;i++){
    for(int j=0;j<Xsize;j++){
     SPI_Write(*newdata);
      newdata++;
       }
      newdata+=16-Xsize;
   }
  }
  EPD_CS_1;
 // Serial.println("alldone");
  driver_delay_xms(200);
  EPD_WriteCMD(0x12);
  EPD_WriteCMD(0x92);
  }
