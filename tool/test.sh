#!/bin/bash

usage_exit() {
  echo "Usage: $0 -f (b_a|b_b|b_c|b_d)" 1>&2
  exit 1
}

del() {
  rm "./main"
}

fail_exit() {
  del
  exit 1
}

while getopts ":f:" OPT
do
  case $OPT in
    f) file=$OPTARG;;
    :) usage_exit;;
    \?) usage_exit;;
  esac
done

shift $(($OPTIND - 1))

if [[ $file = "" ]]; then
  echo "filename was not specified."
  usage_exit
fi

cpp_file="$HOME/CLionProjects/contest/main.cpp"
g++ -std=c++1y -o main $cpp_file

json=$(cat "./cases/$file.json")
len=$(echo $json | jq length)
for i in $( seq 0 $(($len - 1)) ); do
  # read test case
  kv=$(echo $json | jq .[$i])
  input=$(echo $kv | jq .in | sed "s/\"//g")
  output=$(echo $kv | jq .out | sed "s/\"//g")
  output=$(echo -e "$output") # convert new lines

  # testing
  out="$(./main <<< $input)"
  if [[ $out != $output ]]; then
    echo -e "Fail!\ninput: $input"
    echo "------------------- expected -------------------"
    echo -e "$output"
    echo "-------------------- actual --------------------"
    echo -e "$out"
    echo "------------------------------------------------"
    fail_exit
  fi
done

cat $cpp_file | pbcopy
del
echo -e "Success!!\nCopied to clipboard"
