#!/bin/bash

function show_results()
{
	n=$((FAILED + PASSED))
	if [ "$FAILED" -eq "0" ]; then
		echo -e $GREEN"All tests passed successfully!$RESET ($n tests)"
	else
		echo -e "$RED$FAILED / $n tests failed"$RESET
		echo "Trace available in $LOG_PATH"
		read -p "Show trace with less? (yes/no) " choice
		case "$choice" in
			y|yes|Y|YES ) less $LOG_PATH/*/*/* ;;
		esac
	fi
}
