##Files for my QuickSort test

- Sources
- Shell script for timing
- Checking program
- CSV writing script

####Instructions for Running the Test

0. Download all programs from the repo
0. Compile everything:
	* javac *.java
	* gcc CheckSort -o CheckSort.c
	* gcc -O2{or 3} QsortC -o QsortC.c
	* g++ -O2{or 3} Qsort -o Qsort.cc
0. Make scripts executable:
	* chmod +x *.py
	* chmod +x Qsort.php
	* chmod +x TestTime.sh
0. Create files with random numbers:
	* java GenRandFile
0. Run the test, and wait for a long time:
	* ./TestTime.sh
0. View Results:
	* cat RunTimesTable.csv
	* Can be opened with Excel or Calc
0. To test sorting uncomment printing functions in Qsort files, and execute them.
0. Check the output files if they were sorted:
	* ./CheckSort 10e{power of 10}sorted{language}.txt
	