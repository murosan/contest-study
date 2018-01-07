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

$n1 = explode(" ", trim(fgets(STDIN)));
$n2 = explode(" ", trim(fgets(STDIN)));

$dice1 = getDice($n1);
$dice2 = getDice($n2);

sort($n1);
sort($n2);

if ($n1 != $n2) {
  echo "No\n";
  return;
}

$dice2->toTop($dice1->top);
while ($dice1->south != $dice2->south) $dice2->spin();

if ($dice1->north == $dice2->north
  && $dice1->east == $dice2->east
  && $dice1->west == $dice2->west)
  echo "Yes\n";
else
  echo "No\n";

function getDice($n)
{
  $dice = new Dice();
  $dice->top = $n[0];
  $dice->south = $n[1];
  $dice->east = $n[2];
  $dice->west = $n[3];
  $dice->north = $n[4];
  $dice->bottom = $n[5];
  return $dice;
}
