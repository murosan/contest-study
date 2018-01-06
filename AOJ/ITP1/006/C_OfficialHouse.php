<?php
$n = trim(fgets(STDIN));
$arr = array();

for ($i = 1; $i <= 4; $i++)
  for ($j = 1; $j <= 3; $j++)
    for ($k = 1; $k <= 10; $k++)
      $arr[$i][$j][$k] = 0;

for ($i = 0; $i < $n; $i++) {
  list($b, $f, $r, $v) = explode(" ", trim(fgets(STDIN)));
  $arr[$b][$f][$r] += $v;
}

for ($i = 1; $i <= 4; $i++) {
  for ($j = 1; $j <= 3; $j++) {
    for ($k = 1; $k <= 10; $k++) echo " " . $arr[$i][$j][$k];
    echo "\n";
  }
  if ($i != 4) echo "####################\n";
}
