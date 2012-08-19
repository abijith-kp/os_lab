#create a new folder with given name if it do not exist or delete the existing file and then create the new folder 

#!/bin/bash

if [ -f $1 ];
	then
	rm $1
	mkdir $1
fi

if [ ! -d $1 ];
	then
	mkdir $1
fi

echo "FOLDER IS CREATED"
