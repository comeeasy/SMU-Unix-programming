#! /bin/bash

for i in $*
do
	echo $i
done

echo ===============================

for i in $@
do
	echo $i
done

echo ===============================

for i in "$*"
do
	echo $i
done

echo ===============================

for i in "$@"
do
	echo $i
done

exit 0
