<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>无标题文档</title>
</head>

<body>
	<?php
	session_start();
	$dir_root=$_SERVER['DOCUMENT_ROOT'];
        if ($_FILES["file"]["size"] < 20000)
        {
            if ($_FILES["file"]["error"] > 0)
                echo "Return Code: " . $_FILES["file"]["error"] . "<br />";
            else
            {
                echo "Upload: " . $_FILES["file"]["name"] . "<br />";
                echo "Type: " . $_FILES["file"]["type"] . "<br />";
                echo "Size: " . ($_FILES["file"]["size"] / 1024) . " Kb<br />";
                echo "Temp file: " . $_FILES["file"]["tmp_name"] . "<br />";

                if (file_exists("$dir_root/root/assets/teacher/teacher_file/" . $_FILES["file"]["name"]))
                    echo $_FILES["file"]["name"] . " already exists. ";
                else
                 {
                     move_uploaded_file($_FILES["file"]["tmp_name"],
                     "$dir_root/root/assets/teacher/teacher_file/" . $_FILES["file"]["name"]);
                     echo "Stored in: " . "/root/assets/teacher/teacher_file/" . $_FILES["file"]["name"];
                 }
             }
         }
         else    echo "Invalid file";
	
	/*处理上传的csv文件,将姓名性别写入数据库*/
	$filename=$_FILES["file"]["name"];
	$link=mysql_connect('localhost','root','123456');
	if(!$link)    echo "数据库连接失败".mysql.error();
	        else
			{
                mysql_select_db('test',$link);//选数据库
                mysql_query("set names utf8");//设置编码
                echo 'Connection OK'."\n";
            }
	$handle=fopen("$dir_root/root/assets/teacher/teacher_file/$filename", "r");
	
	
	//解析csv
    $result_arr=array();
    $i=0;
	$data_line=array();	
    while($data_line=fgetcsv($handle)) 
	{
		$result_arr[$i]=array();
        for($j=0;$j<=1;$j++)
		{
			$result_arr[$i][$j]=$data_line[$j];
		}
        $i++;
    }
	
	/*打印数组*/
	for($i=0;$i<14;$i++)
	{
		for($j=0;$j<=1;$j++) echo $result_arr[$i][$j]." ";
		echo "\n";
	}
	/*for ($i = 1; $i < $len_result; $i++) 
	{   //循环获取各字段值
		$name = iconv('gb2312', 'utf-8', $result[$i][0]); //中文转码
		$sex = iconv('gb2312', 'utf-8', $result[$i][1]);
		echo $name."aaa".$sex;
		$data_values .= "('$name','$sex'),";
	}*/
	fclose($handle); //关闭指针
	
	//批量插入数据表中
	for($i=0;$i<15;$i++)
	{
		$stu_id=(string)rand(100000,999999);
		$stu_pwd=(string)rand(100000,999999);
		$sql=mysql_query("insert into student (teacher,stu_id,stu_pwd,name,sex) values ('{$_SESSION['t_name']}','{$stu_id}','{$stu_pwd}','{$result_arr[$i][0]}','{$result_arr[$i][1]}')");
        if ($sql) echo "插入成功\n";
        else echo "插入失败，SQL:$sql<br>错误：".mysql_error();
	}
	
	
    /*参数设置*/
	$h = fopen("$dir_root/root/assets/student/jilu.txt","a");
    fwrite($h,$_SESSION['t_name'].",".$_POST['renshu']."\n");
	


    ?>
  

</body>
</html>