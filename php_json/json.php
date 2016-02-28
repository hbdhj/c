<?php
header("Access-Control-Allow-Origin: *");
header("Content-Type: application/json; charset=UTF-8");

$conn = new mysqli("localhost", "denghaijun", "dhj123", "mysql_kb");

$result = $conn->query("SELECT A_NAME FROM actions");

$outp = '{"actions":[';
while($rs = $result->fetch_array(MYSQLI_ASSOC)) {
    #if ($outp != "[") {$outp .= ",";}
    $outp .= '{"Name":"'  . $rs["A_NAME"] . '"},';
}
$outp .="]}";

$conn->close();

echo($outp);
?>
