#include <io.h> //  _setmode
#include <fcntl.h> // _O_U16TEXT
#include <iostream>
using namespace std;


const int LIMIT = 100; 


class safearray
{
private:
	int arr[LIMIT];
public:
	
	int& operator[] (int n)
	{
		if (n < 0 || n >= LIMIT)
			{ wcout << L"Ошибочный индекс!"; exit(1); }
		return arr[n];
	}
};


class safehilo : public safearray
{
private:
	int lowerbound; 
	int upperbound; 
public:
	
	safehilo(int low, int up) : lowerbound(low), upperbound(up)
	{
		
		if (lowerbound > upperbound)
			{ wcout << L"Ошибка! Верхняя граница индекса массива не может быть меньше нижней.\n"; exit(1); }
		if (upperbound - lowerbound >= LIMIT)
			{ wcout << L"Ошибка! В массиве не может быть больше " << LIMIT << L" элементов.\n"; exit(1); }
	}
	
	int& operator[] (int n)
	{
		if (n < lowerbound || n > upperbound)
			{ wcout << L"Ошибочный индекс!"; exit(1); }
		return safearray::operator[] (n - lowerbound);
		
	}
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	int low, up; // для верхней и нижней границ индекса массива

	wcout << L"Введите нижнюю границу индекса массива : "; wcin >> low;
	wcout << L"Введите верхнюю границу индекса массива: "; wcin >> up;

	safehilo sa1(low, up);

	// задаем значения элементов
	for (int j = low; j <= up; j++)
		// используем функцию слева от знака присваивания (=)
		sa1[j] = j * 10;

	// показываем элементы
	for (int j = low; j <= up; j++)
	{
		// используем функцию справа от знака присваивания (=)
		int temp = sa1[j];
		wcout << L"Элемент " << j << L" равен " << temp << endl;
	}

	return 0;
}