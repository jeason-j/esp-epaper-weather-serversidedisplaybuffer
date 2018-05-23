<?php
class epd_drive{
var $xDot=128;
var $yDot=296;
var $EPDbuffer=array(); '4736'
function clearbuffer()
{
	for($i=0;$i<4736;$i++)
{
	$EPDbuffer[$i]=255;
}
}

function SetPixel($x, $y)
{
 if($x<$xDot and $y<$yDot)  EPDbuffer[$x/8+$y*$xDot/8]&=~(0x80>>$x%8) ;
	
}






}


?>