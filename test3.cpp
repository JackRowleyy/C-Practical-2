#include <iostream>
using namespace std;
void mul_div(double* first, double* second) {
	double temp = (*first) * (*second);
	*second = (*first) / (*second);
	*first = temp;
}
int main() {

	double a = 5.0, b = 2.0;
	mul_div(&a, &b);
	cout << a << " " << b << endl;
	return 0;
}
