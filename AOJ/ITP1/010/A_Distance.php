<?php
list($x1, $y1, $x2, $y2) = explode(" ", trim(fgets(STDIN)));
echo sprintf("%.10f\n", sqrt(($x2 - $x1) * ($x2 - $x1) + ($y2 - $y1) * ($y2 - $y1)));
