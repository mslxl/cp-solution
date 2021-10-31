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

EXEC="/tmp/$FILE_NAME_WITHOUT_EXT"

if [[ -f "/tmp/$FILE_NAME_WITHOUT_EXT" ]]; then
    echo "Remove old execuable file"
    rm "/tmp/$FILE_NAME_WITHOUT_EXT"
fi


echo "Compling to $EXEC"
g++ "$FILE_DIR/$FILE_NAME" -o "$EXEC"
if [[ "$?" -ne "0" ]]; then
    exit $?
fi

STDOUT="/tmp/$FILE_NAME_WITHOUT_EXT.$RANDOM.stdout"
echo "Execuating..."
if [[ -f "$FILE_DIR/$FILE_NAME_WITHOUT_EXT.in" ]]; then
    echo -n "Redirect $FILE_NAME_WITHOUT_EXT.in to stdin..."
    cat "$FILE_DIR/$FILE_NAME_WITHOUT_EXT.in" | $EXEC > "$STDOUT" || {
        ERROR_CODE="$?"
        cat "$STDOUT"
        echo "Program exit with error code: $ERROR_CODE."
        exit $ERROR_CODE
    }
else
    $EXEC | tee "$STDOUT" || {
        ERROR_CODE="$?"
        echo "Program exit with error code: $ERROR_CODE!"
        exit $ERROR_CODE
    }
fi
echo "Finish!"
echo

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
        echo "The code was copy to clipborad"
        not_copy=true
        type clip.exe > /dev/null && $not_copy && {
            # Running in WSL
            cat "$FILE_DIR/$FILE_NAME" | clip.exe
            not_copy=false
        }
        rm "$FILE_DIR/$FILE_NAME_WITHOUT_EXT.out.diff"
    else 
        echo "Diff: "
        echo
        cat "$FILE_DIR/$FILE_NAME_WITHOUT_EXT.out.diff" | highlight --syntax diff -O xterm256
        # cat "$FILE_DIR/$FILE_NAME_WITHOUT_EXT.out.diff" 
        echo
        echo "Differ file save to $FILE_DIR/$FILE_NAME_WITHOUT_EXT.out.diff"
    fi
else
    echo "OUTPUT: "
    cat "$STDOUT"
fi