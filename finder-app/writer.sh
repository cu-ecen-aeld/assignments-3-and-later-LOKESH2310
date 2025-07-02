#!/bin/bash

# Check for required number of arguments
if [ $# -ne 2 ]; then
    echo "Error: Two arguments required - writefile and writestr"
    exit 1
fi

writefile=$1
writestr=$2

# Extract the directory path from the writefile
dirpath=$(dirname "$writefile")

# Create directory path if it does not exist
mkdir -p "$dirpath"

# Try writing to the file
echo "$writestr" > "$writefile"

# Check if writing was successful
if [ $? -ne 0 ]; then
    echo "Error: Failed to create or write to file '$writefile'"
    exit 1
fi

exit 0

