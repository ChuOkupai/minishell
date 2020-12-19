#!/bin/bash

if [[ "$#" != "1" ]]; then
	echo "usage: $0 [SIGNAME or SIGNUM]"
	exit 1
fi
kill -s "$1" $$
