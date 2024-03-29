#!/usr/bin/bash

OUTPUT_FILENAME="CustomDynamicArrays_MatricesCalculator"

g++ -I custom_dynamic_arrays/headers/ -o "$OUTPUT_FILENAME" custom_dynamic_arrays/*.cpp

chmod +x "$OUTPUT_FILENAME"
./"$OUTPUT_FILENAME"
