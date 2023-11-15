APP1=encode
APP2=decode
INPUT=text1.txt
CIPHER=message1.txt
OUTPUT=output.txt
ERRORS=0

# See https://stackoverflow.com/questions/962255/how-to-store-standard-error-in-a-variable

echo "Building the two applications ..."
make clean > /dev/null && make > /dev/null
echo "Finished building."

echo "Testing handling of incorrect command-line input ..."
MSG="$(./$APP1 2>&1 > /dev/null)"
EXPECTED="Please enter input and output file names as command-line arguments."
if [ "$MSG" != "$EXPECTED" ]
then
    echo "$APP1: Missing or incorrect error message for missing command-line arguments."
    ERRORS=$((ERRORS + 1))
fi

MSG="$(./$APP2 2>&1 > /dev/null)"
EXPECTED="Please enter an input file name as a command-line argument."
if [ "$MSG" != "$EXPECTED" ]
then
    echo "$APP2: Missing or incorrect error message for missing command-line arguments."
    ERRORS="$((ERRORS + 1))"
fi
echo "Errors: $ERRORS"

echo "Checking encoding and decoding ..."
ERRORS=0
./$APP1 $INPUT $CIPHER
./$APP2 $CIPHER > $OUTPUT

DIFF=$(diff $INPUT $OUTPUT)
if [ "$DIFF" != "" ]
then
    printf "\nXXXXXXXX UNEXPEXTED OUTPUT: XXXXXXXX\n\n"
    printf "In each pair below, your output appears above the expected output.\n"
    printf "$DIFF\n\n"
    ERRORS=$((ERRORS + 1))
fi

if [ $ERRORS -eq 0 ]
then
    printf "\n======== CORRECT ========\n\n"
fi
rm $CIPHER
rm $OUTPUT
make clean > /dev/null
