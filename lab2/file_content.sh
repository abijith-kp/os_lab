#to check the wheather the two given files have the same content

#!/bin/bash

if diff $1 $2 > /dev/null ;
	then
	echo "FILES ARE SAME!!!!"
else
	echo "FILES ARE NOT SAME!!!!"
fi

exit
