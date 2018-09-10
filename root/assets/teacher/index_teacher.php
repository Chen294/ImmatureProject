<!DOCTYPE html>
<html>
<head>
	<title>File Upload widget a Flat Responsive Widget Template :: w3layouts</title>
	<link rel="stylesheet" href="css/style.css">
	


		<meta name="viewport" content="width=device-width, initial-scale=1" />
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />

		<script type="application/x-javascript"> addEventListener("load", function() { setTimeout(hideURLbar, 0); }, false); function hideURLbar(){ window.scrollTo(0,1); } </script>

		
</head>

<body>
	<?php
	session_start();
    if(empty($_SESSION['t_name']))
    {
        header("Location:/index.html");
        exit();
    }
    echo "欢迎您".$_SESSION['t_name']."，请您上传学生的csv文件，只能两列分别为姓名和性别";
    ?>
<div class="agile-its">
	<h2>上传文件</h2>
	<div class="w3layouts">
	<p>文件上传页面，请您点击选择或者拖动学生名单的CSV（UTF-8编码）学生文件</p>
		<div class="photos-upload-view">
			<form id="upload" action="process.php" method="POST" enctype="multipart/form-data">
				<input type="hidden" id="MAX_FILE_SIZE" name="file" value="300000" />
					<div class="agileinfo">
					<input type="submit" class="choose" value="选择文件">
					<h3>或</h3>
						<input type="file" id="fileselect" name="file" multiple="multiple" />
						<div id="filedrag">拖拽文件到这里</div>
					</div>
				    <select name="renshu">
                      <option value =4 >4人间</option>
                      <option value =6 >6人间</option>
                    </select>
				    <input type="submit" class="choose" value="上传">
			</form>
			<div id="messages">
	
			</div>
		</div>
		<div class="clearfix"></div>
		<script src="js/filedrag.js"></script>


		</div>
</div>
<script type="text/javascript" src="js/jquery.min.js"></script>


</body>
</html>