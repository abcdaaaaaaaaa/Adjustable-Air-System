<?php
$servername = "localhost";
$dbname = "uzayinfo_air";
$username = "uzayinfo_airuser";
$password = "air2500";

        $conn = new mysqli($servername, $username, $password, $dbname);

        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        } 
?>