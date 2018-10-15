<?php 

//news
//$rssfeed = array("http://rss.sina.com.cn/news/world/focus15.xml");
$rssfeed = array("http://www.people.com.cn/rss/world.xml");
header('Content-Type:text/html;charset= UTF-8');    
for($i=0;$i<sizeof($rssfeed);$i++){//分解开始
    $buff = "";
    $rss_str="";
    //打开rss地址，并读取，读取失败则中止
    $fp = fopen($rssfeed[$i],"r") or die("can not open $rssfeed"); 
    while ( !feof($fp) ) {
        $buff .= fgets($fp,4096);
    }
    //关闭文件打开
    fclose($fp);
 //建立一个 XML 解析器
    $parser = xml_parser_create();
    //xml_parser_set_option -- 为指定 XML 解析进行选项设置
    xml_parser_set_option($parser,XML_OPTION_SKIP_WHITE,1);
    //xml_parse_into_struct -- 将 XML 数据解析到数组$values中
    xml_parse_into_struct($parser,$buff,$values,$idx);
    //xml_parser_free -- 释放指定的 XML 解析器
    xml_parser_free($parser);
$i=1;
    foreach ($values as $val) {
    
        $tag = $val["tag"];
        $type = $val["type"];
        $value = $val["value"];
        //标签统一转为小写
        $tag = strtolower($tag);
        
        if ($tag == "item" && $type == "open"){
            $is_item = 1;
        }else if ($tag == "item" && $type == "close") {
            //构造输出字符串
            $rss_str .= $title;
            $is_item = 0; break;
        }
        //仅读取item标签中的内容
        if($is_item==1){
            if ($tag == "title") {$title = $value;}        
            if ($tag == "link") {$link = $value;}
        }
  
    }
    //输出结果
//echo $rss_str;

}	








$client_name="news";
$message=$rss_str;

$con = mysqli_connect("localhost","duckweather","duckweather","duckweather");
if (!$con)
  {
  die('Could not connect: ' . mysqli_error());
  echo 'error sql connect';
  }
$result_message=mysqli_query($con,"SELECT * FROM message WHERE client_name='".$client_name."'");  
 if(mysqli_num_rows($result_message)==0)
{
mysqli_query($con,"INSERT INTO message (client_name,message) VALUES ('".$client_name."', '".$message."')");
echo("success");
}
else
{
$row=mysqli_fetch_array($result_message);
mysqli_query($con,"UPDATE message SET message='".$message."' WHERE client_name='".$client_name."'");
echo("success");
} 
  
?>