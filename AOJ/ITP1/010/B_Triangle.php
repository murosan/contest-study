<?php
list($a, $b, $c) = explode(" ", trim(fgets(STDIN)));
$c *= pi() / 180;

$s = 0.5 * $a * $b * sin($c);
$l = $a + $b + sqrt(pow($a, 2) + pow($b, 2) - 2 * $a * $b * cos($c));
$h = $b * sin($c);

echo sprintf("%.10f\n%.10f\n%.10f\n", $s, $l, $h);
