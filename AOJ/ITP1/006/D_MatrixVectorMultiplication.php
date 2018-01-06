<?php
list($n, $m) = explode(" ", trim(fgets(STDIN)));

$a = array();
$b = array();

for ($i = 0; $i < $n; $i++)
  $a[$i] = explode(" ", trim(fgets(STDIN)));

for ($i = 0; $i < $m; $i++)
  $b[$i] = trim(fgets(STDIN));

for ($i = 0; $i < $n; $i++) {
  $c = 0;
  for ($j = 0; $j < $m; $j++)
    $c += ($a[$i][$j] * $b[$j]);
  echo "$c\n";
}
