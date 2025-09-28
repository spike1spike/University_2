#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	float x, y;
	cout << "Введите число x: ";
	cin >> x;
	cout << "Введите число y: ";
	cin >> y;

	float R = (sqrt(pow(x, 2) + pow(y, 2))) * sin(x);
	float S = exp(x / y);

	cout << "Число R: " << R << "\n";
	cout << "Число S: " << S << "\n";

	float C = max(R, S);
	cout << "Число C: " << C << "\n";

	cout << "Нажмите Enter для завершения программы...";
	cin.get();
	cin.get();
	return 0;
}