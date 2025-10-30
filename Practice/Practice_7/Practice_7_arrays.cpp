#include <iostream>

using namespace std;

void calculateMax(const int* arr, int size, int& max) {
	max = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
}

void findArrayWithMaxValue(const int* arrA, const int* arrB, int sizeA, int sizeB) {
	int maxA = 0, maxB = 0;

	calculateMax(arrA, sizeA, maxA);
	calculateMax(arrB, sizeB, maxB);

	if (maxA > maxB) {
		for (int i = 0; i < sizeA; i++) {
			if (arrA[i] == maxA) {
				cout << "Массив A содержит наибольшее значение " << maxA << " с порядковым номером " << i + 1 << endl;
				cout << "Элементы массива A: " << endl;
				for (int j = 0; j < sizeA; j++) {
					cout << arrA[j] << " ";
				}
			}
		}
	}
	else {
		for (int i = 0; i < sizeB; i++) {
			if (arrB[i] == maxB) {
				cout << "Массив B содержит наибольшее значение " << maxB << " с порядковым номером " << i + 1 << endl;
				cout << "Элементы массива B: " << endl;
				for (int j = 0; j < sizeB; j++) {
					cout << arrB[j] << " ";
				}
			}
		}
	}
	cout << endl;
}

int main() {
	setlocale(LC_CTYPE, "rus");

	int sA = 5;
	int sB = 4;

	int* A = new int[sA];
	int* B = new int[sB];

	cout << "Введите " << sA << " элементов для массива A: " << endl;
	for (int i = 0; i < sA; i++) {
		cin >> A[i];
	}
	cout << "Введите " << sB << " элементов для массива B: " << endl;
	for (int i = 0; i < sB; i++) {
		cin >> B[i];
	}

	findArrayWithMaxValue(A, B, sA, sB);

	delete[] A;
	delete[] B;

	cout << "Нажмите Enter для завершения программы...";
	cin.get();
	cin.get();

	return 0;
}
