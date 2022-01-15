# control.sh
#! /bin/bash

if [ $# -ne 1 ];
then
	echo "wrong dude";
	exit 1;
fi

if [ $(($1 % 2)) -eq 0 ];
then
	echo "2 series"
elif [ $(($1 % 3)) -eq 0 ];
then
	echo "3 series"
fi

for i in `ls .`;
do
	stat "$i"
	echo '\n'
done
