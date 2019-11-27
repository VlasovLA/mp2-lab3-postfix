#include "TProc.h"
#include <iostream>

using namespace std;

bool TProc::RunNewTask()
{
	TJob job = JobStream.GetNewTask();
	if (job == -1) 
		return false;
	taskNumb = job;
	tacts_remain_for_task = job % 3;
	if(detailed)
		cout << "������ � " << completedTasks + 1 << ": ������ ���������� - ���� " << tactsCount;
	return true;
}

bool TProc::IsProcFree()
{
	return tacts_remain_for_task == 0;
}

void TProc::Processing()
{
	if (tacts_remain_for_task)
		tacts_remain_for_task--;


	if (tacts_remain_for_task == 0 && taskNumb != -1)
	{
		if (detailed)
			cout << ".  ����� ���������� - ���� " << tactsCount << endl;
		completedTasks++;
		taskNumb = -1;
	}
}

TProc::TProc(int intens, int cycles, int size, bool det):JobStream(size, intens)
{
	tacts_remain_total = cycles;
	taskNumb = -1;
	tacts_remain_for_task = 0;
	if (cycles < 0)
		throw exc::negative_value;
	tasksNotTaken = 0; 
	freeTacts = 0; 
	completedTasks = 0; 
	tactsCount = 0;
	detailed = det;
}

int TProc::Proc_Tick()
{
	tactsCount++;
	if (!JobStream.GenerateNewTask())
		tasksNotTaken++;
	if (IsProcFree() && !RunNewTask())
		freeTacts++;
	Processing();
	if (tacts_remain_total == 1)
	{
		missedTasks = JobStream.MissedTasks();
		if (!IsProcFree())
		{
			if (detailed)
				cout << ".  �� ���������." << endl;
			missedTasks--;
		}
	}
	//if (JobStream.MissedTasks)
	return --tacts_remain_total;
}

void TProc::TotalStatistics()
{
	int total = completedTasks + tasksNotTaken + missedTasks;
	cout.precision(2);
	cout << "��������� ��������� � ������������:" << endl
		<< "������� ������������� �����: " << total << endl;
	cout << "������� ����������� �����: " << completedTasks 
		<< "(" << (float)(completedTasks * 100) / total << "%)" << endl;

	cout << "������� ��������� �����: " << tasksNotTaken + missedTasks
		<< "(" << (float)((tasksNotTaken + missedTasks) * 100) / total << "%)" << endl;

	cout << "������� ��������� �� �� �������� ����� � �������: " << tasksNotTaken
		<< "(" << (float)(tasksNotTaken * 100) / total << "%)" << endl;

	cout << "������� ��������� �� �� ��������� ������: " << missedTasks
		<< "(" << (float)(missedTasks * 100) / total << "%)" << endl;

	cout << "���������� ������ �������: " << freeTacts
		<< "(" << (float)(freeTacts * 100 / tactsCount) << "%)" << endl;

	cout << "������� ���������� ������ �� �������: " 
		<< (float)(tactsCount - freeTacts) / completedTasks << endl;
}
