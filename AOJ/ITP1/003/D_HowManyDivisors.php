<?php
list($a, $b, $c) = explode(" ", trim(fgets(STDIN)));

$count = 0;
for (; $a <= $b; $a++) {
  if ($c % $a == 0) $count++;
}

echo "$count\n";
