<?php
include 'epd_drive.php';
$epd=new epd_drive();
epd.clearbuffer();
epd.SetPixel(0,0);
echo epd.EPDbuffer;

?>