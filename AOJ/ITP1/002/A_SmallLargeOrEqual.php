<?php
list($a, $b) = explode(" ", trim(fgets(STDIN)));
$op = $a == $b ? "==" : ($a < $b ? "<" : ">");
echo "a $op b\n";
