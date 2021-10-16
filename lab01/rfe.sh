#! /bin/bash

if [ $# -ne 2 ]
then
	echo "Usage: $0 old_suffix new_suffix"
	exit 1
fi

for file in *.$1
do
	mv $file `basename $file $1`$2
done

exit 0
