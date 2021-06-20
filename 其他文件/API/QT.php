  
<?php

 
require 'conn.php';
header('Content-Type:text/html;charset=utf-8');
error_reporting(E_ALL^E_NOTICE^E_WARNING);

//过滤表
function lib_replace_end_tag($str) {
    if (empty($str)) return false;
    $str = htmlspecialchars($str);
    $str = str_replace('/', "", $str);
    $str = str_replace('"', "", $str);
    $str = str_replace('(', "", $str);
    $str = str_replace(')', "", $str);
    $str = str_replace('CR', "", $str);
    $str = str_replace('ASCII', "", $str);
    $str = str_replace('ASCII 0x0d', "", $str);
    $str = str_replace('LF', "", $str);
    $str = str_replace('ASCII 0x0a', "", $str);
    $str = str_replace(',', "", $str);
    $str = str_replace('%', "", $str);
    $str = str_replace(';', "", $str);
    $str = str_replace('eval', "", $str);
    $str = str_replace('open', "", $str);
    $str = str_replace('sysopen', "", $str);
    $str = str_replace('system', "", $str);
    $str = str_replace('$', "", $str);
    $str = str_replace("'", "", $str);
    $str = str_replace("'", "", $str);
    $str = str_replace('ASCII 0x08', "", $str);
    $str = str_replace('"', "", $str);
    $str = str_replace('"', "", $str);
    $str = str_replace("", "", $str);
    $str = str_replace("&gt", "", $str);
    $str = str_replace("&lt", "", $str);
    $str = str_replace("<SCRIPT>", "", $str);
    $str = str_replace("</SCRIPT>", "", $str);
    $str = str_replace("<script>", "", $str);
    $str = str_replace("</script>", "", $str);
    $str = str_replace("select", "", $str);
    $str = str_replace("join", "", $str);
    $str = str_replace("union", "", $str);
    $str = str_replace("where", "", $str);
    $str = str_replace("insert", "", $str);
    $str = str_replace("delete", "", $str);
    $str = str_replace("update", "", $str);
    $str = str_replace("like", "", $str);
    $str = str_replace("drop", "", $str);
    $str = str_replace("DROP", "", $str);
    $str = str_replace("sleep", "", $str);
    $str = str_replace("create", "", $str);
    $str = str_replace("modify", "", $str);
    $str = str_replace("rename", "", $str);
    $str = str_replace("alter", "", $str);
    $str = str_replace("cas", "", $str);
    $str = str_replace("&", "", $str);
    $str = str_replace(">", "", $str);
    $str = str_replace("<", "", $str);
    $str = str_replace(" ", chr(32), $str);
    $str = str_replace(" ", chr(9), $str);
    $str = str_replace("    ", chr(9), $str);
    $str = str_replace("&", chr(34), $str);
    $str = str_replace("'", chr(39), $str);
    $str = str_replace("<br />", chr(13), $str);
    $str = str_replace("''", "'", $str);
    $str = str_replace("css", "'", $str);
    $str = str_replace("CSS", "'", $str);
    $str = str_replace("<!--", "", $str);
    $str = str_replace("convert", "", $str);
    $str = str_replace("md5", "", $str);
    $str = str_replace("passwd", "", $str);
    $str = str_replace("password", "", $str);
    $str = str_replace("../", "", $str);
    $str = str_replace("./", "", $str);
    $str = str_replace("Array", "", $str);
    $str = str_replace("or 1='1'", "", $str);
    $str = str_replace(";set|set&set;", "", $str);
    $str = str_replace("`set|set&set`", "", $str);
    $str = str_replace("--", "", $str);
    $str = str_replace("OR", "", $str);
    $str = str_replace('"', "", $str);
    $str = str_replace("*", "", $str);
    $str = str_replace("-", "", $str);
    $str = str_replace("+", "", $str);
    $str = str_replace("/", "", $str);
    $str = str_replace("=", "", $str);
    $str = str_replace("'/", "", $str);
    $str = str_replace("-- ", "", $str);
    $str = str_replace(" -- ", "", $str);
    $str = str_replace(" --", "", $str);
    $str = str_replace("(", "", $str);
    $str = str_replace(")", "", $str);
    $str = str_replace("{", "", $str);
    $str = str_replace("}", "", $str);
    $str = str_replace("-1", "", $str);
    //$str = str_replace(".", "", $str);
    $str = str_replace("response", "", $str);
    $str = str_replace("write", "", $str);
    $str = str_replace("|", "", $str);
    $str = str_replace("`", "", $str);
    $str = str_replace(";", "", $str);
    $str = str_replace("etc", "", $str);
    $str = str_replace("root", "", $str);
    $str = str_replace("//", "", $str);
    $str = str_replace("!=", "", $str);
    $str = str_replace("$", "", $str);
    $str = str_replace("&", "", $str);
    $str = str_replace("&&", "", $str);
    $str = str_replace("==", "", $str);
    $str = str_replace("#", "", $str);
    $str = str_replace("@", "", $str);
    $str = str_replace("mailto:", "", $str);
    $str = str_replace("CHAR", "", $str);
    $str = str_replace("char", "", $str);
	return $str;	 
}

$action = $_GET['model'];
switch ($action) {
    //账号登录登录  1-->登陆成功         0-->登录失败
    case"1":
        $username = lib_replace_end_tag($_POST['username']);
        $passwd2 = lib_replace_end_tag($_POST['passwd']);
        $passwd = md5("$passwd2" );
        $sqluser = "select username,passwd from `account` where username='" . $username . "' and passwd='" . $passwd2 . "'";
        $queryuser = mysqli_query($conn, $sqluser);
        // echo $sqluser;
        $rowuser = mysqli_fetch_array($queryuser,MYSQLI_ASSOC);
        //确保获取数据正确，并且不为空
        if ($rowuser && is_array($rowuser) && !empty($rowuser)) {
            //密码和用户名有都正确
            if ($rowuser['username'] == $username && $rowuser['passwd'] == $passwd2) {
                //密码正确
                $result = array(
                    'status' => '1',
                );
                echo json_encode($result);
                exit();
            } else if($rowuser['username'] == $username){
                // 账号正确，密码错误
                $result = array(
                    'status' => '2',
                );
                echo json_encode($result);
                exit();
            }
        } else {
            $result = array(
                // 账号密码为空
                'status' => '3',
            );
            echo json_encode($result);
            exit();
        }
    
    // 注册账号密码（账号、密码、头像链接、头像删除链接）
    case "2":
        $username = lib_replace_end_tag($_POST['username']);
        $passwd = $_POST['passwd'];
        $passwd2 =  md5("$passwd");
        $avatorUrl = $_POST['avatorUrl'];
        $deleteUrl = $_POST['deleteUrl'];
        // 查询注册用户名字是否已存在
        $sqlfind= "select *  from `account` where username='" . $username . "'";
        $res = mysqli_query($conn,$sqlfind);
        $row = mysqli_fetch_array($res,MYSQLI_ASSOC);
        if($row['username']!=$username && !empty($username) && !empty($passwd) ){
            $add_sql = "INSERT INTO `account`(`username`, `passwd`,`avatorUrl`,`deleteUrl`) VALUES ('" . $username . "', '" . $passwd . "', '" . $avatorUrl . "', '" . $deleteUrl . "')";
            // echo $add_sql;
            $result = mysqli_query($conn, $add_sql);
            if (!$result) {
                echo $result;
                echo "{\"status\": '11'}";
                break;
            }
            echo "{\"status\": '1'}";
        }
        else{
            echo "{\"status\": '-1'}";
        }
    break;

    //返回头像链接、账号、密码等数据
    case "3":
        $username = lib_replace_end_tag($_POST['username']);
        $query_sql = "select * from `account` where  username='".$username. "'";
        // echo $query_sql;
        $resoure = mysqli_query($conn, $query_sql);
        //$row = mysqli_fetch_array($resoure);
        while ($row = mysqli_fetch_array($resoure, MYSQLI_BOTH)) {
            $arr = array(
                'username' => $row['username'],
                'passwd' => $row['passwd'],
                'avatorUrl' => $row['avatorUrl'],
                'deleteUrl' => $row['deleteUrl']
            );
            $data[]=$arr;
        }
        //把数据转换为JSON数据.
        $json = json_encode($data);
        echo "{" . '"data"' . ":" . $json . "}";
        break;

    //返回温湿度数据
    case "4":
        $id = lib_replace_end_tag($_POST['id']);
        $query_sql = "select * from `data` where  id='".$id. "'";
        // echo $query_sql;
        $resoure = mysqli_query($conn, $query_sql);
        //$row = mysqli_fetch_array($resoure);
        while ($row = mysqli_fetch_array($resoure, MYSQLI_BOTH)) {
            $arr = array(
                'date' => $row['date'],
                'humanity' => $row['humanity'],
                'temperature' => $row['temperature'],
                'id' => $row['id'],
                'ppm' => $row['ppm']
            );
            $data[]=$arr;
        }
        //把数据转换为JSON数据.
        $json = json_encode($data);
        echo "{" . '"data"' . ":" . $json . "}";
        // echo $json;
        break;
        
    default:
    exit();
}
?>