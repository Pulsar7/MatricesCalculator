#!/usr/bin/bash

OUTPUT_FILENAME="CustomDynamicArrays_MatricesCalculator"

g++ -o "$OUTPUT_FILENAME" custom_dynamic_arrays/*.cpp -I custom_dynamic_arrays/_headers/

chmod +x "$OUTPUT_FILENAME"
./"$OUTPUT_FILENAME"
