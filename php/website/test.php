<?php
$url="https://free-api.heweather.com/v5/weather?city=qingdao&key=fab38a62dcaa4630aa9eac1a3ae097aa&lang=ch";  

$html = file_get_contents($url); 
echo $html;

?>