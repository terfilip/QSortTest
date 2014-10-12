
#!/bin/bash

#The script that conducts the test and prints results in
#CSV table.

function printCell() {
	local j="2"
	local line="$2,"
	while [ $j -lt 9 ]
		do
		local secondsSum="0"
		local k="0"
		local trialRuns="5"
		while [ $k -lt $trialRuns ]
			do
			#echo "command: $1 $j" #LOG
			local trialResult="$(extractSeconds $1 $j )"
			#echo $trial_result
			secondsSum="$(echo "$secondsSum+$trialResult" | bc )"
			((k++))
			done
		local avg="$(../div.py $secondsSum $trialRuns)"
		local line="$line$avg,"
		echo "10^$j ints with $2 done."
		((j++))
		done
		echo "$line" >> ../result/RunTimesTable.csv
}


function extractSeconds() {
    local rawOut="$(time ($*) 2>&1 1>/dev/null )"
    local realTime="$(echo $rawOut | cut -d\s -f1)"
    local minuteDelim="$(echo $realTime | sed -n "s/[m].*//p" | wc -c )"
    local seconds="$(echo ${realTime:minuteDelim} )"
    local realMins="$(echo $realTime | cut -d\m -f1)"
    local spDelim="$(echo $realMins | sed -n "s/[' '].*//p" | wc -c )"
    local mins="$(echo ${realMins:spDelim} )"
    local minsec=$[$mins*60]
    local seconds="$(echo "$minsec+$seconds" | bc )"
    echo $seconds
}


function printHeadings() {
	echo " ,Seconds taken to sort array, , , , , , ," > ../result/RunTimesTable.csv
	local headings="Language"
	local exp="2"
	while [ $exp -lt 9 ]
		do
		headings="$headings,10^$exp integers"
		((exp++))
		done
	echo $headings >> ../result/RunTimesTable.csv
}

cd bin
printHeadings
i="0"
progCommands=( ./QsortC ./Qsort "java Qsort" ./Qsort.py "pypy Qsort.py" ./Qsort.php "jython -J-Xmx8000m Qsort.py" )
langs=(C C++ Java "Python 3" "PyPy2.2.1" PHP Jython)
while [ $i -lt ${#progCommands[@]} ]
	do
	printCell "$(echo ${progCommands[$i]} )" "$(echo ${langs[$i]} )"
	((i++))
	done
cd ..
