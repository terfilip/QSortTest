
#!/bin/bash

#The script that conducts the test and prints results in 
#CSV table.

function print_cell()
{
	local j="2"
	local line="$2,"
	while [ $j -lt 9 ]
		do
		local seconds_sum="0"
		local k="0"
		local trial_runs="5"
		while [ $k -lt $trial_runs ]
			do
			local trial_result="$(extract_seconds $1 $j )"
			#echo $trial_result
			seconds_sum="$(echo "$seconds_sum+$trial_result" | bc )"
			((k++))
			done
		local avg="$(./div.py $seconds_sum $trial_runs)" 
		local line="$line$avg,"
		echo "10^$j ints with $2 done."
		((j++))
		done
		echo "$line" >> RunTimesTable.csv
}


function extract_seconds()
{
	local raw_out="$(time ($*) 2>&1 1>/dev/null )"
	#echo "time output"
	#echo $raw_out
	local real_time="$(echo $raw_out | cut -d\s -f1)"
	#echo "real time"
	#echo $real_time
	local minute_delim="$(echo $real_time | sed -n "s/[m].*//p" | wc -c )"
	local seconds="$(echo ${real_time:minute_delim} )"
	#echo "number of seconds w/o mins"
	#echo $seconds
	local real_mins="$(echo $real_time | cut -d\m -f1)"
	#echo "minutes w/o secs"
	#echo $real_mins
	local sp_delim="$(echo $real_mins | sed -n "s/[' '].*//p" | wc -c )"
	local mins="$(echo ${real_mins:sp_delim} )"
	#echo "just mins"
	#echo $mins
	local minsec=$[$mins*60]
	local seconds="$(echo "$minsec+$seconds" | bc )"
	#echo "The total number of seconds is"
	#echo $seconds
	echo $seconds
}

function print_headings()
{
	echo " ,Seconds taken to sort array, , , , , , ," > RunTimesTable.csv
	local headings="Language"
	local exp="2"
	while [ $exp -lt 9 ] 
		do
		headings="$headings,10^$exp integers"
		((exp++))
		done
	echo $headings >> RunTimesTable.csv
}

#Running the script will delete any previous RunTimesTable, to save the hassle of deleting it manually
print_headings
i="0"
prog_commands=( ./QsortC ./Qsort "java Qsort" ./Qsort.py "pypy Qsort.py" ./Qsort.php "jython -J-Xmx8000m Qsort.py" )
langs=(C C++ Java "Python 3" "PyPy2.2.1" PHP Jython)
while [ $i -lt ${#prog_commands[@]} ]
	do
	print_cell "$(echo ${prog_commands[$i]} )" "$(echo ${langs[$i]} )"
	((i++))
	done

