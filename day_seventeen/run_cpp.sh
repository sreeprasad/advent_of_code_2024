#!/bin/bash

SOURCE_FILE="two.cpp"
OUTPUT_FILE=${SOURCE_FILE%.cpp}

INPUT_FILE=${2:-input.txt}

g++ -std=c++17 -Wall -Wextra -Wshadow -DONPC -O2 -o "$OUTPUT_FILE" "$SOURCE_FILE"

if [ $? -eq 0 ]; then
    echo "Compilation successful. Running the program..."
    if [ -f "$INPUT_FILE" ]; then
        ./"$OUTPUT_FILE" < "$INPUT_FILE"
    else
        echo "Input file $INPUT_FILE not found. Running without input..."
        ./"$OUTPUT_FILE"
    fi
else
    echo "Compilation failed."
fi

