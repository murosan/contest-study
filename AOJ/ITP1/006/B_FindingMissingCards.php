<?php
$n = trim(fgets(STDIN));
$arr = array();

for ($i = 0; $i < $n; $i++) {
  list($pic, $num) = explode(" ", trim(fgets(STDIN)));
  $arr[$pic][$num] = true;
}

for ($i = 1; $i <= 13; $i++)
  if (!isset($arr["S"][$i])) echo "S $i\n";
for ($i = 1; $i <= 13; $i++)
  if (!isset($arr["H"][$i])) echo "H $i\n";
for ($i = 1; $i <= 13; $i++)
  if (!isset($arr["C"][$i])) echo "C $i\n";
for ($i = 1; $i <= 13; $i++)
  if (!isset($arr["D"][$i])) echo "D $i\n";
