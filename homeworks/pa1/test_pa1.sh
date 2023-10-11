#!/bin/sh
# Author: Amittai Aviram - aviram@bc.edu

APP=pa1
INPUT=input_$APP.txt
EXPECTED=expected_$APP.txt

echo Building ...
gcc -Wall -Werror -std=c99 $APP.c -o $APP
echo Building complete.

echo Running ...
./$APP < $INPUT > output.txt
echo Running complete.

echo Comparing real and expected output.
DIFF=$(diff output.txt $EXPECTED)
if [ "$DIFF" != "" ]
then
    printf "\nXXXXXXXX UNEXPEXTED OUTPUT: XXXXXXXX\n\n"
    printf "In each pair below, your output appears above the expected output.\n"
    printf "$DIFF\n\n"
else
    printf "\n======== CORRECT ========\n\n"
fi
rm output.txt


