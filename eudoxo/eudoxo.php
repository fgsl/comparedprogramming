<?php
/**
 * PHP implementation of Eudoxo Algorithm for square root
 * @author Flávio Gomes da Silva Lisboa <flavio.lisboa@fgsl.eti.br>
 **/
if ($argc<3){
	echo "\nType: php eudoxo.php [number to extract root square] [number of iterations]\n";
	exit;
}

$p = $argv[1]; // square
$n = $argv[2]; // iterations

$start = microtime(true);

$x = ((1 + $p)/2);

echo "\n n=0; x=$x\n";

for ($i=1;$i<$n;$i++){
	$x = ((($p/$x) + $x)/2);
	echo "\n n=$i; x=$x; x^2=" . ($x * $x) . "\n";
}	

$elapsedtime = microtime(true) - $start;

echo "\nElapsed time: " . round($elapsedtime/1000,4) . "ms\n";

echo "\nValue of language function:" . sqrt($p) . "\n"; 

