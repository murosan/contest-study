<?php

class Dice
{
  public $top = 0;
  public $bottom = 0;
  public $north = 0;
  public $east = 0;
  public $south = 0;
  public $west = 0;

  public function toNorth()
  {
    $t = $this->top;
    $this->top = $this->south;
    $this->south = $this->bottom;
    $this->bottom = $this->north;
    $this->north = $t;
  }

  public function toEast()
  {
    $t = $this->top;
    $this->top = $this->west;
    $this->west = $this->bottom;
    $this->bottom = $this->east;
    $this->east = $t;
  }

  public function toSouth()
  {
    $t = $this->top;
    $this->top = $this->north;
    $this->north = $this->bottom;
    $this->bottom = $this->south;
    $this->south = $t;
  }

  public function toWest()
  {
    $t = $this->top;
    $this->top = $this->east;
    $this->east = $this->bottom;
    $this->bottom = $this->west;
    $this->west = $t;
  }

  public function spin()
  {
    $n = $this->north;
    $this->north = $this->west;
    $this->west = $this->south;
    $this->south = $this->east;
    $this->east = $n;
  }

  public function toBottom()
  {
    $this->toNorth();
    $this->toNorth();
  }

  public function toTop($x)
  {
    if ($x == $this->north) $this->toSouth();
    elseif ($x == $this->east) $this->toWest();
    elseif ($x == $this->south) $this->toNorth();
    elseif ($x == $this->west) $this->toEast();
    elseif ($x == $this->bottom) $this->toBottom();
  }
}

$dice = new Dice();
$n = explode(" ", trim(fgets(STDIN)));
$dice->top = $n[0];
$dice->south = $n[1];
$dice->east = $n[2];
$dice->west = $n[3];
$dice->north = $n[4];
$dice->bottom = $n[5];

$q = trim(fgets(STDIN));

for ($i = 0; $i < $q; $i++) {
  list($a, $b) = explode(" ", trim(fgets(STDIN)));
  $dice->toTop($a);
  while ($b != $dice->south) $dice->spin();
  echo $dice->east . "\n";
}
