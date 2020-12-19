#!/bin/bash

# Configuration
ENABLE_BONUS='1'
MSH_PATH='..'
LOG_PATH='./log'
SRC_PATH='./src'
TMP_PATH='./tmp'

# Colors
RESET="\033[0m"
RED="\033[31m"
GREEN="\033[32m"

for src in $SRC_PATH/*.sh; do
	source $src
done

init

for path in ./suite/*; do
	run_suite $path
done

if [ "$ENABLE_BONUS" == "1" ]; then
	run_suite './bonus'
fi

show_results
clean
