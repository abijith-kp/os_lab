#check wheather the given number is odd or even

#!/bin/bash

read -p "enter a no.: " n
chk=`expr $n % 2`

if [ $chk == 0 ];
	then
	echo "$n is even"
	exit
fi

echo "$n is odd"
exit
