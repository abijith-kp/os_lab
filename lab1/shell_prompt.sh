#all commands that is to be exicuted in this command prompt should be put in another folder cmd.
#example:
# 	if fact.sh is to be run then move fact.sh to cmd/
#	   run this script and type fact 5


#!/bin/bash

clear
cd cmd/

while [ 1 ];
	do
	#command prompt
	read -p "devil> " cmd

	#converting the arguments to an array
	arr=(${cmd})

	if ls | grep "${arr[0]}" > /dev/null;
			then
			./"${arr[0]}".sh ${cmd#"${arr[0]} "}
		else
		echo "ERROR: $cmd : command not found"
		fi
	done
