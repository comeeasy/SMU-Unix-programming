#! /bin/bash

# args: one two "long three"
for i in one two long three
do 
	echo $i
done

echo =============================

for i in one two long three
do 
	echo $i
done

echo =============================

for i in "one two long three"
do 
	echo $i
done

echo =============================

for i in "one" "two" "long three"
do 
	echo $i
done

echo =============================
