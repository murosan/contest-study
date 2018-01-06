<?php
list($n, $m, $l) = explode(" ", trim(fgets(STDIN)));
$a = array();
$b = array();
$c = array();

for ($i = 0; $i < $n; $i++) $a[$i] = explode(" ", trim(fgets(STDIN)));
for ($i = 0; $i < $m; $i++) $b[$i] = explode(" ", trim(fgets(STDIN)));
for ($i = 0; $i < $n; $i++)
  for ($j = 0; $j < $l; $j++)
    $c[$i][$j] = 0;

for ($i = 0; $i < $n; $i++)
  for ($j = 0; $j < $l; $j++)
    for ($k = 0; $k < $m; $k++)
      $c[$i][$j] += $a[$i][$k] * $b[$k][$j];

$out = array();
for ($i = 0; $i < $n; $i++)
  array_push($out, implode(" ", $c[$i]));

echo implode("\n", $out) . "\n";
