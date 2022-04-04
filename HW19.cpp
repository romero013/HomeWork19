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

	//������ 1
	cout << "������ 1.\n������� ��� �����: ";
	cin >> n >> m;	
	cout << "���������� ����� �������� ����� " << n << " � " << m << " - ����� " << maxDel(n, m) << ".\n\n"; // ������� � ������� �����
	//cout << "���������� ����� �������� ����� " << n << " � " << m << " - ����� " << NOD(n, m) << ".\n\n"; // ������� � ������� ��������
	
	// ������ 2
	cout << "������ 2.\n";
	cout << "������� �����: ";
	cin >> n;
	cout << "����� " << n << " � ��������� ���� = " << resurveNumber(n) << ".\n\n";

	// ������ 3
	cout << "������ 3.\n";
	int z3[10] = { 2, 5, 6, 3, 1, 7, 19, 15, 18, 8 };
	showArr(z3, 10);
	cout << "������� �����: ";
	cin >> n;
	cout << sortArray(z3, 10, n) << endl;
	showArr(z3, 10);
	cout << endl;

	//������ 4
	cout << "������ 4.\n������� ������ � ����� ��������� �������: ";
	cin >> n >> m;
	int z4[10];
	showArray(z4, 10, n, m);
	cout << endl;

	return 0;
} 
//������ 1 (������� � ������� �����)
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
//������ 1 (������� � ������� ��������)
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
// ������ 2
int resurveNumber(int a) {
	int firstNumber = 0;
	do {
		firstNumber = firstNumber * 10 + a % 10;
		a /= 10;
	} while (a != 0);
	return firstNumber;
}
// ������ 3
template <typename T> T sortArray(T arr[], int length, T a) {	
	int key;
	for (int i = 0; i < length; i++)
		if (arr[i] == a) {
			key = i;
			break;
		}

	sort(arr + key + 1, arr + length);

	cout << "������ ������� ����� " << a << " � ������� = ";
	return key;
}
// ������ 4
template <typename T> void showArray(T arr[], int length, int a, int b) {
	cout << "[";
	for (int i = 0; i < length; i++) {
		arr[i] = rand() % (b - a) + a;
		cout << arr[i] << ", ";
	}
	cout << "\b\b]\n";
}
// ����� �������
template <typename T> void showArr(T arr[], int length) {
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}