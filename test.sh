#!/usr/bin/bash

OUTPUT_FILENAME="MatricesCalculator"

g++ -I src/headers/ -o "$OUTPUT_FILENAME" src/*.cpp

chmod +x "$OUTPUT_FILENAME"
./"$OUTPUT_FILENAME"
