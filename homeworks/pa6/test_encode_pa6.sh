APP=encode
INPUT=text1.txt
EXPECTED=cipher1.txt
OUTPUT=output.txt
ERRORS=0

echo "Building the two applications ..."
make clean > /dev/null && make > /dev/null
echo "Finished building."

echo "Checking encoding ..."
./$APP $INPUT $OUTPUT

DIFF=$(diff $OUTPUT $EXPECTED)
if [ "$DIFF" != "" ]
then
    printf "\nXXXXXXXX UNEXPEXTED OUTPUT: XXXXXXXX\n\n"
    printf "In each pair below, your output appears above the expected output.\n"
    printf "$DIFF\n\n"
else
    printf "\n======== CORRECT ========\n\n"
fi

rm $OUTPUT
make clean > /dev/null
