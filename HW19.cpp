#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int maxDel(int a, int b);
int NOD(int n1, int n2);
int resurveNumber(int a);
template <typename T> T sortArray(T arr[], int length, T a);
template <typename T> void showArray(T arr[], int length, int a, int b);
template <typename T> void showArr(T arr[], int length);

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int n, m;

	//Задача 1
	cout << "Задача 1.\nВведите два числа: ";
	cin >> n >> m;	
	cout << "Наибольший общий делитель чисел " << n << " и " << m << " - число " << maxDel(n, m) << ".\n\n"; // Решение с помощью цикла
	//cout << "Наибольший общий делитель чисел " << n << " и " << m << " - число " << NOD(n, m) << ".\n\n"; // Решение с помощью рекурсии
	
	// Задача 2
	cout << "Задача 2.\n";
	cout << "Введите число: ";
	cin >> n;
	cout << "Число " << n << " в отражённом виде = " << resurveNumber(n) << ".\n\n";

	// Задача 3
	cout << "Задача 3.\n";
	int z3[10] = { 2, 5, 6, 3, 1, 7, 19, 15, 18, 8 };
	showArr(z3, 10);
	cout << "Введите число: ";
	cin >> n;
	cout << sortArray(z3, 10, n) << endl;
	showArr(z3, 10);
	cout << endl;

	//Задача 4
	cout << "Задача 4.\nВведите начало и конец диапазона массива: ";
	cin >> n >> m;
	int z4[10];
	showArray(z4, 10, n, m);
	cout << endl;

	return 0;
} 
//Задача 1 (Решение с помощью цикла)
int maxDel(int a, int b) {
	if (a == b)
		return a;
	if (a > b)
		for (int i = b; i > 1; i--)
			if (a % i == 0 && b % i == 0)
				return i;
	if (a < b)
		for (int i = a; i > 1; i--)
			if (a % i == 0 && b % i == 0)
				return i;
}
//Задача 1 (Решение с помощью рекурсии)
int NOD(int n1, int n2) {
	int div, d;
	if (n1 == n2)
		return n1;
	d = n1 - n2;
	if (d < 0) {
		d = -d;
		div = NOD(n1, d);
	}
	else {
		div = NOD(n2, d);
	}
	return div;
}
// Задача 2
int resurveNumber(int a) {
	int firstNumber = 0;
	do {
		firstNumber = firstNumber * 10 + a % 10;
		a /= 10;
	} while (a != 0);
	return firstNumber;
}
// Задача 3
template <typename T> T sortArray(T arr[], int length, T a) {	
	int key;
	for (int i = 0; i < length; i++)
		if (arr[i] == a) {
			key = i;
			break;
		}

	sort(arr + key + 1, arr + length);

	cout << "Первая позиция числа " << a << " в массиве = ";
	return key;
}
// Задача 4
template <typename T> void showArray(T arr[], int length, int a, int b) {
	cout << "[";
	for (int i = 0; i < length; i++) {
		arr[i] = rand() % (b - a) + a;
		cout << arr[i] << ", ";
	}
	cout << "\b\b]\n";
}
// Вывод массива
template <typename T> void showArr(T arr[], int length) {
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}