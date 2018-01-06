<?php
$lowers = range("a", "z");
$counts = array();
foreach ($lowers as $lower) $counts[$lower] = 0;

while (true) {
  $s = trim(fgets(STDIN));
  if ($s == '') break;

  $s = str_split($s);
  foreach ($s as $c)
    if (ctype_lower($c) || ctype_upper($c))
      $counts[strtolower($c)]++;
}

foreach ($lowers as $lower) echo "$lower : $counts[$lower]\n";
