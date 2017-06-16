<?php
	session_start();
	if ($_SESSION['logged']!=1)
	   die ("Sessão não iniciada.");
	
	$segundo = $_POST['segundo'];
	$minuto = $_POST['minuto'];
	$hora = $_POST['hora'];
	$dia = $_POST['dia'];
	$semana = "";   
	$mes = "";
	$canal = $_POST['canal'];
	$numero = $_POST['numero'];
	$grupo = $_POST['grupo'];
	$funcao = $_POST['funcao'];
	
switch ($_POST['semana']) {
    case "Todos":
        $semana = "*";
    	break;
    case "Domingo":
        $semana = "0";
        break;
    case "Segunda":
        $semana = "1";
        break;
    case "Terça":
        $semana = "2";
        break;
    case "Quarta":
        $semana = "3";
        break;
    case "Quinta":
        $semana = "4";
        break;
    case "Sexta":
        $semana = "5";
        break;
    case "Sabado":
        $semana = "6";
        break;
}

switch ($_POST['mes']) {
    case "Todos":
        $mes = "*";
        break;
    case "Janeiro":
        $mes = "1";
        break;
    case "Fevereiro":
        $mes = "2";
        break;
    case "Março":
        $mes = "3";
        break;
    case "Abril":
        $mes = "4";
        break;
    case "Maio":
        $mes = "5";
        break;
    case "Junho":
        $mes = "6";
        break;
    case "Julho":
        $mes = "7";
        break;
    case "Agosto":
        $mes = "8";
        break;
    case "Setembro":
        $mes = "9";
        break;
    case "Outubro":
        $mes = "10";
        break;
    case "Novembro":
        $mes = "11";
        break;
    case "Dezembro":
        $mes = "12";
        break;
}

	$q = "INSERT INTO agenda (segundo, minuto, hora, dia, semana, mes, canal, numero, grupo, funcao) VALUES ('".$segundo."', '".$minuto."', '".$hora."', '".$dia."', '".$semana."', '".$mes."', '".$canal."', '".$numero."', '".$grupo."', '".$funcao."');";
	$db = new PDO("sqlite:db/automacao.sqlite");
	$db->query($q);
   
    print("Tarefa adicionada com sucesso.");
    exit;
?>