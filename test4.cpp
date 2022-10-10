#include <iostream>
using namespace std;

int search(char* pchs, int size, char key) {
	int count = 0;
	for (int n = 0; n < size; n++) {
		if (pchs[n] == key) {
			count++;
		}
	
	}
	for (int n = 0; n < size; n++) {
		if (*pchs++ == key) {
			count++;
		}
	}
}
int main() {
	int size = 0;
	char key = 0;
	cout << "Set the size";
	cin >> size;
	cout << "set the key";
	cin >> key;
	char* pchs = new char[size];
	if (pchs != NULL) {
		for (int n = 0; n < size; n++) {
			pchs[n] = 97 + rand() % 26;
			cout << pchs[n] << " ";
		}
		cout << endl;
		cout << "Occurances = " << search(pchs, size, key) << endl;

	}
	delete[] pchs;
	return 0;
}