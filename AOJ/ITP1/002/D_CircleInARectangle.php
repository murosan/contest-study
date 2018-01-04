<?php
list($W, $H, $x, $y, $r) = explode(" ", trim(fgets(STDIN)));

if ($r <= $x && $x <= $W - $r && $r <= $y && $y <= $H - $r)
  echo "Yes\n";
else
  echo "No\n";
