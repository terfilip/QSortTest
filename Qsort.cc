#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

void quicksort(int *a, int left, int right);
int partition(int *a, int left, int right, int pivotIdx);
void swap(int *a, int x, int y);
void array_init(int *a, string filename);
//void array_print(int *a, string filename, int size);
int pow_ten(int idx);

int main(int argc, char *argv[])
{
	if(argc != 2) {
		cout << "Usage: ./Qsort <powerOfTen>" << endl;
		return 0;
	}
	const int IDX = atoi(argv[1]);
	const int SIZE = pow_ten(IDX);
	int *a = new int[SIZE];
	ostringstream iName;
	//ostringstream oName;
	
	iName << "10e" << IDX << ".txt";
	//oName << "10e" << IDX << "sortedC++.txt";
	
	string inputFile = iName.str();
	//string outputFile = oName.str();
	
	array_init(a, inputFile);		
	quicksort(a, 0, SIZE - 1);
	cout << "Sorted "<< SIZE <<" integers in C++." << endl;
	//To Test Sorting
	//array_print(a, outputFile, SIZE);
	delete[] a;
	return 0;
}

void array_init(int *a, string filename)
{
	ifstream iF (filename.c_str());
	string line; 
	int i = 0;
	while (getline(iF,line)) {
		istringstream(line) >> a[i++];
	}
	iF.close();
}
/*  
void array_print(int *a, string filename, int size)
{
	ofstream oF (filename.c_str());
	for (int i = 0; i < size; i++) {
		oF << a[i] << endl;
	}
	oF.close();
}
*/


void quicksort (int *a, int left, int right)
{
	if (left < right) {
			int pivotIdx = left + ((right - left)/2);
			int newPivotIdx = partition(a, left, right, pivotIdx);
			quicksort(a, left, newPivotIdx -1);
			quicksort(a, newPivotIdx + 1, right);
		}
}

int partition(int *a, int left, int right, int pivotIdx)
{
	int pivotVal = a[pivotIdx];
	swap(a, pivotIdx, right);
	int storeIdx = left; int i;
	for(int i = left; i < right; i++) {
		if(a[i] < pivotVal) {
			swap(a, i, storeIdx++);
		}
	}
	swap(a, storeIdx, right);
	return storeIdx;
}

void swap(int *a, int x, int y)
{
	int tmp = a[x];
	a[x] = a[y];
	a[y] = tmp;
}

/*Own function to avoid using 
 * library version in each language
 */
int pow_ten(int idx)
{
	if (idx == 0) 
	    return 1;
	else 
	    return 10 * pow_ten(idx - 1);
}
