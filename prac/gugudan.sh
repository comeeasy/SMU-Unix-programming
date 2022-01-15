#! /bin/bash

echo "gugudan"

for i in 1 2 3 4 5 6 7 8 9;
do
	for j in 1 2 3 4 5 6 7 8 9;
	do
		k=$(($i * $j));
		echo -n "$i*$j=$k\t";
	done
	echo ""
done
