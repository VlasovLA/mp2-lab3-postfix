#pragma once

const int MaxMemSize = 100;
typedef int TElem;

class TQueue
{
private:
	TElem* pMem;
	int MemSize;
	int ElemCount;
	int Li;
	int Hi;
	int GetNextIndex(int index);

public:
	//TQueue();
	TQueue(int size);
	~TQueue();
	bool isEmpty(void);
	bool isFull(void);
	void Put(const TElem& Val);
	int ElCount();
	TElem Get(void);
};

enum class exc
{
	negative_value, too_large_intensity, too_large_queue, queue_is_empty, queue_is_full
};