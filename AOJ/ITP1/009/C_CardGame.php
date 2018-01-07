<?php
$n = trim(fgets(STDIN));
$ptTaro = 0;
$ptHanako = 0;

for ($i = 0; $i < $n; $i++) {
  list($text1, $text2) = explode(" ", trim(fgets(STDIN)));
  $cmp = strcmp($text1, $text2);
  if ($cmp == 0) {
    $ptTaro++;
    $ptHanako++;
  } elseif ($cmp > 0) {
    $ptTaro += 3;
  } else {
    $ptHanako += 3;
  }
}

echo "$ptTaro $ptHanako\n";
