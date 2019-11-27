#include "TJobStream.h"
#include <ctime>
#include <cstdlib>

TJobStream::TJobStream(int size, int intens) : queue(size)
{
	if (intens < 0)
		throw exc::negative_value;
	if (intens > 100)
		throw exc::too_large_intensity;
	StreamIntensity = intens;
	srand(static_cast<unsigned int>(time(0)));
}

/*TJobStream::TJobStream()
{
	queue = TQueue();
	StreamIntensity = 0;
}*/

TJob TJobStream::GetNewTask()
{
	if (queue.isEmpty()) 
		return -1;
	return queue.Get();
}

bool TJobStream::GenerateNewTask()
{
	if (Random(StreamIntensity))
	{
		if (queue.isFull()) 
			return false;
		TJob job = RandomNumber(0, 4);
		queue.Put(job);
		return true;
	}
	else 
		return true;
}


int TJobStream::MissedTasks()
{
	return (queue.ElCount());
}

int RandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

bool Random(int percent)
{
	return (RandomNumber(0, 100) <= percent);
}
