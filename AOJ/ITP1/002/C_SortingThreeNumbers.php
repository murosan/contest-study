<?php
$list = explode(" ", trim(fgets(STDIN)));
sort($list);
echo implode(" ", $list), "\n";
