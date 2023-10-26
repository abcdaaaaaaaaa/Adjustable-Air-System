<?php
$servername = "localhost";
$dbname = "uzayinfo_spacesystem";
$username = "uzayinfo_spaceuser";
$password = "space2500";

        $conn = new mysqli($servername, $username, $password, $dbname);

        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        } 
?>
