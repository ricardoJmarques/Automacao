<?php
    session_start();
  	if ($_SESSION['logged']!=1)
	    die ("Sessão não iniciada.");
	 
	 $ID = $_POST['ID'];
	 
	 $q = 'DELETE FROM agenda WHERE id ='.$ID;
	 $db = new PDO("sqlite:db/automacao.sqlite");
	 $db->query($q);	
     print("Tarefa removida com sucesso.");
	 exit;
?>