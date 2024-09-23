#include <iostream>

using namespace std;

int main()
{
	const int dim {10};
	int vec[dim] {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
	int sum {};
	// versión con iteración "tradicional"
	// for (int i {}; i < dim; ++i)
	// 	sum += vec[i];
	// versión for-each
	for (auto dato: vec)
		sum += dato;
	cout << "La sumatoria da: " << sum << endl;
	return 0;
}
