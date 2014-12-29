#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_BUFFER 16

void arrayInit(int *a, char *filename);
void arrayPrint(int *a, char *filename, int size);
void quicksort(int *a, int left, int right);
int partition(int *a, int left, int right, int pivotIdx);
void swap(int *a, int x, int y);
int powTen(int idx);

int main(int argc, char *argv[]) {
	if((argc < 2) || (argc > 3)) {
		printf("Usage: ./QsortC <powerOfTen>\n");
		return 0;
	}
	int idx = atoi(argv[1]);
	const int SIZE = powTen(idx);

	char inputFile[STRING_BUFFER];
	char outputFile[STRING_BUFFER];
	sprintf(inputFile, "%s%d%s", "10e", idx, ".txt");
	sprintf(outputFile, "%s%d%s", "10e", idx, "sortedC.txt");

	int *a = malloc(SIZE * sizeof(int));
	arrayInit(a, inputFile);
	quicksort(a, 0, SIZE - 1);
	//Used to test sorting
	if ((argc == 3) && (strcmp(argv[2], "--print")== 0))
		arrayPrint(a, outputFile, SIZE);
	free(a);
	printf("Quicksorted %d ints in C\n",SIZE);
	return 0;
}

void arrayInit(int *a, char *filename) {
	FILE *iF = fopen(filename, "r");
	char line[STRING_BUFFER]; int i = 0;
	while (fgets(line, STRING_BUFFER, iF) != NULL)
		a[i++] = atoi(line);
	fclose(iF);
}

void arrayPrint(int *a, char *filename, int size) {
	FILE *oF = fopen(filename, "w");
	int i;
	for (i = 0; i < size; i++) {
		fprintf(oF,"%d\n", a[i]);
	}
	fclose(oF);
}

void quicksort (int *a, int left, int right) {
	if (left < right) {
			int pivotIdx = left + ((right - left) / 2);
			int newPivotIdx = partition(a, left, right, pivotIdx);
			quicksort(a, left, newPivotIdx -1);
			quicksort(a, newPivotIdx + 1, right);
	}
}

int partition(int *a, int left, int right, int pivotIdx) {
	int pivotVal = a[pivotIdx];
	swap(a, pivotIdx, right);
	int storeIdx = left; int i;
	for(i = left; i < right; i++)
		if(a[i] < pivotVal)
			swap(a, i, storeIdx++);
	swap(a, storeIdx, right);
	return storeIdx;
}

void swap(int *a, int x, int y) {
	int tmp = a[x];
	a[x] = a[y];
	a[y] = tmp;
}

int powTen(int idx) {
	if (idx == 0)
		return 1;
	else
		return 10 * powTen(idx - 1);
}
