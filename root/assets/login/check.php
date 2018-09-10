<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>check</title>
</head>

<body>
	<?php
        session_start();//启session
        $link=mysql_connect('localhost','root','123456');//数据库连接填入应参数
	
	        /*链接数据库*/
            if(!$link)    echo "数据库连接失败".mysql.error();
	        else
			{
                mysql_select_db('test',$link);//选数据库
                mysql_query("set names utf8");//设置编码
            }

            /*获取表单提交数据*/
            $username=$_POST['usrid'];
            $password=$_POST['pwd'];
	        if(isset($_POST['submit_teacher']))    $loginway=$_POST['submit_teacher'];
            else $loginway=$_POST['submit_student'];
	
	
            /*查询判断*/
	       if($loginway=="教师登陆")
		   {
			   $sql="select * from teacher where usrid='$username' and pwd='$password'";
               $rec=mysql_query($sql) or die ("执行失败");
               if(mysql_num_rows($rec)>0)
		       {
				   $row = mysql_fetch_row($rec);
                   $_SESSION['t_name']=$row[1];//session存储记录登录状态
                   echo "登录成功，1秒钟后跳转到老师管理页面";
	               header("Refresh:1;url=/root/assets/teacher/index_teacher.php");
               }
	           else    echo "<script>alert('密码或用户名错误');history.go(-1);</script>";//登录失败
		   }
	       if($loginway=="学生登陆")
		   {
			   $sql="select * from student where stu_id='$username' and stu_pwd='$password'";
               $rec=mysql_query($sql) or die ("执行失败");
               if(mysql_num_rows($rec)>0)
		       {
				   $row = mysql_fetch_row($rec);
                   $_SESSION['s_name']=$row[4];//session存储记录登录状态
				   $_SESSION['sex']=$row[5];
                   echo "登录成功，1秒钟后跳转到调查页面";
	               header("Refresh:1;url=/root/assets/student/index_student.php");
               }
	           else    echo "<script>alert('密码或用户名错误');history.go(-1);</script>";//登录失败
		   }
	       
           

?>
</body>
</html>