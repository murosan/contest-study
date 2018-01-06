<?php
$n = trim(fgets(STDIN));
$arr = explode(" ", trim(fgets(STDIN)));

echo min($arr) . " " . max($arr) . " " . array_sum($arr) . "\n";
