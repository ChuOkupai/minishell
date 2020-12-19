#!/bin/bash

function init()
{
	export LC_ALL=C # Forces byte-wise comparison for sorting
	rm -rf $LOG_PATH $TMP_PATH
	mkdir $TMP_PATH
	if [ "$ENABLE_BONUS" == "1" ]; then
		flag='bonus'
	else
		flag='all'
	fi
	make -C $MSH_PATH $flag > /dev/null
	cp $MSH_PATH/minishell minishell
	chmod 755 minishell
	FAILED=0
	PASSED=0
}
