<?php
list($r, $c) = explode(" ", trim(fgets(STDIN)));
$sheet = array();

for ($i = 0; $i < $r; $i++)
  $sheet[$i] = explode(" ", trim(fgets(STDIN)));

for ($i = 0; $i < $c; $i++) {
  $sum = 0;
  for ($j = 0; $j < $r; $j++) $sum += $sheet[$j][$i];
  $sheet[$r][$i] = $sum;
}

for ($i = 0; $i <= $r; $i++) {
  $sum = array_sum($sheet[$i]);
  echo implode(" ", $sheet[$i]) . " $sum\n";
}
