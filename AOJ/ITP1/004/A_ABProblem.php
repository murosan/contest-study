<?php
list($a, $b) = explode(" ", trim(fgets(STDIN)));

$div = $a / $b;

echo intval($div) . "\n";
echo ($a % $b) . "\n";
echo sprintf("%7f\n", $div);
