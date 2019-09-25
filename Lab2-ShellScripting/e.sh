#!/bin/bash
if [ -e ./a.sh ]
then
	echo the contents of a.sh
        cat ./a.sh
else

        echo "--file a.sh  does not exist in the current directory---"
        echo "current files in directory:"
        ls
        echo " "
fi
ps
echo All files in current directory:
pwd
ls -l
sleep 5

