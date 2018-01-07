<?php
$pattern = strtolower(trim(fgets(STDIN)));
$count = 0;

while (true) {
  $text = trim(fgets(STDIN));
  if ($text == "END_OF_TEXT") break;
  $text = explode(" ", strtolower($text));

  foreach ($text as $word)
    if ($word == $pattern) $count++;
}

echo $count . "\n";
