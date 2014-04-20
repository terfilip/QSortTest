/* Note that the size for the strings is 11,
 * because the program is used on files that contain
 * numbers that are at most 10 digits long(max number of digits for int32)
 * + null terminator. So the program will not work on numbers greater
 * than 10 digits, unless modified. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define numChars 12

void file_check(char * filename)
{
	FILE *toCheck = fopen(filename, "r");
	if(!toCheck) {
		puts("File not found");
		return;
	}
	char line[numChars], nextLine[numChars];
	fgets(line, numChars, toCheck);
	int i = 2, sorted = 1;
	while(fgets(nextLine, numChars, toCheck) != NULL) {
		if(atoi(line) > atoi(nextLine)) {
			printf("%s is NOT SORTED. Error at lines %d and %d.\n",filename, i, i-1);
			sorted = 0;
			break; 
		}
		memcpy(line, nextLine, sizeof(nextLine));
		i++;
	}
	fclose(toCheck);
	if (sorted) {
		printf("The file %s contains sorted values.\n",filename);
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		puts("usage: ./CheckSort <filename>");
		return 0;
	}
	file_check(argv[1]);
	return 0;
}

