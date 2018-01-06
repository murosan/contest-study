<?php
while (true) {
  list($m, $f, $r) = explode(" ", trim(fgets(STDIN)));
  if ($m == -1 && $f == -1 && $r == -1) break;

  if ($m == -1 || $f == -1) echo "F\n";
  elseif ($m + $f >= 80) echo "A\n";
  elseif ($m + $f >= 65) echo "B\n";
  elseif ($m + $f >= 50 || $r >= 50) echo "C\n";
  elseif ($m + $f >= 30) echo "D\n";
  else echo "F\n";
}
