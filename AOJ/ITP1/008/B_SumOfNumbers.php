<?php
while (true) {
  $s = str_split(trim(fgets(STDIN)));
  if (!$s[0]) break;
  echo array_sum($s) . "\n";
}
