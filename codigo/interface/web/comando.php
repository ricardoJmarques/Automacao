<?php
	session_start();
	if ($_SESSION['logged']!=1)
	   die ("Sessão não iniciada.");
	$canal = $_POST['canal'];
	$numero = $_POST['numero'];
	$grupo = $_POST['grupo'];
	$funcao = $_POST['funcao'];
	$comando = 'automacao '.$canal.' '.$numero.' '.$grupo.' '.$funcao;
	exec($comando);
	print "Comando executado com exito.";
?>