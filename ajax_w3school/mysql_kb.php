
<?php
if ($_SERVER["REQUEST_METHOD"] == "GET") {
    $con = mysql_connect("localhost","denghaijun","dhj123");
    if (!$con)
    {
        die('Could not connect: ' . mysql_error());
    } else {
        mysql_select_db("mysql_kb", $con);
        $ret="";
        $result = mysql_query("SELECT * FROM ACTIONS");
        $result_num = mysql_num_rows($result);
        if ($result_num>0)
        {
            $ret.="Actions: ";
            //echo "result_num = $result_num";
            $rowId=0;
            while($row = mysql_fetch_array($result))
            {
                if($rowId==0)
                    $ret .= $row['A_NAME'];
                else
                    $ret .= "," . $row['A_NAME'];
                $rowId+=1;
            }
        }
        $ret .= ";";
        $result = mysql_query("SELECT * FROM OBJECTS");
        $result_num = count($result);
        if ($result_num>0)
        {
            $ret.="OBJECTS:";
            $rowId=0;
            while($row = mysql_fetch_array($result))
            {
                if($rowId==0)
                    $ret .= $row['O_NAME'];
                else
                    $ret .= "," . $row['O_NAME'];
                $rowId+=1;
            }
        }
        $ret .= ";";
        $result = mysql_query("SELECT * FROM commands");
        $result_num = count($result);
        if ($result_num>0)
        {
            $ret.="commands:";
            $rowId=0;
            while($row = mysql_fetch_array($result))
            {
                if($rowId==0)
                    $ret .= $row['C_NAME'];
                else
                    $ret .= "," . $row['C_NAME'];
                $rowId+=1;
            }
        }
        mysql_close($con);

        echo $ret;
    }
}
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $firstName="";
    $lastName="";
    if (isset($_POST['fname'])) {
        $firstName = $_POST['fname'];             // get data
    }
    if (isset($_POST['lname'])) {
        $lastName = $_POST['lname'];             // get data
    }
    echo "welcome ".$firstName." ".$lastName;
}
?>
