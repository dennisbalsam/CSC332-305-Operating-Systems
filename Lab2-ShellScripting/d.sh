#!/bin/bash
echo starting e
if [ -e ./e.sh ]
then
        chmod +x ./e.sh
else

        echo "---file e.sh  does not exist in the current directory---"
        echo "current files in directory:"
        ls
        echo " "
fi
ps
sleep 5

