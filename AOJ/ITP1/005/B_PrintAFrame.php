<?php
while (true) {
  list($h, $w) = explode(" ", trim(fgets(STDIN)));
  if (!$h) break;

  for ($i = 1; $i <= $h; $i++) {
    for ($j = 1; $j <= $w; $j++) {
      if ($i == 1 || $i == $h || $j == 1 || $j == $w) echo "#";
      else echo ".";
    }
    echo "\n";
  }

  echo "\n";
}
