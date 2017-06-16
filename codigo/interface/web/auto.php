<?php
	session_start();
	if ($_SESSION['logged']!=1)
	   die ("Sessão não iniciada.");
	$funcao = $_POST['funcao'];
	$comando = 'autoaudi '.$funcao;
	exec($comando);
	print "Comando executado com exito.";
?>