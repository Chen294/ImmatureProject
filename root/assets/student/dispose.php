<!DOCTYPE html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>无标题文档</title>
</head>

<body>
    <?php
    session_start();
    //获取表单提交数据
     $q1=$_POST['shuijiao'];
     $q2=$_POST['qichuang'];
     $q3=$_POST['guihua'];
     $q4=$_POST['dsws'];
     $q5=$_POST['xyf'];
     $q6=$_POST['xzxt'];
     $q7=$_POST['dbz'];
     $q8=$_POST['sy'];
     $q9=$_POST['ecy'];
     $q10=$_POST['chouyan'];
     $q11=$_POST['lt'];
     $q12=$_POST['hd'];
     $q13=$_POST['youxi'];
     $q14=$_POST['wushui'];
     $q15=$_POST['yundong'];


//记录数据
$h = fopen("jilu.txt","a");//写入方式打开文件jilu.txt，如果没有则创建之
fwrite($h,$_SESSION['s_name'].",".$_SESSION['sex'].",");
fwrite($h,$q1.",".$q2.",".$q3.",".$q4.",".$q5.",".$q6.",".$q7.",".$q8.",".$q10.",".$q11.",".$q12.",".$q13.",".$q14.",".$q15."\r\n");//把变量写入文件
fclose($h);//关闭文件

//反馈
echo "提交成功,再次感谢你们的支持";

?>
</p>
<p>&nbsp;</p>
<img src="images/hhh.gif" />
</body>

</html>