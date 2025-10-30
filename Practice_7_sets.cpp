#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

void getSetDifference(const set<int>& setA, const set<int>& setB, set<int>& result) {
	set_difference(setA.begin(), setA.end(), setB.begin(), setB.end(), inserter(result, result.begin()));
}

void findMaxElement(const set<int>& setA, const set<int>& setB, set<int>& result) {
	int max = 0;

	getSetDifference(setA, setB, result);
	for (int elem : result) {
		if (elem > max) {
			max = elem;
		}
	}

	cout << "Максимальный элемент разницы множеств A и B: " << max << endl;

}

int main() {
	setlocale(LC_CTYPE, "rus");

	int sA, sB;

	cout << "Введите размер множества A: ";
	cin >> sA;
	cout << "Введите размер множества B: ";
	cin >> sB;

	set<int>* stA = new set<int>;
	set<int>* stB = new set<int>;

	set<int>* res = new set<int>;

	int temp_elem;
	cout << "Введите " << sA << " элементов множества A:" << endl;
	for (int i = 0; i < sA; i++) {
		cin >> temp_elem;
		stA -> insert(temp_elem);
	}
	cout << "Введите " << sB << " элементов множества B:" << endl;
	for (int i = 0; i < sB; i++) {
		cin >> temp_elem;
		stB -> insert(temp_elem);
	}	

	findMaxElement(*stA, *stB, *res);

	delete stA;
	delete stB;

	cout << "Нажмите Enter для завершения программы...";
	cin.get();
	cin.get();

	return 0;
}