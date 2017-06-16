<?php
	session_start();
	if ($_SESSION['logged']!=1)
	   die ("Sessão não iniciada.");
	$portao = $_POST['portao'];
	$comando = 'portao '.$portao;
	exec($comando);
	print "Comando executado com exito.";
?>