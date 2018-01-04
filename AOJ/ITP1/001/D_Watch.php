<?php
$s = fgets(STDIN);
$hou = intval($s / 3600);
$min = intval($s % 3600 / 60);
$sec = $s % 60;
echo "$hou:$min:$sec\n";
