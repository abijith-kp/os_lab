#to replace the word $2 with the word $3 from the file $1

#!/bin/bash

if [ -z $1 ] || [ -z $2 ] || [ -z $3 ];
	then
	echo "ERROR:OPERAND MISSING"
	exit
fi

if [ ! -s $3 ];
	then
	echo "ERROR: $3 :FILE NOT FOUND"
	exit
fi

sed -i "s,$1,$2,g" $3

echo "FILE CHANGED"
exit
