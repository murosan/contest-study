#!/bin/bash

usage_exit() {
  echo "Usage: $0 [-f] filename" 1>&2
  exit 1
}

fail_exit() {
  rm "./main"
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

  # testing
  out=$(./main <<< $input)
  if [[ $out != $output ]]; then
    failed=1
    echo "Fail!"
    echo "------------------- expected -------------------"
    echo $output
    echo "-------------------- actual --------------------"
    echo $out
    echo "------------------------------------------------"
    fail_exit
  fi
done

cat $cpp_file | pbcopy
echo -e "Success!!\nCopied to clipboard"
