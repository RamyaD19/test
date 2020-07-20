<html>
<head>
<style>
.error{color:red;}
div.myform {
border-radius: 35px;
  border: 1px solid black;
  background-color: lightblue;
  width: 300px;
 padding:30px 50px 50px 50px;
  margin-left:450px;
margin-top:100px;
}
</style>
</head>
<body bgcolor="FFFFF0">
<?php
$servername = "localhost";
$username = "ramya";
$password = "mdr13418";
$dbname = "login";
$emailErr=$passErr="";
$fname=$pass="";
$conn = new mysqli($servername, $username, $password, $dbname);
if ($conn->connect_error)
   die("Connection failed: " . $conn->connect_error);
$sql ="create table if not exists login1(sno int unsigned auto_increment primary key,name varchar(50), password varchar(20))";
if ($conn->query($sql) == TRUE) { }
else 
    echo "Error creating table: " . $conn->error;
if($_SERVER['REQUEST_METHOD']=="POST")
{
	if(empty($_POST["name"]))
		$emailErr="username is required";
	else
	{
    		if (!filter_var($_POST["name"], FILTER_VALIDATE_EMAIL)) 
   			$emailErr = "Enter valid username"; 
		else
			$fname=$_POST["name"];
	}
	if(empty($_POST["password"]))
		$passErr="password is required";
	else
	{
    		 if(strlen($_POST["password"])<8)
   		 	$passErr = "Enter valid password format"; 
		else
			$pass=$_POST["password"];
	}
	$sql="select * from login1";
	$result=$conn->query($sql);
	$flag=0;
	if($result->num_rows>0)
	{
		while($row=$result->fetch_assoc())
		{
			if($fname==$row["name"])
			{
				$flag=1;
				if($pass==$row['password'])
				{
					echo "Welcome"." ".$fname;
					break;
				}
				else
				{
					echo "Enter valid password";
					break;
				}
				
			}
		}
		if(($flag==0)&&($fname!="")&&($pass!=""))
		{
			$newrow="insert into login1(name,password) values('$fname','$pass')";
			if($conn->query($newrow)==true)
				echo " Your Registraion details:<br>username:".$fname."<br>password:".$pass;
		}
	}
	else
	{
		if(($fname!="")&&($pass!=""))
		{
			$newrow="insert into login1(name,password) values('$fname','$pass')";
			if($conn->query($newrow))
				echo " Your Registraion details:<br>username:".$fname."<br>password:".$pass;
		}
	}	
}
$conn->close();
/*$sql="insert into login1(name,password) values('$name','$password')";
if($conn->query($sql)==true)
	echo "Record created successfully";
else
	echo "Error inserting record:" .$conn->error;
}
echo $row["sno"];
		echo "<br>";
		echo $row["name"];
		echo "<br>";
		echo "ok.<br>";
		echo $row["password"];
if(flag==0)
	$newrow="insert into login1(name,password) values('$name','$password')";
		echo "<br>";
// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error)
   die("Connection failed: " . $conn->connect_error);*/
?>
<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
<div class="myform">
<h2 style="text-align:center">Login</h2>
<b>Username:</b><input type="text" name="name"><br>
<span class="error"><?php echo $emailErr;?></span><br>
<b>Password:</b><input type="password" name="password"><br>
<span class="error"><?php echo $passErr;?></span><br>
<input type="submit" value="Login" name="submit">
<input style="margin-left:15px" type="submit" value="Register" name="submit"</div>
</form>
<!--<body>
<div id="demo">
<p>New text will come here</p>
<button onclick="myfun()">Try it</button>
</div>
<script>
function myfun()
{	alert('htes');
	var xhttp= new XMLHttpRequest();
 alert(xhttp);
	xhttp.onreadystatechange=function(){
		if(this.readyState==4 && this.status==200){
			document.getElementById("demo").innerHTML=this.responseText;}
		};
	xhttp.open("GET", "mytext.txt", true); 
	xhttp.send();
}
</script>-->
</body>
</html>
