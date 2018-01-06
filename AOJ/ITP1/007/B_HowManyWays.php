<?php
while (true) {
  list($n, $x) = explode(" ", trim(fgets(STDIN)));
  if (!$n && !$x) break;

  $count = 0;
  for ($i = 1; $i <= $n; $i++)
    for ($j = $i + 1; $j <= $n; $j++)
      for ($k = $j + 1; $k <= $n; $k++)
        if ($i != $j && $i != $k && $j != $k && $i + $j + $k == $x) $count++;

  echo "$count\n";
}
