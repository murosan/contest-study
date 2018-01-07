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

  public function equals($d)
  {
    $n1 = array($this->top, $this->bottom, $this->north, $this->east, $this->south, $this->west);
    $n2 = array($d->top, $d->bottom, $d->north, $d->east, $d->south, $d->west);
    sort($n1);
    sort($n2);
    if ($n1 != $n2) return false;

    $this->toTop($d->top);
    $count = 0;
    while ($this->south != $d->south && $count <= 3) {
      $this->spin();
      $count++;
    }

    if ($this->top == $d->top && $this->bottom == $d->bottom &&
      $this->north == $d->north && $this->east == $d->east &&
      $this->south == $d->south && $this->west == $d->west)
      return true;
    else
      return false;
  }
}

$n = trim(fgets(STDIN));
$dices = array();
for ($i = 0; $i < $n; $i++) {
  $num = explode(" ", trim(fgets(STDIN)));
  array_push($dices, getDice($num));
}

$notEqual = true;
for ($i = 0; $i < $n && $notEqual; $i++)
  for ($j = $i + 1; $j < $n && $notEqual; $j++)
    $notEqual = !$dices[$i]->equals($dices[$j]);

if ($notEqual) echo "Yes\n";
else echo "No\n";

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
