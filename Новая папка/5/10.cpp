#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

int gcount = 0; // глобальная переменная для счетчика

void counter1(); // прототипы функций
void counter2();

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	int ncount; // количество раз, которое будут вызываться функции

	wcout << L"Введите количество раз, которое будут вызываться функции: "; wcin >> ncount;
	for (int i = 1; i <= ncount; i++)
	{
		counter1(); wcout << endl;
		counter2(); wcout << endl;
	}

	return 0;
}

// функция выводит на экран количество раз, которое она вызывалась,
// с помощью глобальной переменной
void counter1()
{
	gcount++;
	wcout << gcount << L"-й вызов функции counter1, ранее вызывалась " << gcount - 1 << L" раз";
}

// функция выводит на экран количество раз, которое она вызывалась,
// с помощью статической локальной переменной
void counter2()
{
	static int lcount = 0; // инициализация при первом вызове
	lcount++;
	wcout << lcount << L"-й вызов функции counter2, ранее вызывалась " << lcount - 1 << L" раз";
}
