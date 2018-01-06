<?php
$s = str_split(trim(fgets(STDIN)));
foreach ($s as $c) {
  if (ctype_upper($c)) echo strtolower($c);
  else if (ctype_lower($c)) echo strtoupper($c);
  else echo $c;
}
echo "\n";
