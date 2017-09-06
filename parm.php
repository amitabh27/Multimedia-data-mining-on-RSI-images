<!DOCTYPE html>
<html lang="en">
    
    <head>
        <meta charset=utf-8>
        <!--<meta name="viewport" content="width=device-width, initial-scale=1.0">-->
        <title>Peano Count Tree Association Rule Mining</</title>
        <link href='http://fonts.googleapis.com/css?family=Roboto:400,300,700&amp;subset=latin,latin-ext' rel='stylesheet' type='text/css'>
        <link rel="stylesheet" type="text/css" href="css/bootstrap.css" />
        <link rel="stylesheet" type="text/css" href="css/bootstrap-responsive.css" />
        <link rel="stylesheet" type="text/css" href="css/style.css" />
        <link rel="stylesheet" type="text/css" href="css/pluton.css" />
        <link rel="stylesheet" type="text/css" href="css/jquery.cslider.css" />
        <link rel="stylesheet" type="text/css" href="css/jquery.bxslider.css" />
        <link rel="stylesheet" type="text/css" href="css/animate.css" />
    </head>
    
    <body>
        <div class="navbar">
            <div class="navbar-inner">
                <div class="container">
                       <!--<img src="uploads/geo1.jpg" width="120" height="40" alt="Logo">-->
                    <div class="nav-collapse collapse pull-right">
                        <ul class="nav" id="top-navigation">
                            <li class="active"><a href="#home">Home</a></li>
		            <li><a href="#services">Services</a> </li> 
                            <li><a href="#aboutus">About us</a></li>
			    <li><a href="#contact">Contact</a></li>
                        </ul>
                    </div>
                </div>
            </div>
        </div>
        <div id="home">
            <div id="da-slider" class="da-slider">
                <div class="triangle"></div>
                <div class="mask"></div>
                <div class="container">
                    <!-- Start first slide -->
                    <div class="da-slide">
                        <h2 class="fittext2">Peano Count Tree Association Rule Mining</h2>
                        <h4>Fast and Accurate</h4>
                       <p>PARM takes two images as input.One is the Contributing Factor(say rainfall) towards the success of an event(say yield) and then it finds the rules using which we can predict the success of the same event in a totally different geographical region.</p>
                        
                    </div>
                    <!-- End first slide -->
                    <!-- Start second slide -->
                    <div class="da-slide">
                        <h2>Parallelisation</h2>
                        <h4>Speed Up and Efficiency</h4>
                        <p>We have parallelised several prominent data mining algorithms like Apriori,Bayesian,Knn,NN,K-means etc</p>
                    </div>
                    <!-- End second slide -->
                    <!-- Start third slide -->
                    <div class="da-slide">
                        <h2>Serialisation</h2>
                        <h4>Stand alone machine codes</h4>
                        <p>Codes have been drafted in C with a generalised approach.</p>
                    </div>
                    <!-- End third slide -->
                </div>
            </div>
        </div>
        <!-- End home section -->

	 <!-- Services section start -->

        <div class="section primary-section" id="services">
            <div class="container">
                <!-- Start title section -->
                <div class="title"><br>
                    <h1>RESEARCH ARENA</h1>
                </div>
                
		


<p align="center"> <form action="#services" method="post" enctype="multipart/form-data">
    <b>Select image to upload:<br></p></b>
    <p align="center"><input type="file" name="fileToUpload1" id="fileToUpload1"></p>
    <p align="center"><input type="file" name="fileToUpload2" id="fileToUpload2">  </p>
    <p align="center"><input type="file" name="fileToUpload3" id="fileToUpload3"></p>
    <p align="center"><select name="f3" size="1">
		<option selected value="none">Type of Mapping</option>
		<option  value="rgb">RGB to RGB</option>
		<option  value="grey">RGB to Grey</option></select></p>
    
   <p align="center"><input type="submit" value="Upload Images" name="submit"></p><br>
    
</form>

<?php



// Check if image file is a actual image or fake image

/*$f1="",$f2="",$f3="",$f4="",$f5="",$f6="",$f7="",$f8="",$f9="";*/
$f111="1";
$m1="";
$m2="";
$m3="";
$m4="";
$m5="";
$m6="";
$m7="";
$m8="";
$filename11="";
$filename22="";
$filename33="";
$flag=1;

$value="";

	if(isset($_POST["submit"]))
	{
	$filename11 = pathinfo($_FILES['fileToUpload1']['name'], PATHINFO_FILENAME);
	$filename22 = pathinfo($_FILES['fileToUpload2']['name'], PATHINFO_FILENAME);
	$filename33 = pathinfo($_FILES['fileToUpload3']['name'], PATHINFO_FILENAME);

		if($filename11=="" || $filename22=="" || $filename33=="")
		{

		$m1="Select the files to be uploaded.";
		}
		else
		{

		$value=$_POST['f3'];
			if($value=="none")
				{
				echo "Select the type of mapping.";
				$flag=0;
				}
		$target_dir = "uploads/";

		$target_file1 = $target_dir . basename($_FILES["fileToUpload1"]["name"]);
		$target_file2 = $target_dir . basename($_FILES["fileToUpload2"]["name"]);
		$target_file3 = $target_dir . basename($_FILES["fileToUpload3"]["name"]);

		$uploadOk = 1;

		$imageFileType1 = pathinfo($target_file1,PATHINFO_EXTENSION);
		$imageFileType2 = pathinfo($target_file2,PATHINFO_EXTENSION);
		$imageFileType3 = pathinfo($target_file3,PATHINFO_EXTENSION);

		$check1 = getimagesize($_FILES["fileToUpload1"]["tmp_name"]);
		$check2 = getimagesize($_FILES["fileToUpload2"]["tmp_name"]);
		$check3 = getimagesize($_FILES["fileToUpload3"]["tmp_name"]);

			if($check1 !== false && $check2 !== false && $check3 !== false) 
			{
			$uploadOk = 1;
			} 
			else 
			{
			$m2="File is not an image.";
			$uploadOk = 0;
			}


// Check file size
			if($_FILES["fileToUpload1"]["size"] > 500000 || $_FILES["fileToUpload2"]["size"] > 500000  || $_FILES["fileToUpload3"]["size"] > 500000 ) 
			{
			$m3="Your file is too large.";
			$uploadOk = 0;
			}



// Allow certain file formats
			if(($imageFileType1 != "jpg" && $imageFileType1 != "png" && $imageFileType1 != "jpeg"
&& $imageFileType1 != "gif") && ($imageFileType2 != "jpg" && $imageFileType2 != "png" && $imageFileType2 != "jpeg"
&& $imageFileType2 != "gif") && ($imageFileType3 != "jpg" && $imageFileType3 != "png" && $imageFileType3 != "jpeg"
&& $imageFileType3 != "gif") )
			{
			$m4="Only JPG, JPEG, PNG & GIF files are allowed.";
			$uploadOk = 0;
			}


//Images must be of same dimensions.
		$image_info1 = getimagesize($_FILES["fileToUpload1"]["tmp_name"]);
		$image_width1 = $image_info1[0];
		$image_height1 = $image_info1[1];
		$image_info2 = getimagesize($_FILES["fileToUpload2"]["tmp_name"]);
		$image_width2 = $image_info2[0];
		$image_height2 = $image_info2[1];
		$image_info3 = getimagesize($_FILES["fileToUpload3"]["tmp_name"]);
		$image_width3 = $image_info3[0];
		$image_height3 = $image_info3[1];

		$fake=0;

			if( ($image_width1==$image_width2 && $image_width1==$image_width3 && $image_width2==$image_width3) && ($image_height1==$image_height2 && $image_height1==$image_height3 && $image_height2==$image_height3))
$fake=1;
			else
			{
			$m5="All the images must be of same dimensions.";
			$uploadOk=0;
			}

//checking whether he has uploaded the same image more than once.

			if( ($filename11==$filename22) || ($filename11==$filename33) || ($filename22==$filename33) )
			{
			$uploadOk=0;
			$m6="Attempt to upload same file more than once was traced.";
			}


// Check if $uploadOk is set to 0 by an error
			if ($uploadOk == 0 || $flag==0)
			{
			$m7="Sorry, your file was not uploaded.";
			} 
			else
			{
				if (move_uploaded_file($_FILES["fileToUpload1"]["tmp_name"], $target_file1)) 
				{
					if (move_uploaded_file($_FILES["fileToUpload2"]["tmp_name"], $target_file2)) 
					{
						if (move_uploaded_file($_FILES["fileToUpload3"]["tmp_name"], $target_file3)) 
						{
						echo "The files have been successfully uploaded."."<br>";
						rename("uploads/$filename11.jpg","uploads/geo1.jpg");
						rename("uploads/$filename22.jpg","uploads/geo2.jpg");
						rename("uploads/$filename33.jpg","uploads/geo3.jpg");
							if($value=="grey")
							{
							$output1=shell_exec('java parm1');
							$output2=shell_exec('/opt/lampp/htdocs/parm2');
							$output3=shell_exec('/opt/lampp/htdocs/parm3');
							$output4=shell_exec('java parm4');
							$output5=shell_exec('java parm55');
							$output5=shell_exec('java parm66');
							}
							if($value=="rgb")
							{
							$output1=shell_exec('java parm11');
							$output2=shell_exec('/opt/lampp/htdocs/parm22');
							$output3=shell_exec('/opt/lampp/htdocs/parm33');
							$output4=shell_exec('java parm44');
							}
						echo "Predicted image:";
	//sleep(4);
					?>
	<img src="uploads/generated_image1.jpg" alt="output">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
	<img src="uploads/generated_image2.jpg" alt="output">
	
					<?php
					}
					else 
					{
       					 echo "Sorry, there was an error uploading your file.";
					}
			}
			else 
			{
        		echo "Sorry, there was an error uploading your file.";
			}
    	} 
	else 
	{
        echo "Sorry, there was an error uploading your file.";
	}
}


}
//else
}

echo " " . "$m8" . " $m1" . " $m2" . " $m3" . " $m4" . " $m5" .  " $m6" .  " $m7";
?>

</div>
</div>
        <!-- Services section end -->
       <!-- About us section start -->
        <div class="section primary-section" id="aboutus">
            <div class="container">
                <!-- Start title section -->
                <div class="title">
                    <h1>What We Do?</h1>
                    <!-- Section's title goes here -->
                    <p>PARM <br> Peano count Association rule mining</p>
                    <!--Simple description for section goes here. -->
                </div>
                <div class="row-fluid">
                    <div class="span4">
                        <div class="centered service">
                            
			    <h3>Spatial data</h3>
                            <p>We create association rules from images<br> More data <br>=> Higher accuracy <br>=> Better rules</p>
                        </div>
                    </div>
                    <div class="span4">
                        <div class="centered service">

                            <h3>Powerfull processing</h3>
                            <p>In spatial image processing we require high computing power</p>
                        </div>
                    </div>
                    <div class="span4">
                        <div class="centered service">
                            
                            <h3>Clean Code</h3>
                            <p>A joint venture wherein clean code and high computing merge to give quick association rule discovery in RSI imagery</p>
                        </div>
                    </div>
                </div>
	<br>
	<br>
	<br>
	<br>
	<p align="center">
	RSI images involve a large amount of data. Processing such data requires more computing speed and an efficient algorithm. Here we use an efficient association rule mining algorithm called PARM. This algorithm creates an intermediate representaion of images known as p-trees and prunes them efficiently in order to generate the rules in RSI images.
	</p>
            </div>
        </div>
        <!-- About us section end -->
       <!-- Contact section start -->
        <div id="contact" class="contact">
            <div class="section secondary-section">
                <div class="container">
                    <div class="title">
                        <h1>Contact Us</h1>
                        </div>
                </div>
                <div class="container">
                    <div class="span9 center contact-info">
                        <p>Fr.Conceicao Rodrigues Institute of Technology, Vashi</p>
			<p> Akshat Bansal </p>                        
			<p class="info-mail">aksnitu@gmail.com</p>
                        <p>+91 810 871 8480</p>
			<p> Jay Sheth
                        <p class="info-mail">jaymscricket16@gmail.com</p>
			<p>+91 992 020 5663</p>
			<p> Amitabh Tiwari </p>
                        <p class="info-mail">amitabh.tiwari27@gmail.com</p>			
			<p>+91 996 983 3570</p>
                    </div>
                </div>
            </div>
        </div>
        <!-- Contact section ends --> 
                    
        
       <!-- Footer section start -->
        <div class="footer">
            <p>&copy; 2015 All Rights Reserved,PARM</p>
        </div>
        <!-- Footer section end -->
        <!-- ScrollUp button start -->
        <div class="scrollup">
            <a href="#">
                <i class="icon-up-open"></i>
            </a>
        </div>
        <!-- ScrollUp button end -->
        <!-- Include javascript -->
        <script src="js/jquery.js"></script>
        <script type="text/javascript" src="js/jquery.mixitup.js"></script>
        <script type="text/javascript" src="js/bootstrap.js"></script>
        <script type="text/javascript" src="js/modernizr.custom.js"></script>
        <script type="text/javascript" src="js/jquery.bxslider.js"></script>
        <script type="text/javascript" src="js/jquery.cslider.js"></script>
        <script type="text/javascript" src="js/jquery.placeholder.js"></script>
        <script type="text/javascript" src="js/jquery.inview.js"></script>
        <script type="text/javascript" src="js/app.js"></script>
    </body>
</html>
