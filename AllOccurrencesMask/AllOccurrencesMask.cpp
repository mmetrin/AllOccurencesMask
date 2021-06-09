// AllOccurrencesMask.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int result[100];
int rp = 0;
char input[255], mask[255];
int ms;


void RecFindOfMask(bool bollres, int i, int j, bool nword);
void FindOfMask(int i);
void SizeOfMask();
int SizeOfInp(int i);

void end();



int main()
{
	std::cout << "Hello World!\n";

	std::cout << "Write your string: ";
	std::cin.getline(input, 255);
	std::cout << "Write your mask: ";
	std::cin.getline(mask, 255);
	SizeOfMask();
	result[0] = -2;
	FindOfMask(0);
	std::cout << "Result is ";
	int i = 0;
	while (rp > 1)
	{
		std::cout << result[i] << ", ";
		i++;
		rp--;
	}
	std::cout << result[i] << std::endl;
}

void RecFindOfMask(bool bollres, int i, int j, bool nword)
{
	if (input[i] == '\0' || input[i] == ' ')
	{
		bool ended = false;
		while (mask[j] != '\0')
		{
			if (mask[j] != '*')
			{
				if (!nword) rp--;
				if (input[i] == ' ') FindOfMask(i + 1);
				else end();
				ended = true;
				break;
			}
			j++;
		}
		if (!ended)
		{
			if (input[i] == ' ') FindOfMask(i + 1);
			else end();
		}
	}
	else if (mask[j] == '\0')
	{
		if (mask[j - 1] == '*')
		{
			while (input[i] != ' ' && input[i] != '\0') i++;
			if (input[i] == ' ') FindOfMask(i + 1);
			else end();
		}
		else
		{
			if (!nword) rp--;
			while (input[i] != ' ' && input[i] != '\0') i++;
			if (input[i] == ' ') FindOfMask(i + 1);
			else end();
		}
	}
	else if (mask[j] == '*')
	{
		if (nword) result[rp++] = i;
		RecFindOfMask(true, i, j + 1, false);
	}
	else if (mask[j] == '?')
	{
		if (bollres)
		{
			if (mask[j + 1] == '\0')
			{
				while (input[i] != ' ' && input[i] != '\0') i++;
				if (input[i] == ' ') FindOfMask(i + 1);
				else end();
			}
			else return RecFindOfMask(true, i + 1, j + 1, nword);
		}
		else
		{
			if (nword) result[rp++] = i;
			RecFindOfMask(false, i + 1, j + 1, false);
		}
	}
	else if (mask[j] == input[i])
	{
		if (nword) result[rp++] = i;
		RecFindOfMask(false, i + 1, j + 1, false);
	}
	else if (bollres) return RecFindOfMask(true, i + 1, j, nword);
	else
	{
		bool found = false;
		while (j >= 0)
		{
			if (mask[j] == '*')
			{
				found = true;
				break;
			}
			j--;
		}
		if (found) return RecFindOfMask(true, i + 1, j + 1, nword);
		else
		{
			while (input[i] != ' ' && input[i] != '\0') i++;
			if (input[i] == ' ') FindOfMask(i + 1);
			else end();
		}
	}
}

void FindOfMask(int i)
{
	int inps = SizeOfInp(i);
	if (ms > inps)
	{
		if (input[i + inps] == ' ')
		{
			i += inps;
			FindOfMask(i);
		}
		else end();
	}
	else RecFindOfMask(false, i, 0, true);
}

void SizeOfMask()
{
	int i = 0;
	ms = 0;
	while (mask[i] != '\0')
	{
		if (mask[i] != '*')
			ms++;
		i++;
	}
}

int SizeOfInp(int i)
{
	int size = 0;
	while (input[i] != ' ' && input[i] != '\0')
	{
		i++;
		size++;
	}
	return size;
}

void end()
{
	if (rp == 0)
	{
		result[0] = -1;
		rp++;
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
