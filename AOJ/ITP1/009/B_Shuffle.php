<?php
while (true) {
  $s = trim(fgets(STDIN));
  if ($s == "-") break;
  $m = trim(fgets(STDIN));

  for ($i = 0; $i < $m; $i++) {
    $h = trim(fgets(STDIN));
    $head = substr($s, 0, $h);
    $tail = substr($s, $h);
    $s = $tail . $head;
  }

  echo $s . "\n";
}
