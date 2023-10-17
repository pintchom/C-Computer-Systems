# Author: Amittai Aviram - aviram@bc.edu

APP1=./div1
APP2=./div2
OUTPUT1=output1.txt
OUTPUT2=output2.txt
INPUT=input_pa3.txt
EXPECTED=expected_pa3.txt

echo "Building ..."
make clean && make

echo "Running ..."
$APP1 < $INPUT > $OUTPUT1
$APP2 < $INPUT > $OUTPUT2
echo >> $OUTPUT1
echo >> $OUTPUT2

echo "Checking $APP1 ..."
DIFF=$(diff $OUTPUT1 $EXPECTED)
if [ "$DIFF" != "" ]
then
    echo -e "\nXXXXXXXX UNEXPECTED OUTPUT: XXXXXXXX\n"
    echo "$DIFF\n"
else
    echo -e "\n======== CORRECT ========\n"
fi

echo "Checking $APP2 ..."
DIFF=$(diff $OUTPUT2 $EXPECTED)
if [ "$DIFF" != "" ]
then
    echo -e "\nXXXXXXXX UNEXPECTED OUTPUT: XXXXXXXX\n"
    echo "$DIFF\n"
else
    echo -e "\n======== CORRECT ========\n"
fi
rm $OUTPUT1 $OUTPUT2
make clean
