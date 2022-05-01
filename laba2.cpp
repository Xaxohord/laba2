#include <iostream>
#include <algorithm>
#include <cmath>
#include <conio.h>
#include <chrono>
#include <cstdlib>
#include <ctime> 
#define N 10000
using namespace std;

int a[N];
int b[N];
class Timer
{
private:
	// Псевдонимы типов используются для удобного доступа к вложенным типам
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer() : m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

void int_massiv()
{
	// определяем переменные

	int i;

	srand(time(0)); // инициализация генерации случайных чисел

	//генерируем целый случайный массив из 10 эелментов от 1 до 5
	for (i = 0; i < N - 1; i++) {
		a[i] = 1 + rand() % 1000;
		//a[i] = i;
		b[i] = a[i];
	}


	//for (i = 0; i < 999; i++)
	//	cout << a[i] << " "; // вывод результата на экране
}
void quicksort(int a, int b, int x[N]) {

	if (a >= b) {
		return;
	}
	int m = (a + b) / 2;
	int k = x[m];
	int l = a - 1;
	int r = b + 1;
	while (true) {
		do { l++; } while (x[l] < k);
		do { r--; } while (x[r] > k);
		if (l >= r) {
			break;
		}
		int tmp = x[r];
		x[r] = x[l];
		x[l] = tmp;
	}
	r++;
	l = l - 1;
	quicksort(a, l, x);
	quicksort(r, b, x);

}

void BUBBLESORT(int mas[N], int n)
{
	for (int i = 1; i < n; i++)
	{
		if (mas[i] >= mas[i - 1])
			continue;
		int j = i - 1;
		while (j >= 0 && mas[j] > mas[j + 1])
		{
			std::swap(mas[j], mas[j + 1]);
			j--;
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int_massiv();
	Timer t;
	BUBBLESORT(a, N);
	cout << "Время для бабл: " << t.elapsed() << endl;
	//for (int i = 0; i < N; i++) {
	//			cout << b[i] << endl;
	//		}
	Timer d;
	quicksort(0, N - 1, b);
	cout << "Время для куиксорте: " << d.elapsed() << endl;
	//for (int i = 0; i < N; i++) {
	//			cout << a[i] << endl;
	//		}
	system("pause");
}

