#include <iostream>
using namespace std;
bool bAddArrays(char*& pchs, int& size, char* pchs2, int size2) {
	
	char* pchsNEW = NULL;
	if ((pchsNEW = new char[size + size2]) == NULL) {
		return false;
	}
	for (int i = 0; i < size; i++) {
		pchsNEW[i] = pchs[i];
	}
	delete pchs;
	for (int i = 0; i < size; i++) {
		pchsNEW[size + i] = pchs2[i];
	}
	pchs = pchsNEW;
	size += size2;
	return true;
}


bool bResizeArray(int*& pi, int& size, int sizeNew)
{
	// allocate new array 
	int* piNew = NULL;
	if (sizeNew <= 0 || (piNew = new int[sizeNew]) == NULL)
		return false;   // resize fails 
	// if expanding, initialise the new tail to zero 
	if (sizeNew > size) {
		for (int i = 0; i < size; i++)
			piNew[i] = pi[i];
		for (int i = size; i < sizeNew; i++)
			piNew[i] = 0;
	}
	// if shrinking, erase the tail contents 
	else {
		for (int i = 0; i < sizeNew; i++)
			piNew[i] = pi[i];
	}

	// delete old array 
	delete[] pi;

	// point pi to the new array, and update size to sizeNew 
	pi = piNew;
	size = sizeNew;

	// resize successful 
	return true;
}

int main()
{
	// old array 
	int size = 10;
	int* pi = new int[size];
	for (int i = 0; i < size; i++)
		pi[i] = i;
	for (int i = 0; i < size; i++)
		cout << pi[i] << " ";
	cout << endl;

	// expanding 
	if (bResizeArray(pi, size, 20)) {
		for (int i = 0; i < size; i++)
			cout << pi[i] << " ";
		cout << endl;
	}

	// shrinking 
	if (bResizeArray(pi, size, 5)) {
		for (int i = 0; i < size; i++)
			cout << pi[i] << " ";
		cout << endl;
	}
	delete[] pi;

	return 0;
}

// free array memory 