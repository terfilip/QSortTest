#!/usr/local/bin/python3

def extract_times():
	timeList = []
	timeFile = open("times", "r")
	for i in range(0, 35):
		timef = '{num:.{dpoints}f}'.format(num= float(timeFile.readline()) / 10, dpoints=4)
		timeList.extend([timef])
	timeFile.close()
	return timeList
def print_times(timeList):
	timesTable = open("RunTimesTable.csv", "w")
	for i in range(0, 35):
		timesTable.write(str(timeList[i]))
		if(((i+1) % 7) == 0):
			timesTable.write("\n")
		else:
			timesTable.write(",")
print_times(extract_times())
