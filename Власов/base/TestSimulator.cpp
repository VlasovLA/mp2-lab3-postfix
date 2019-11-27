#include <iostream>
#include <ctime>
#include <locale>
#include "TQueue.h"
#include "TProc.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	int answer = 1, intensity, cycles, size;
	while (answer != 0)
	{
		try
		{
			cout << "Введите интенсивность потока задач (0-100%): ";
			cin >> intensity;
			cout << "Введите количество циклов симуляции: ";
			cin >> cycles;
			cout << "Введите размер очереди задач ( max " << MaxMemSize << " ): ";
			cin >> size;
			do
			{
				cout << "Выберите режим работы:" << endl
					<< "1 - Краткий" << endl
					<< "2 - Подробный ( описывается каждая выполняемая задача )" << endl;
				cin >> answer;
			} while (answer != 1 && answer != 2);
			TProc sample(intensity, cycles, size, answer-1);
			while (sample.Proc_Tick());
			do
			{
				cout << endl << "Выберите:" << endl
					<< "1 - Показать итоговую статистику" << endl
					<< "2 - Начать новую симуляцию" << endl
					<< "0 - Выход" << endl;
				cin >> answer;
				cout << endl;
			} while (answer != 0 && answer != 1 && answer != 2);
			if (answer == 1)
			{
				sample.TotalStatistics();
				do
				{
				cout << endl << "Выберите:" << endl
					<< "1 - Начать новую симуляцию" << endl
					<< "0 - Выход" << endl;
				} while (answer != 0 && answer != 1);
				cin >> answer;
				cout << endl;
			}
		}
		catch (const exc ex)
		{
			switch (ex)
			{
			case exc::negative_value:
				cout << "Введены недопустимые отрицательные значения" << endl;
				break;
			case exc::too_large_intensity:
				cout << "Введено слишком большое значение интенсивоности потока задач ( max "<< MaxMemSize << " )" << endl;
				break;
			case exc::too_large_queue:
				cout << "Введен недопустимо большой размер очереди" << endl;
				break;
			default:
				break;
			}
		}

	}
	return 0;
}