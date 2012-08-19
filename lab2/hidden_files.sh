#to move all the hidden files to a new folder called hidden_files

#!/bin/bash

if [ ! -d hidden_files ] ;
	then
	mkdir hidden_files
fi

mv .* hidden_files
