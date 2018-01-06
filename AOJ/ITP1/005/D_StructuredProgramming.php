<?php
$n = trim(fgets(STDIN));

for ($i = 1; $i <= $n; $i++) {
  $x = $i;
  if ($x % 3 == 0) {
    echo " $i";
    continue;
  }

  do {
    if ($x % 10 == 3) {
      echo " $i";
      break;
    }
    $x = intval($x / 10);
  } while ($x);
}

echo "\n";
