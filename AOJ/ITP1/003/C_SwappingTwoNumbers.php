<?php
while (true) {
  list($a, $b) = explode(" ", trim(fgets(STDIN)));
  if (!$a && !$b) break;

  if ($a < $b) echo "$a $b\n";
  else echo "$b $a\n";
}
