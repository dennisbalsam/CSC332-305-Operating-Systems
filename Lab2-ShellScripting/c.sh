#!/bin/bash
echo starting d
if [ -e ./d.sh ]
then
        ./d.sh
else
        echo "--file d.sh  does not exist in the current directory---"
        echo "current files in directory:"
        ls
fi
ps
sleep 5

