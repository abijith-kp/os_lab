#programe that implements an adder using functions

#!/bin/bash

function adder()
	{ sum=`expr $1 + $2`
	  echo "SUM IS $sum"
	  exit
	}

if [ -z $1 ] || [ -z $2 ];
	then
	echo "ERROR:OPERANDS MISSING"
	exit
fi

adder $1 $2
