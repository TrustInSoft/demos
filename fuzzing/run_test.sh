#!/bin/bash

INPUT_FILE=input-files/seeds.txt

if [ "$1" == "afl" ]; then
	afl-fuzz -i input-files -o afl-results ./calculate 7 19
elif [ "$1" == "loop" ]; then
	for x in {-10..1000}; do
		for y in {-10..1000}; do
			./calculate $x $y
		done
	done
else
	nblines=$(cat $INPUT_FILE | wc -l)
	echo "Seeds file has $nblines lines"
	for line in {1..16}; do
		#echo "LIne = $line"
		str=$(sed "${line}q;d" ${INPUT_FILE})
		# echo "Running: calculate $str"
		./calculate $line
	done
fi
