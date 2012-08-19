#get the output from line $2 to $3 from the file $1

#!/bin/bash

x=`expr $3 - $2 + 1`
head -n$3 $1 | tail -n$x
exit
