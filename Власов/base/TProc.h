#pragma once
#include "TQueue.h"
#include "TJobStream.h"


class TProc
{
private:
	TJob taskNumb; 
	int tacts_remain_for_task; 
	int tacts_remain_total;
	TJobStream JobStream; 

	void Processing();
	bool RunNewTask();
	bool IsProcFree();
	bool detailed;
	int tasksNotTaken;
	int missedTasks;
	int freeTacts;
	int completedTasks;
	int tactsCount;

public:
	TProc(int intens, int tacts, int size, bool det);
	int Proc_Tick();
	void TotalStatistics();

};
