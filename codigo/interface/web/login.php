<?php
	$myusername = $_POST['username'];
    $mypassword = $_POST['password'];
	$q = 'SELECT * FROM users;'; // WHERE username="'. $myusername .'" AND password="'. $mypassword .'";';
	$db = new PDO("sqlite:db/automacao.sqlite");
	foreach ($db->query($q) as $row){
			if ($row['username'] != $myusername)
	   		   echo "Username incorrecto";
			else {
				 if ($row['password'] != $mypassword)
			   	 	echo "Password incorrecta";
				 else {
			   	 	  echo "Login com sucesso";
			   		  session_start();
					  $_SESSION['logged']=1;
			 	 }
			}
	}
?>
