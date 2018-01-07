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
}

$dice = new Dice();
$n = explode(" ", trim(fgets(STDIN)));
$dice->top = $n[0];
$dice->south = $n[1];
$dice->east = $n[2];
$dice->west = $n[3];
$dice->north = $n[4];
$dice->bottom = $n[5];

$order = str_split(trim(fgets(STDIN)));
foreach ($order as $o) {
  if ($o == "N") $dice->toNorth();
  elseif ($o == "E") $dice->toEast();
  elseif ($o == "S") $dice->toSouth();
  else $dice->toWest();
}

echo $dice->top . "\n";
