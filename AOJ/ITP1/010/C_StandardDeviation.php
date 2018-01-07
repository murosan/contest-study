<?php
while (true) {
  $n = trim(fgets(STDIN));
  if (!$n) break;

  $points = explode(" ", trim(fgets(STDIN)));
  $avg = array_sum($points) / $n;

  $dispersion = 0;
  foreach ($points as $point) $dispersion += pow($avg - $point, 2);
  $dispersion /= $n;

  echo sprintf("%.10f\n", abs(sqrt($dispersion)));
}
