#! /bin/bash

function add() 
{
sum=0
adder=1
while [ $adder -le 100 ];
do
	sum=$(($sum + $adder));
	adder=$(($adder + 1));
done
echo $sum
}



