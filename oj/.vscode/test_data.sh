#!/bin/zsh
set -e

FILE_NAME="$1"
FILE_NAME_WITHOUT_EXT="$2"
FILE_DIR=$(realpath "$3")

# Print relate info
# echo "File Name: $FILE_NAME"
# echo "File Name Without Extension: $FILE_NAME_WITHOUT_EXT"
# echo "Dir : $FILE_DIR"
# echo "***"
echo "Test $FILE_DIR/$FILE_NAME"

if [[ -f "/tmp/$FILE_NAME_WITHOUT_EXT" ]]; then
    echo "Remove old execuable file"
    rm "/tmp/$FILE_NAME_WITHOUT_EXT"
fi

EXEC="/tmp/$FILE_NAME_WITHOUT_EXT"

echo "Compling..."
g++ "$FILE_DIR/$FILE_NAME" -o "$EXEC"
if [[ "$?" -ne "0" ]]; then
    exit $?
fi

STDOUT="/tmp/$FILE_NAME_WITHOUT_EXT.$RANDOM.stdout"
echo "Execuating..."
if [[ -f "$FILE_DIR/$FILE_NAME_WITHOUT_EXT.in" ]]; then
    echo -n "Redirect $FILE_NAME_WITHOUT_EXT.in to stdin..."
    cat "$FILE_DIR/$FILE_NAME_WITHOUT_EXT.in" | $EXEC > "$STDOUT"
else
    $EXEC | tee "$STDOUT"
fi
echo "Finish!"
echo "***"

OUTPUT_LEN=${#$(cat "$STDOUT" )}
if [[ "$OUTPUT_LEN" -ne "0" ]]; then
    cp -f "$STDOUT" "$FILE_DIR/$FILE_NAME_WITHOUT_EXT.ans.out"
else
    echo "!!! NO OUTPUT !!!"
    exit 255
fi

if [[ -f "$FILE_DIR/$FILE_NAME_WITHOUT_EXT.out" ]]; then
    diff -u "$FILE_DIR/$FILE_NAME_WITHOUT_EXT.out" "$STDOUT" > "$FILE_DIR/$FILE_NAME_WITHOUT_EXT.out.diff" || true
    DIFF_LENGTH=${#$(cat "$FILE_DIR/$FILE_NAME_WITHOUT_EXT.out.diff")}
    if [[ "$DIFF_LENGTH" -eq "0" ]]; then
        echo "Congruation! The output is identical to template file"
        rm "$FILE_DIR/$FILE_NAME_WITHOUT_EXT.out.diff"
    else 
        echo "Diff: "
        # cat "$FILE_DIR/$FILE_NAME_WITHOUT_EXT.out.diff" |highlight --syntax diff -O xterm256
        cat "$FILE_DIR/$FILE_NAME_WITHOUT_EXT.out.diff" 
        echo "***"
        echo "diff file save to $FILE_NAME_WITHOUT_EXT.out.diff"
    fi
else
    echo "OUTPUT: "
    cat "$STDOUT"
fi