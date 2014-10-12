#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

const int STRING_BUFFER = 24;

void quicksort(int *a, int left, int right);
int partition(int *a, int left, int right, int pivotIdx);
void array_init(int *a, char * filename);
void array_print(int *a, char *filename, int size);
int pow_ten(int idx);

int main(int argc, char *argv[]) {
	if((argc < 2) || (argc > 3)) {
		cout << "Usage: ./Qsort <powerOfTen> {if print}--print" << endl;
		return 0;
	}
	const int IDX = atoi(argv[1]);
	const int SIZE = pow_ten(IDX);

	char inputFile[STRING_BUFFER];
	sprintf(inputFile, "%s%d%s", "10e",IDX, ".txt");
	char outputFile[STRING_BUFFER];
	sprintf(outputFile, "%s%d%s", "10e",IDX, "sortedC++.txt");

	int *a = new int[SIZE];
	array_init(a, inputFile);
	quicksort(a, 0, SIZE - 1);
	//To Test Sorting
	if ((argc == 3) && (strcmp(argv[2],"--print") == 0)) {
		array_print(a, outputFile, SIZE);
	}
	delete[] a;
	cout << "Sorted "<< SIZE <<" integers in C++." << endl;
	return 0;
}

void array_init(int *a, char *filename) {
	FILE *iF = fopen(filename, "r");
	char line[STRING_BUFFER]; int i = 0;
	while (fgets(line, STRING_BUFFER, iF) != NULL) {
		a[i++] = atoi(line);
	}
	fclose(iF);
}

void array_print(int *a, char *filename, int size) {
	FILE *oF = fopen(filename, "w");
	for (int i = 0; i < size; i++) {
		fprintf(oF,"%d\n", a[i]);
	}
	fclose(oF);
}

void quicksort (int *a, int left, int right) {
	if (left < right) {
			int pivotIdx = left + ((right - left)/2);
			int newPivotIdx = partition(a, left, right, pivotIdx);
			quicksort(a, left, newPivotIdx -1);
			quicksort(a, newPivotIdx + 1, right);
		}
}

int partition(int *a, int left, int right, int pivotIdx) {
	int pivotVal = a[pivotIdx];
	swap(a[pivotIdx], a[right]);
	int storeIdx = left;
	for(int i = left; i < right; i++) {
		if(a[i] < pivotVal) {
			swap(a[i], a[storeIdx++]);
		}
	}
	swap(a[storeIdx], a[right]);
	return storeIdx;
}

/*Own function to avoid using
 * library version in each language
 */
int pow_ten(int idx) {
	if (idx == 0)
	    return 1;
	else
	    return 10 * pow_ten(idx - 1);
}
