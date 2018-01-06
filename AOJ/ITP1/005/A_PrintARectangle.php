<?php
while (true) {
  list($h, $w) = explode(" ", trim(fgets(STDIN)));
  if (!$h) break;

  for ($i = 0; $i < $h; $i++) {
    for ($j = 0; $j < $w; $j++) echo "#";
    echo "\n";
  }

  echo "\n";
}
