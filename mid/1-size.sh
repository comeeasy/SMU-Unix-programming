#!/bin/bash

let sum=0;

for i in "$@"
do
	if [ ! -e "$1" ];
	then 
		echo "No shcu file or directory"
		exit 1
	fi
	size="`stat -c %s $i`"
  echo "$i" "$size"
	sum=$(($sum + $size))
done

echo $sum

exit 0
