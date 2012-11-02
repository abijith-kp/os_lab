#!/bin/bash

arg=$0
name=`echo $0 | cut -c 3-${#arg}`

echo "Compiling files in the current folder.... $name"

for i in *.c
	do
	if echo $i | grep --word $name
		then
		continue
	else
		echo "Compiling $i...."
		out=`echo $i | cut -c 1-$[${#i} - 2]`
		gcc $i -o $out
	fi
done

echo "Ready to execute...."
exit
