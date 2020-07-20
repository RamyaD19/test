<html>
<head>
<style>
table,th,td{
	border: 1px solid black;
	border-collapse: collapse;
}
table{margin: 10px;}
th,td{ padding: 5px;}
</style>
<body>
<?php
$servername = "localhost";
$username = "ramya";
$password = "mdr13418";
$dbname = "login";
$conn = new mysqli($servername, $username, $password, $dbname);
if ($conn->connect_error)
	die("Connection failed: " . $conn->connect_error);
$para = $_GET["q"];
$sql = "select $para from login1";
$result = $conn->query($sql);

if ($result->num_rows > 0) 
{
	echo "<table><tr><th>".$para."</th></tr>";
	while($row = $result->fetch_assoc()) 
		echo "<tr><td>". $row[$para] . "</td></tr>";
		//echo $row[$para] . "<br>"
	echo "</table>";
}
else
	echo "Choose name or password";
$conn->close();
?>
</body>
</html>
