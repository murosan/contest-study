<?php
$n = trim(fgets(STDIN));
$x = explode(" ", trim(fgets(STDIN)));
$y = explode(" ", trim(fgets(STDIN)));

$a = array();
for ($i = 0; $i < $n; $i++)
  $a[$i] = abs($x[$i] - $y[$i]);

$p1 = 0;
$p2 = 0;
$p3 = 0;
$p4 = 0;

foreach ($a as $ai) {
  $p1 += $ai;
  $p2 += $ai * $ai;
  $p3 += $ai * $ai * $ai;
  if ($p4 < $ai) $p4 = $ai;
}
$p2 = sqrt($p2);
$p3 = pow($p3, 1 / 3);

echo sprintf("%.10f\n%.10f\n%.10f\n%.10f\n", $p1, $p2, $p3, $p4);
