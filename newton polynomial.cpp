#include <iostream>
using namespace std;
//implementation of diveded difference
double div_diff(int arr_x[], int arr_y[], int size) {
	 double div_diffVal = 0;
		 if (size > 0) {
			 //computing the value of div_diff in the given dimention of array
			 for (int j = 0; j < size; j++)
			 {
				 int mul = 1;

				 for (int i = 0; i < size;i++) { //calculation of the denominator
					 if (i != j) 
						 mul *= (arr_x[j] - arr_x[i]);
				 }

				 div_diffVal += static_cast<double>(arr_y[j]) / mul;
			 }
			 return div_diffVal;
		 }
		 else cout << "dim < 0\n";return 1;
	 
}

double nt_pol(int* arr_x, int* arr_y, int size) {
	int k;
	int index;
	cout << "Enter the index of the 1st array: ";
	cin >> index;

	double sum = 0;

	for (k = 1; k < size; k++)
	{
		double div_diffVal = 0;

			//computing the value of div_diff in the given dimention of array
			for (int j = 0; j < k + 1; j++)
			{
				int mul = 1;

				for (int i = 0; i < k + 1;i++) { //calculation of the denominator
					if (i != j)
						mul *= (arr_x[j] - arr_x[i]);
				}

				div_diffVal += static_cast<double>(arr_y[j]) / mul;
			}

			double term = 1;
		for (int i = 0; i < k; i++)
		{
			term *= arr_x[index] - arr_x[i];
		}

		sum+= div_diffVal * term;
	}
	return arr_y[0] + sum;
}
	int main() {
		int x[] = { 0, 2, 3 };
		int y[] = { 0, 1, 3 };
		for (int i = 0; i < 3; i++) {
			cout << "Result: " << nt_pol(x, y, 3) << endl;
		}
	return 3;
}
