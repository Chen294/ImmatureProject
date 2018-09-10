<!doctype html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>大学生意向室友调查问卷</title>
	<link rel="stylesheet" href="../css/index_student.css">

</head>

<body>
	<?php
	session_start();
    if(empty($_SESSION['t_name']))
    {
        header("Location:/index.html");
        exit();
    }
    echo "你好".$_SESSION['s_name'];
    ?>
	
<div class="quanju" id="div0">
  <h1 class="biaoti">&nbsp; </h1>
  <h1 class="biaoti">大学生生活方式调查</h1>
<div class="daoyu" id="div1">亲爱的同学们：<br>
&nbsp; &nbsp; &nbsp;&nbsp; 你们好！<br>
&nbsp; &nbsp; &nbsp; &nbsp;我们是四川大学计科院“寝室问卷调查分配系统”项目成员。宿舍是我们大学生学习和生活的一个重要场所，但是大家都有自己独特的个性和生活方式。希望同学们能抽出几分钟时间认真做完这份调查问卷，我们会根据问卷的作答为你找到最合适的室友。<br>
&nbsp; &nbsp; &nbsp;&nbsp;感谢你们的支持与协助。</div>
&nbsp; &nbsp;&nbsp; &nbsp;&nbsp; &nbsp;&nbsp; &nbsp;
  <br />
<div class="div_question" id="div1">
    <form action="dispose.php" method="post">
   
    <div class="div_title_question" id="divTitle1">  1.你的平均睡觉时间  </div>
    <div style="clear: both;">  </div>
    <p>
      <label>
        <input type="radio" name="shuijiao" value="1" id="shuijiao_0" />
        22:30以前</label>
      &nbsp;
      <label>
        <input type="radio" name="shuijiao" value="2" id="shuijiao_1" />
        22:30-23:00</label>
      &nbsp;
      <label>
        <input type="radio" name="shuijiao" value="3" id="shuijiao_2" />
        23:00-23:30</label>
      &nbsp;
      <label>
        <input type="radio" name="shuijiao" value="4" id="shuijiao_3" />
        23:30以后</label>
      </p>
    <p><br />
    </p>
    <div class="div_title_question" id="divTitle1">  2.你的平均起床时间  </div>
    <div style="clear: both;">  </div>
        <p>
          <label>
            <input type="radio" name="qichuang" value="1" id="qichuang_0" />
            6:30以前</label>
          &nbsp;
          <label>
            <input type="radio" name="qichuang" value="2" id="qichuang_1" />
            6:30-7:00</label>
          &nbsp;
          <label>
            <input type="radio" name="qichuang" value="3" id="qichuang_2" />
            7:00-7:30</label>
          &nbsp;
          <label>
            <input type="radio" name="qichuang" value="4" id="qichuang_3" />
            7:30以后</label>
        </p>
        <p><br />
        </p>
      <div class="div_title_question" id="divTitle1">  3.请问你对未来的计划  </div>
    <div style="clear: both;">  </div>
    <p>
      <label>
        <input type="radio" name="guihua" value="1" id="guihua_0" />
        读研、出国</label>
      &nbsp;
      <label>
        <input type="radio" name="guihua" value="2" id="guihua_1" />
        能有个好工作</label>
      &nbsp;
      <label>
        <input type="radio" name="guihua" value="3" id="guihua_2" />
        还没想好</label>
      &nbsp;</p>
    <p><br />
      
    </p>
    <div class="div_title_question" id="divTitle1">  4.你打扫房间的频率  </div>
    <div style="clear: both;">  </div>
    <p>
      <label>
        <input type="radio" name="dsws" value="1" id="dsws_0" />
        经常</label>
      &nbsp;
      <label>
        <input type="radio" name="dsws" value="2" id="dsws_1" />
        偶尔</label>
      &nbsp;
      <label>
        <input type="radio" name="dsws" value="3" id="dsws_2" />
        几乎不      
        <br />
        <br />
        <br />
      </label>
    </p>
    <div class="div_title_question" id="divTitle1">  5.你一般换/洗一次衣服的频率  </div>
    <div style="clear: both;">  </div>
    <p>
    <label>
      <input type="radio" name="xyf" value="1" id="xyf_0" />
      经常</label>
    &nbsp;
    <label>
      <input type="radio" name="xyf" value="2" id="xyf_1" />
      偶尔</label>
    &nbsp;
    <label>
      <input type="radio" name="xyf" value="3" id="xyf_2" />
      很少
      <br />
      <br />
      <br />
    </label>
    </p>
    
    
      
    <div class="div_title_question" id="divTitle1">  6.你洗澡/洗头的频率</div>
    <div style="clear: both;">  </div>
    <p>
    <label>
      <input type="radio" name="xzxt" value="1" id="xzxt_0" />
      每天</label>
    &nbsp;
    <label>
      <input type="radio" name="xzxt" value="2" id="xzxt_1" />
      隔1-2天</label>
    &nbsp;
    <label>
      <input type="radio" name="xzxt" value="3" id="xzxt_2" />
      隔3天以上<br />
      <br />
      <br /></label>
    </p>
    
    
    <div class="div_title_question" id="divTitle1">  7.你叠被子的频率  </div>
    <div style="clear: both;">  </div>
    <p>
    <label>
      <input type="radio" name="dbz" value="1" id="dbz_0" />
      每天都叠</label>
    &nbsp;
    <label>
      <input type="radio" name="dbz" value="2" id="dbz_1" />
      偶尔</label>
    &nbsp;
    <label>
      <input type="radio" name="dbz" value="3" id="dbz_2" />
      几乎不<br />
      <br />
      <br /></label>
      </p>
    
    
    
    <div class="div_title_question" id="divTitle1">  8.你每天清洁面部/口腔吗  </div>
    <div style="clear: both;">  </div>
    <p>
    <label>
      <input type="radio" name="sy" value="1" id="sy_0" />
      2次及以上</label>
    &nbsp;
    <label>
      <input type="radio" name="sy" value="2" id="sy_1" />
      2次以下</label>
    &nbsp;
    <label>
      <input type="radio" name="sy" value="3" id="sy_2" />
      不经常<br />
      <br />
      <br /></label>
    </p>
    
    
    <div class="div_title_question" id="divTitle1">  9.喜欢二次元？  </div>
    <div style="clear: both;">  </div>
    <p>
    <label>
      <input type="radio" name="ecy" value="1" id="chouyan_0" />
      是</label>
    &nbsp;
    <label>
      <input type="radio" name="ecy" value="2" id="chouyan_1" />
      否<br />
      <br />
      <br /></label>
    </p>
    
    
    <div class="div_title_question" id="divTitle1">  10.你有抽烟的习惯吗  </div>
    <div style="clear: both;">  </div>
    <p>
    <label>
      <input type="radio" name="chouyan" value="1" id="chouyan_0" />
      是</label>
    &nbsp;
    <label>
      <input type="radio" name="chouyan" value="2" id="chouyan_1" />
      否<br />
      <br />
      <br /></label>
    </p>
    
    
    
    
    
    
    <div class="div_title_question" id="divTitle1">  11.你会在寝室和(男)女朋友视频聊天吗  </div>
    <div style="clear: both;">  </div>
    <p>
    <label>
      <input type="radio" name="lt" value="1" id="lt_0" />
      是</label>
    &nbsp;
    <label>
      <input type="radio" name="lt" value="2" id="lt_1" />
      否<br />
      <br />
      <br /></label>
    </p>
    
    
    <div class="div_title_question" id="divTitle1">  12.你积极参加各种活动吗  </div>
    <div style="clear: both;">  </div>
    <p>
    <label>
      <input type="radio" name="hd" value="1" id="hd_0" />
      是</label>
    &nbsp;
    <label>
      <input type="radio" name="hd" value="2" id="hd_1" />
      否<br />
      
      <br />
      <br />
      <br /></label>
      </p>
      
<div class="div_title_question" id="divTitle1">  13.喜欢玩游戏吗  </div>
    <div style="clear: both;">  </div>
    <p>
    <label>
      <input type="radio" name="youxi" value="1" id="youxi_0" />
      经常玩</label>
    &nbsp;
    <label>
      <input type="radio" name="youxi" value="2" id="youxi_1" />
      不怎么玩<br />
      <br />
      <br /></label>
    </p>
    
<div class="div_title_question" id="divTitle1">  14.有午睡的习惯吗  </div>
    <div style="clear: both;">  </div>
    <p>
    <label>
      <input type="radio" name="wushui" value="1" id="wushui_0" />
      比较规律</label>
    &nbsp;
    <label>
      <input type="radio" name="wushui" value="2" id="wushui_1" />
      几乎没有<br />
      <br />
      <br /></label>
    </p>
    
    <div class="div_title_question" id="divTitle1">  15.你经常参加运动吗  </div>
    <div style="clear: both;">  </div>
    <p>
    <label>
      <input type="radio" name="yundong" value="1" id="yundong_0" />
      较多参加</label>
    &nbsp;
    <label>
      <input type="radio" name="yundong" value="2" id="yundong_1" />
      几乎不<br />
      <br />
      <br /></label>
    </p>
    <input type="submit" name="button" id="button" value="提交" />
    </form>
 
</div>
</div>   
    
    
    
    
    
    
    

</body>
</html>
