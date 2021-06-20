<?php
$host='127.0.0.1';//主机
$user='user';//数据库账号
$password='root123.';//数据库密码
$database='data';//数据库名

//打开数据库连接
$conn=mysqli_connect($host,$user,$password,$database);

//判断连接是否成功
if($conn){
  $conn->query("set names utf8");//设置UTF-8编码(JSON的唯一编码)
  // echo "连接成功";

}else{
  echo 'DATABASE_CONNECTION_DIE';//数据库连接失败
  exit;
}

//信息提示函数
function showmsg($text,$urlstr="")
   {
    if($urlstr){
  echo '<Script>alert("'.$text.'");window.location.href="'.$urlstr.'";</Script>';
  exit;
 }
 else {
  echo "<Script>alert('".$text."');history.go(-1);</Script>";
  exit;
 } 
}
?>