#pragma once
#include "TQueue.h"

typedef int TJob;

class TJobStream
{
private:
	double StreamIntensity;
	TQueue queue; 
	
public:
	TJobStream(int size, int intens);
	//TJobStream();
	TJob GetNewTask();
	bool GenerateNewTask();
	int MissedTasks();
};

int RandomNumber(int min, int max);
bool Random(int percent);