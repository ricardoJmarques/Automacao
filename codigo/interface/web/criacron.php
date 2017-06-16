<?php
	session_start();
	if ($_SESSION['logged']!=1)
	   die ("Sessão não iniciada.");
	$ficheiro = "cron/automacao";
	$ficheiroOpen = fopen($ficheiro, 'wb') or die("can't open file");
	$q = 'SELECT * FROM agenda;';
	$db = new PDO("sqlite:db/automacao.sqlite") or die("can't open db");
	foreach ($db->query($q) as $row){
		$linha = $row['minuto']." ".$row['hora']." ".$row['dia']." ".$row['mes']." ".$row['semana']." sleep ".$row['segundo']." ; /usr/bin/automacao ".$row['canal']." ".$row['numero']." ".$row['grupo']." ".$row['funcao'];
		fwrite($ficheiroOpen, $linha);
		fwrite($ficheiroOpen, "\n");
	}
	fclose($ficheiroOpen);
	exec('crontab /var/www/cron/automacao');
	print "Agenda criada com Exito";
?>