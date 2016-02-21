<!DOCTYPE HTML> 
<html>
<head>
<style>
.error {color: #FF0000;}
</style>
</head>
<body> 

<?php
$nameErr = $emailErr = $genderErr = $websiteErr = "";
$name = $email = $gender = $comment = $website = "";

function test_input($data) {
   $data = trim($data);
   $data = stripslashes($data);
   $data = htmlspecialchars($data);
   return $data;
}
   if (empty($_POST["name"])) {
     $nameErr = "name is needed";
     echo "<h2>$nameErr</h2>";
   } else {
     $name = test_input($_POST["name"]);
   }
   
   if (empty($_POST["email"])) {
     $emailErr = "email is needed";
     echo "<h2>$emailErr</h2>";
   } else {
     $email = test_input($_POST["email"]);
   }
     
   if (empty($_POST["website"])) {
     $website = "";
   } else {
     $website = test_input($_POST["website"]);
   }

   if (empty($_POST["comment"])) {
     $comment = "";
   } else {
     $comment = test_input($_POST["comment"]);
   }

   if (empty($_POST["gender"])) {
     $genderErr = "gender is needed";
      echo "<h2>$genderErr</h2>";
   } else {
     $gender = test_input($_POST["gender"]);
   }
   
   if (!empty($nameErr)) {
      echo "<h2>$nameError</h2>";
   } elseif (!empty($emailErr)) {
      echo "<h2>$emailError</h2>";
   } elseif (! empty($genderErr)) {
      echo "<h2>$genderError</h2>";
   } else {
      echo "<h2>Your inputs: </h2>";
      echo $name;
      echo "<br>";
      echo $email;
      echo "<br>";
      echo $website;
      echo "<br>";
      echo $comment;
      echo "<br>";
      echo $gender;
  }
?>

</body>
</html>
