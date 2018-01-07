<?php
$str = trim(fgets(STDIN));
$n = trim(fgets(STDIN));

for ($i = 0; $i < $n; $i++) {
  $line = explode(" ", trim(fgets(STDIN)));
  $order = $line[0];
  $a = $line[1];
  $len = $line[2] - $a + 1;

  if ($order == "print")
    echo substr($str, $a, $len) . "\n";
  elseif ($order == "reverse")
    $str = substr_replace(
      $str,
      strrev(substr($str, $a, $len)),
      $a,
      $len
    );
  else
    $str = substr_replace($str, $line[3], $a, $len);
}
