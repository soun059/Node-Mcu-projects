<?php

$con=mysqli_connect("localhost","root","");
if(!$con)
{
echo 'not connected to server';
}
if(!mysqli_select_db($con,"details"))
{
echo 'connection to database failed';
}
$name=$_GET["name"];
$roll=$_GET["roll"];
$sql="INSERT INTO newtable(name,roll) values('$name','$roll')";
if(!mysqli_query($con,$sql))
{
	echo 'Not inserted'.mysqli_error($con);
}
else
	echo 'inserted';

?>