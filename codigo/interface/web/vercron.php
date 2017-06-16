<?php
	session_start();
	$q = 'SELECT * FROM agenda;';
	$db = new PDO("sqlite:db/automacao.sqlite");
	print ("<table width=100% border=1 cellpadding=0 cellspacing=0>");
	print ("<tr>");
	print ("<td align=center>ID</td><td align=center>Mes</td><td align=center>Semana</td><td align=center>Dia</td><td align=center>Hora</td><td align=center>Minuto</td><td align=center>Segundo</td><td align=center>Canal</td><td align=center>Numero</td><td align=center>Grupo</td><td align=center>Função</td>");
	print ("</tr>");
	foreach ($db->query($q) as $row){
		print ("<tr>");
		print ("<td>".$row['id']."</td><td>".$row['mes']."</td><td>".$row['semana']."</td><td>".$row['dia']."</td><td>".$row['hora']."</td><td>".$row['minuto']."</td><td>".$row['segundo']."</td><td>".$row['canal']."</td><td>".$row['numero']."</td><td>".$row['grupo']."</td><td>".$row['funcao']."</td>");
		print ("</tr>");
	}
	print ("</table>");
	exit;
?>

