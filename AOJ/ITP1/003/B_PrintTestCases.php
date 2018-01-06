<?php
for ($i = 1; ; $i++) {
  $x = trim(fgets(STDIN));
  if ($x == 0) break;
  echo "Case $i: $x\n";
}
