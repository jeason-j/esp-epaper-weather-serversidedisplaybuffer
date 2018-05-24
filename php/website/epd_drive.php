<?php
class epd_drive{
var $xDot=128;
var $yDot=296;
var $fontscale=1;
var $CurrentCursor=0;
var $EPDbuffer=array();
var $fontname;
var $fontwidth;
var $fontheight;
var $message =array(0x00,0x00,0x1F,0x80,0x00,0x00,0x1F,0x80,0x3F,0xC0,0x7F,0xE0,0x00,0x00,0x10,0x80,0x4F,0x20,0x20,0x40,0x1F,0x80,0x00,0x00);

var $aqi_icon =array(
0x1F,0x00,0x20,0xC0,0x6B,0xE0,0x60,0xE0,0xFF,0xF0,0xF1,0xF0,0xEE,0xF0,0xED,0xF0,
0x72,0xE0,0x7F,0xE0,0x20,0xC0,0x1F,0x00);

var $city_icon= array(
0x00,0x00,0x1C,0x00,0x77,0x00,0x41,0x80,0x9C,0x60,0xA2,0x30,0xA2,0x30,0x9C,0xC0,
0x41,0x80,0x77,0x00,0x1C,0x00,0x00,0x00);
function clearbuffer()
{
	for($i=0;$i<4736;$i++)
{
	$this->EPDbuffer[$i]=255;
}
}

function SetPixel($x,$y)
{
 if($x<$this->xDot and $y<$this->yDot)  $this->EPDbuffer[$x/8+$y*$this->xDot/8]&=~(0x80>>$x%8) ;
}
function DrawXline($start,$end, $x)
  {
    for($i=$start;$i<=$end;$i++)
    {
      $this->SetPixel($x,$i);
      }
  }
function DrawYline($start,$end,$y)
  {
	  
    for($i=$start;$i<=$end;$i++)
    {
      $this->SetPixel($i,$y);
      }
  }
 function SetFont($fontindex)
{
     switch ($fontindex)
     {
     case 0:
     $this->fontname="./font/font16";$this->fontwidth=16;$this->fontheight=16;break;
     case 1:
     $this->fontname="./font/font32";$this->fontwidth=32;$this->fontheight=32;break;
     case 2:
     $this->fontname="./font/font10";$this->fontwidth=10;$this->fontheight=10;break;
     case 3:
     $this->fontname="./font/font12";$this->fontwidth=12;$this->fontheight=12;break;
     case 11:
     $this->fontname="./font/weathericon";$this->fontwidth=32;$this->fontheight=32;break;
     case 12:
     $this->fontname="./font/weathericon80";$this->fontwidth=80;$this->fontheight=80;break;
      case 13:
     $this->fontname="./font/weathericon32";$this->fontwidth=32;$this->fontheight=32;break;
     }
  } 
  
function DrawXbm($xMove, $yMove, $width, $height,$xbm) {
  $heightInXbm = floor(($height + 7) / 8);
 //echo "heightinXBM".$heightInXbm."\n";
  $data=(int)0xff;
  //echo ord($data);
  for($x = 0; $x < $width; $x++) {
    for($y = 0; $y < $height; $y++ ) {
		//echo "y=".$y;
      if ($y & 7) {
		 $data<<=1; // Move a bit
		// echo "dat[".$data."]";
      } else {  // Read new data every 8 bit
        $data = $xbm[floor($y / 8) + $x * $heightInXbm];
		//echo "\n"."newByte"; echo "dat[".$data."]";
		$data=hexdec($data);
		//echo "[".bin2hex($data)."]";
		
      }
      // if there is a bit draw it
	  
	 // echo decbin(($data & 0x80)>>7);
      if ((($data & 0x80)>>7)>0) {
		 // echo "abit";
       if($this->fontscale==1) {$this->SetPixel($xMove + $y, $yMove + $x);$this->CurrentCursor=$x;}
       }
    }
  }
}
function DrawXbm_P($xMove, $yMove, $width, $height,$xbm) {
  $heightInXbm = floor(($height + 7) / 8);
 //echo "heightinXBM".$heightInXbm."\n";
  $data=(int)0xff;
  //echo ord($data);
  for($x = 0; $x < $width; $x++) {
    for($y = 0; $y < $height; $y++ ) {
		//echo "y=".$y;
      if ($y & 7) {
		 $data<<=1; // Move a bit
		// echo "dat[".$data."]";
      } else {  // Read new data every 8 bit
        $data = $xbm[floor($y / 8) + $x * $heightInXbm];
		//echo "\n"."newByte"; echo "dat[".$data."]";
		//$data=hexdec($data);
		//echo "[".bin2hex($data)."]";
		
      }
      // if there is a bit draw it
	  
	 // echo decbin(($data & 0x80)>>7);
      if ((($data & 0x80)>>7)>0) {
		//  echo "abit";
       if($this->fontscale==1) {$this->SetPixel($xMove + $y, $yMove + $x);$this->CurrentCursor=$x;}
       }
    }
  }
}

function DrawUnicodeChar($x,$y,$width,$height,&$code)
 { 
  
  $offset;
  $sizeofsinglechar;
  if ($height%8==0) $sizeofsinglechar=floor($height/8)*$width;
  else $sizeofsinglechar=floor($height/8+1)*$width;
 // echo $sizeofsinglechar;
 $offset=($code[0]*0x100+$code[1])*$sizeofsinglechar;
  $file=fopen($this->fontname,"r");
  
  fseek($file,$offset);
 // echo "offset[".$offset."]";
 // echo "ftell".ftell($file);
  $zi=array();
  for ($i=0;$i<$sizeofsinglechar;$i++)
  {
	$zi[$i]=fread($file,1);
	$zi[$i]=bin2hex($zi[$i]);
   // echo "b".$i."[".$zi[$i]."]" ;
	//echo "ftell".ftell($file);
  }
 
  $this->DrawXbm($x,$y,$width,$height,$zi); 

fclose($file);
}
function DrawUTF($x,$y,$width,$height,$code)
{

  $charcount=mb_strlen($code,'utf8');
  $code=iconv("UTF-8","UCS-2",$code);
  //echo $code;
 // echo strlen($code);
  
  
  $this->CurrentCursor=0;
  $sizeofsinglechar;
  if ($height%8==0) $sizeofsinglechar=floor($height/8)*$width;
  else $sizeofsinglechar=floor($height/8+1)*$width;
  $ymove=0;
  $xmove=0;
  $strlength=strlen($code);
  
   $bytes=array();
    for ($i=0; $i < strlen($code); $i++) { 
        $tmp=substr($code, $i,1);
        $bytes[$i]=bin2hex($tmp);
	//echo "b".$bytes[$i]."b";
    }
    
	$i=0;
  while($i<$strlength)
  {
	  // echo "bytes0[".$bytes[$i]."]bytes1[".$bytes[$i+1]."]";
     $bytes[$i]=hexdec($bytes[$i]);
	 $bytes[$i+1]=hexdec($bytes[$i+1]);
      $offset=($bytes[$i]*0x100+$bytes[$i+1])*$sizeofsinglechar;
	  //echo "offset[".$offset."]";
	 // echo "bytes0[".$bytes[$i]."]bytes1[".$bytes[$i+1]."]";
	  $temparrary=array();
	  $temparray[0]=$bytes[$i];
	  $temparray[1]=$bytes[$i+1];
      if ($offset<0xff*$sizeofsinglechar) 
      {
      
      $this->DrawUnicodeChar($x+$xmove,$y+$ymove,$width,$height,$temparray);
      $ymove+=$this->CurrentCursor+1;
      if(($y+$ymove+$width)>=$this->yDot-1) {$xmove+=$height+1;$ymove=0;$thiss->CurrentCursor=0;}
    }
    
    else
    {
      $this->DrawUnicodeChar($x+$xmove,$y+$ymove,$width,$height,$temparray);
      $ymove+=$width;
      if(($y+$ymove+$width)>=$this->yDot-1) {$xmove+=$height+1;$ymove=0;$this->CurrentCursor=0;}
      }
    $i++;$i++;
    }
  }
function getMeteoconIcon($index)
{
 // echo "recieveindes".$index;
  $index=(int)$index;
  if($index==0) $re=12;
  if($index==1) $re=58;
  if($index==2) $re=58;
  if($index==3) $re=58;
  if($index==4) $re=54;
  if($index>=5&&$index<=18) $re=0;
  if($index>=19&&$index<=32) $re=19;
  if($index>=33&&$index<=36)   $re=5;
  if($index>=37&&$index<=40)   $re=16;
  if($index==41) $re=28;
  if($index==42) $re=28;
  if($index==43) $re=28;
  //echo "return".$re;
	return $re;
}
  
  }


?>