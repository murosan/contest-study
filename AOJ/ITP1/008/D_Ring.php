<?php
$s = trim(fgets(STDIN));
$p = trim(fgets(STDIN));
$s .= $s;
if (strpos($s, $p) === false) echo "No\n";
else echo "Yes\n";
