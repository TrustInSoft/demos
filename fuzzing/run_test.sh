#!/bin/bash

INPUT_DIR=input-files

for file in $(ls input-files); do
	echo "Running: ./calculate input-files/$file"
	./calculate input-files/$file
done

exit 0