#include <iostream>

using namespace std;

/*
Написать рекурсивную функцию, которая
выводит N звезд в ряд, число N задает пользователь. 
*/
void f1(int N) {
	if (N > 0) {
		cout << '*';
		f1(N - 1);
	}
}

/*
Написать рекурсивную функцию, которая
вычисляет сумму всех чисел в диапазоне от a до b. 
Пользователь вводит a и b.
*/

int f2(int a, int b) {
	if (a < b)
		return a + f2(a + 1, b);
	else if (a > b)
		return a + f2(a - 1, b);
	else
		return a;
}

/*
Напишите рекурсивную функцию, которая
принимает одномерный массив из 100 целых чисел заполненных 
случайным образом и находит позицию, с которой начинается 
последовательность из 10 чисел,
сумма которых минимальна.
*/
const int SIZE = 100;

int f3(int arr[]) {
	static int glob_index = 0;

	int sum = 0;
	for (int i = glob_index; i < 10 + glob_index; i++) {
		sum += arr[i];
	}

	static int index = 0;
	int sum1 = 0;
	for (int i = index; i < 10 + index; i++) {
		sum1 += arr[i];
	}

	if (sum < sum1) {
		sum1 = sum;
		index = glob_index;
	}
	glob_index++;
	if (glob_index < 90)
		f3(arr);

	return index;
}
/*
Написать перегруженные функции и протестировать их в основной программе:
■ Нахождения максимального значения в одномерном массиве;
■ Нахождения максимального значения в двумерном массиве;
■ Нахождения максимального значения в трёхмерном массиве;
■ Нахождения максимального значения двух целых;
■ Нахождения максимального значения трёх целых.
*/
/*
template <typename T>
T max_elem(T arr[], int s) {
	T max = arr[0];
	for (int i = 1; i < s; i++) {
		if (max < arr[i]) max = arr[i];
	}
	return max;
}

template <typename T>
T max_elem(T arr[][10], int s, int k) {
	T max = arr[0][0];
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < k; i++) {
			if (max < arr[i][j]) max = arr[i][j];
		}
	}
	return max;
}

template <typename T>
T max_elem(T arr[][2][10], int s, int k, int h) {
	T max = arr[0][0][0];
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < k; i++) {
			for (int t = 0; t < h; t++)
			if (max < arr[i][j][t]) max = arr[i][j][t];
		}
	}
	return max;
}

int max_elem(int a, int b) {
	return a > b ? a : b;
}

int max_elem(int a, int b, int c) {
	return (a > b && a > c) ? a : (b > c) ? b : c;
}*/


int main()
{
	int arr[SIZE];
	for (int i = 0; i < SIZE; i++) {
		arr[i] = rand() % 10;
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << f3(arr);

}