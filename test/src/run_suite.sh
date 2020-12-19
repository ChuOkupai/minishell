#!/bin/bash

# (type, output, expected_output)
function write_entry()
{
	printf "\n----\n$1\n----\n$2\n----\n" >> "$file"
	printf "EXPECTED $1\n----\n$3\n----\n" >> "$file"
}

function write_log()
{
	path="$LOG_PATH/$suite_name/$section"
	file="$path/test$n"
	mkdir -p $path
	echo "$test_case" >> "$file"
	if [ "$output1" != "$output2" ]; then
		write_entry 'OUTPUT' "$output1" "$output2"
	fi
	if [ "$exit_status1" != "$exit_status2" ]; then
		write_entry 'EXIT STATUS' "$exit_status1" "$exit_status2"
	fi
	printf $RED"FAILED$RESET %s\n" "'$test_case'"
	FAILED=$((FAILED + 1))
}

function run_suite()
{
	suite_name=$(basename $1)
	echo 'Suite: '$suite_name
	for path in $(echo $1/*.txt); do
		section=$(basename $path .txt)
		echo "  > $section"
		n=1
		while read -r test_case; do
			output1=$(echo -e "$test_case\nexit" | ./minishell 2>&-)
			exit_status1=$?
			output2=$(echo -e "$test_case\nexit" | bash --noprofile --norc 2>&-)
			exit_status2=$?
			if [ "$output1" == "$output2" ] && [ "$exit_status1" == "$exit_status2" ]; then
				PASSED=$((PASSED + 1))
			else
				write_log
			fi
			n=$((n + 1))
		done < $path
	done
}
