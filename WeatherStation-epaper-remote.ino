/**The MIT License (MIT)

Copyright (c) 2017 by Hui Lu

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#include <ESP8266WiFi.h>
#include <Ticker.h>
#include <JsonListener.h>
#include "Wire.h"
#include "TimeClient.h"
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         
#include "heweather.h"
#include <EEPROM.h>
#include <SPI.h>
#include "EPD_drive.h"
#include "EPD_drive_gpio.h"
#include "bitmaps.h"
#include "lang.h"
ADC_MODE(ADC_VCC);
/***************************
  Settings
 **************************/

const int sleeptime=60;     //updating interval 71min maximum
int timeupdateinterval=60;  //update time on display/seconds
const float UTC_OFFSET = 8;
byte end_time=7;            //time that stops to update weather forecast
byte start_time=7;          //time that starts to update weather forecast
const char* server="www.duckweather.tk";
const char* client_name="news"; //send message to weather station via duckduckweather.esy.es/client.php
//modify language in lang.h

 /***************************
  **************************/
String city;
String lastUpdate = "--";
bool shouldsave=false;
bool updating=false; //is in updating progress
TimeClient timeClient(UTC_OFFSET,server);
WaveShare_EPD EPD = WaveShare_EPD();
heweatherclient heweather(server,lang);

Ticker avoidstuck;

void saveConfigCallback () {
   shouldsave=true;
}
void setup() {
 
  Serial.begin(115200);
  
  Serial.println("check_rtc_mem");Serial.println("check_rtc_mem");read_time_from_rtc_mem();
  check_rtc_mem();
   if (read_config()==126)
  {
    Serial.println("readconfig=126");
     EPD.deepsleep(); ESP.deepSleep(60 * 60 * 1000000);
    }
  pinMode(D3,INPUT);
  pinMode(CS,OUTPUT);
  pinMode(DC,OUTPUT);
  pinMode(RST,OUTPUT);
  pinMode(BUSY,INPUT);
  EEPROM.begin(20);
  SPI.beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE0));
  SPI.begin();
  EPD.EPD_init_Part();driver_delay_xms(DELAYTIME);
  
  update_time();//display time
 heweather.client_name=client_name;  
 
   /*************************************************
   wifimanager
   *************************************************/
  
  WiFiManagerParameter custom_c("city","city","your city", 20);
  WiFiManager wifiManager;

  wifiManager.setConfigPortalTimeout(180);
  wifiManager.setAPCallback(configModeCallback);
  wifiManager.setSaveConfigCallback(saveConfigCallback);
  wifiManager.addParameter(&custom_c); 
  wifiManager.autoConnect("Weather widget"); 

  while (WiFi.status() != WL_CONNECTED)
  {
   always_sleep();
  ////Serial.println("failed to connect and hit timeout");
  EPD.clearshadows(); 
  EPD.clearbuffer();
  EPD.fontscale=1;
  EPD.SetFont(3);
  EPD.DrawUTF(0,0,12,12,config_timeout_line1);
  EPD.DrawUTF(18,0,12,12,config_timeout_line2);
  EPD.DrawUTF(36,0,12,12,config_timeout_line3); 
  EPD.DrawUTF(52,0,12,12,config_timeout_line4); 
  EPD.EPD_Dis_Part(0,127,0,295,(unsigned char *)EPD.EPDbuffer,1);
  EPD.deepsleep(); ESP.deepSleep(60 * 60 * 1000000);
  }
 city= custom_c.getValue();
   
   /*************************************************
   EPPROM
   *************************************************/
  if (city!="your city")
  {
    
         EEPROM.write(0,city.length());
         ////Serial.print("\n\n");
         ////Serial.println(String("eeprom_write_0:")+city.length());
         for(int i=0;i<city.length();i++)
         {
           EEPROM.write(i+1,city[i]);
        
         ////Serial.println(city[i]); ////Serial.print("\n\n");
          }
         EEPROM.commit(); 
    }
   
 byte city_length=EEPROM.read(0);
 ////Serial.println("EEPROM_CITY-LENGTH:");////Serial.println(city_length);
 if (city_length>0)
 {
  String test="";
  for(int x=1;x<city_length+1;x++) 
  {test+=(char)EEPROM.read(x);
  ////Serial.print((char)EEPROM.read(x));
  }
  city=test;
  ////Serial.println("   test:");////Serial.print(test);
  heweather.city=city;
  }
/*************************************************
   update weather
*************************************************/
//heweather.city="huangdao";
heweather.EPDbuffer=&EPD.EPDbuffer[0];
avoidstuck.attach(10,check);
updating=true;
updateData();
updating=false;
updatedisplay();

}
void check()
{
  if(updating==true)
  {EPD.deepsleep(); ESP.deepSleep(60 * sleeptime * 1000000);}
  avoidstuck.detach();
  return;
  }

void loop() {
 
 if(digitalRead(D3)==LOW)
 {
  WiFiManager wifiManager;
  wifiManager.resetSettings();
 }
 
EPD.deepsleep();
 byte seconds=timeClient.getSeconds_byte();
        if(seconds>50) timeupdateinterval=seconds+60;
        else timeupdateinterval=60-seconds;
        timeClient.localEpoc+=timeupdateinterval;

write_time_to_rtc_mem();//save time before sleeping
ESP.deepSleep(timeupdateinterval * 1 * 1000000); //main control of sleeping inverval

}
void updatedisplay()
{
   EPD.clearshadows(); 
   EPD.fontscale=1;
   dis_batt(3,272);
  
   EPD.SetFont(2);
  
 // EPD.DrawUTF(20,220,10,10,(String)ESP.getVcc()+" "+(String)lastUpdate);
   EPD.EPD_Dis_Part(0,127,0,295,(unsigned char *)EPD.EPDbuffer,1);
   driver_delay_xms(DELAYTIME); 
  // dis_time(0, 230);
 }
 void dis_batt(int16_t x, int16_t y)
{
  /*attention! calibrate it yourself */
   float voltage;
   voltage=(float)ESP.getVcc()/1000; 
  
  float batt_voltage=voltage;
  
 /*attention! calibrate it yourself */
  if (batt_voltage<=2.9)  {EPD.clearbuffer();EPD.DrawXbm_P(39,98,100,50,(unsigned char *)needcharge);always_sleep();}
  if (batt_voltage>2.9&&batt_voltage<=2.95)  EPD.DrawXbm_P(x,y,20,10,(unsigned char *)batt_1);
  if (batt_voltage>2.95&&batt_voltage<=3.0)  EPD.DrawXbm_P(x,y,20,10,(unsigned char *)batt_2);
  if (batt_voltage>3.0&&batt_voltage<=3.05)  EPD.DrawXbm_P(x,y,20,10,(unsigned char *)batt_3);
  if (batt_voltage>3.05&&batt_voltage<=3.1)  EPD.DrawXbm_P(x,y,20,10,(unsigned char *)batt_4);
  if (batt_voltage>3.1)  EPD.DrawXbm_P(x,y,20,10,(unsigned char *)batt_5);
  
  }

 void dis_time(int16_t x, int16_t y)
 {
  x=24;y=128;
  EPD.fontscale=1;EPD.clearbuffer();
  EPD.SetFont(5);
  EPD.DrawUTF(x,y,70,70,timeClient.getFormattedTime());
  EPD.EPD_Dis_Part(24,95,128,295,(unsigned char *)EPD.EPDbuffer,1);
 }

void updateData() {
  
  timeClient.updateTime();
  heweather.update();
  lastUpdate = timeClient.getHours()+":"+timeClient.getMinutes();

  byte rtc_mem[4];rtc_mem[0]=126;
  byte Hours=timeClient.getHours().toInt();
  ////Serial.println("hour");
  ////Serial.print(Hours);
  if (Hours==end_time)
  {
    if((start_time-end_time)<0)  rtc_mem[1]=(24-Hours+start_time)*60/sleeptime;
    else rtc_mem[1]=(start_time-Hours)*60/sleeptime;
    ESP.rtcUserMemoryWrite(0, (uint32_t*)&rtc_mem, sizeof(rtc_mem));
    ////Serial.println("rtc_mem[1]");
    ////Serial.println(rtc_mem[1]);
    }
 
  ////Serial.print("heweather.rain");////Serial.print(heweather.rain);////Serial.print("\n");
  //delay(1000);
}

void configModeCallback (WiFiManager *myWiFiManager) {
  ////Serial.println("Entered config mode");
  ////Serial.println(WiFi.softAPIP());
  //if you used auto generated SSID, print it
  ////Serial.println(myWiFiManager->getConfigPortalSSID());
  //进入配置模式
  
  EPD.clearshadows(); EPD.clearbuffer();EPD.fontscale=1;
  EPD.SetFont(3);
  EPD.fontscale=1;
  EPD.DrawXbm_P(6,80,32,32,one);
  EPD.DrawXbm_P(42,80,32,32,two);
  EPD.DrawXbm_P(79,80,32,32,three);
  EPD.fontscale=1;
  EPD.DrawUTF(6,112,12,12,config_page_line1);
  EPD.DrawUTF(22,112,12,12,config_page_line2);
  EPD.DrawXline(80,295,39);
  EPD.DrawUTF(42,112,12,12,config_page_line3);
  EPD.DrawUTF(58,112,12,12,config_page_line4);
  EPD.DrawXline(80,295,76);
  EPD.DrawUTF(79,112,12,12,config_page_line5);
  EPD.DrawUTF(94,112,12,12,config_page_line6);
  EPD.DrawXbm_P(6,0,70,116,phone);
  EPD.EPD_Dis_Part(0,127,0,295,(unsigned char *)EPD.EPDbuffer,1);
  driver_delay_xms(DELAYTIME);
}

/*
 * rctmem[2]=126 always sleep
 * rctmem[0]=126 first time power up
 * rtc_mem[1] how many hours left
 * 
 */
void read_time_from_rtc_mem()
{ 
  byte rtc_mem[4];
  ESP.rtcUserMemoryRead(8, (uint32_t*)&rtc_mem, sizeof(rtc_mem));
  timeClient.localEpoc = ((unsigned long)rtc_mem[3] << 24) | ((unsigned long)rtc_mem[2] << 16) | ((unsigned long)rtc_mem[1] << 8) | (unsigned long)rtc_mem[0];
  Serial.println("readlocalepoc:");Serial.println(timeClient.localEpoc);
  }
void write_time_to_rtc_mem()
{
  //write time to rtc before sleep
  long time_before_sleep;
  time_before_sleep=timeClient.getCurrentEpoch();
  byte rtc_mem[4];
  rtc_mem[0] = byte(time_before_sleep);
  rtc_mem[1] = byte(time_before_sleep >> 8);
  rtc_mem[2] = byte(time_before_sleep >> 16);
  rtc_mem[3] = byte(time_before_sleep >> 24);
  ESP.rtcUserMemoryWrite(8, (uint32_t*)&rtc_mem, sizeof(rtc_mem));
  Serial.println("writelocalepoc:");Serial.println(rtc_mem[0]);
  Serial.println("writelocalepoc1:");Serial.println(rtc_mem[1]);
  Serial.println("writelocalepoc2:");Serial.println(rtc_mem[2]);
  Serial.println("writelocalepoc3:");Serial.println(rtc_mem[3]);

}

unsigned long read_config()
{
  byte rtc_mem[4];
  ESP.rtcUserMemoryRead(4, (uint32_t*)&rtc_mem, sizeof(rtc_mem));
  ////check if sleeping forever is needed
  return rtc_mem[2];
  
  }
unsigned long always_sleep()
{
  byte rtc_mem[4];
  ESP.rtcUserMemoryRead(4, (uint32_t*)&rtc_mem, sizeof(rtc_mem));
  if (rtc_mem[2]!=126)
  {
    ////Serial.println("first time to run check config");
    rtc_mem[2]=126;
    ESP.rtcUserMemoryWrite(4, (uint32_t*)&rtc_mem, sizeof(rtc_mem));
   
    }
  
  }
void check_rtc_mem()
{
  /*
  rtc_mem[0] sign for first run
  rtc_mem[1] how many hours left
  */
  byte rtc_mem[4];
  ESP.rtcUserMemoryRead(0, (uint32_t*)&rtc_mem, sizeof(rtc_mem));
  if (rtc_mem[0]!=126)
  {
    Serial.println("first time to run");
    byte times= byte(sleeptime*60/timeupdateinterval);
    Serial.println("times");Serial.println(times);
    rtc_mem[0]=126;
    rtc_mem[1]=0;
    rtc_mem[2]=times;//time
    Serial.println("rctmemblock0-2");Serial.println(rtc_mem[2]);
    ESP.rtcUserMemoryWrite(0, (uint32_t*)&rtc_mem, sizeof(rtc_mem));
    }
  else
  {
    if(rtc_mem[1]>0) 
    {
       rtc_mem[1]--;
       Serial.println("don't need to update weather");
       Serial.println(rtc_mem[1]);
       ESP.rtcUserMemoryWrite(0, (uint32_t*)&rtc_mem, sizeof(rtc_mem));
       EPD.deepsleep();
       ESP.deepSleep(60 * sleeptime * 1000000);
      }
    }
   
  }
  void update_time()
  {
      byte rtc_mem[4];
      byte times= byte(sleeptime*60/timeupdateinterval);
  ESP.rtcUserMemoryRead(0, (uint32_t*)&rtc_mem, sizeof(rtc_mem));
     Serial.println("rtcmem[2]");
    Serial.println(rtc_mem[2]);
  if(rtc_mem[2]>times-1)
  {
    rtc_mem[2]=0;
    ESP.rtcUserMemoryWrite(0, (uint32_t*)&rtc_mem, sizeof(rtc_mem));
      Serial.println("rctmem[2]>59 need to update weather");
    }
    else
    {
      Serial.println("don't need to update weather, need time");

       byte rct_temp=byte(rtc_mem[2]+1);
       rtc_mem[2]=rct_temp;
       dis_time(1, 240);
       EPD.deepsleep();
        byte seconds=timeClient.getSeconds_byte();
        if(seconds>50) timeupdateinterval=seconds+60;
        else timeupdateinterval=60-seconds;
        timeClient.localEpoc+=timeupdateinterval;
      
       write_time_to_rtc_mem();
       ESP.rtcUserMemoryWrite(0, (uint32_t*)&rtc_mem, sizeof(rtc_mem));
       ESP.deepSleep(timeupdateinterval * 1 * 1000000);
      }
  
    }
