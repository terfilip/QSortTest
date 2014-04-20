#!/bin/bash

seconds_sum="0"
i="0"
while [ $i -lt 10 ]
	do
	raw_out="$(time ($*) 2>&1 1>/dev/null )"
	#echo "time output"
	#echo $raw_out
	real_time="$(echo $raw_out | cut -d\s -f1)"
	#echo "real time"
	#echo $real_time
	minute_delim="$(expr index "$real_time"  m )"
	seconds="$(echo ${real_time:minute_delim} )"
	#echo "number of seconds w/o mins"
	#echo $seconds
	real_mins="$(echo $real_time | cut -d\m -f1)"
	#echo "minutes w/o secs"
	#echo $real_mins
	sp_delim="$(expr index "$real_mins" ' ' )"
	mins="$(echo ${real_mins:sp_delim} )"
	#echo "just mins"
	#echo $mins
	minsec=$[$mins*60]
	seconds="$(echo "$minsec+$seconds" | bc )"
	#echo "The total number of seconds is"
	#echo $seconds
	seconds_sum="$(echo "$seconds_sum+$seconds" | bc )"
	((i++))
	done
echo $seconds_sum >> times #Outputs the sum of all 10 runs to a file, another program will handle it later
