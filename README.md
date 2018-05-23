# Esp8266-weather-station-epaper
中文版说明在这里http://hlu.lu/2017/07/06/esp8266%E7%94%B5%E7%BA%B8%E5%B1%8F%E5%A4%A9%E6%B0%94%E9%A2%84%E6%8A%A5%E7%AB%99/
## Summary
这个版本把图像处理和字库放在服务器端，使得每次更新天气的时间大大减少，省电
This version put display buffer on the serverside. esp8266 dont need waste time to read fonts and process images, just read and put into screen. save time and battery.

