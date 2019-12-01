#include "TQueue.h"

TQueue::TQueue(int size)
{
	if (size < 0) 
		throw exc::negative_value;
	if (size > MaxMemSize) 
		throw exc::too_large_queue;
	if (size == 0) 
		size = MaxMemSize;

	ElemCount = 0;
	MemSize = size;
	pMem = new TElem[MemSize];
	Hi = -1;
	Li = 0;
}

int TQueue::GetNextIndex(int index)
{
	return (++index) % MemSize;
}

TQueue::~TQueue()
{
	delete[] pMem;
}

bool TQueue::isEmpty(void)
{
	return ElemCount == 0;
}

bool TQueue::isFull(void)
{
	return ElemCount == MemSize;
}

void TQueue::Put(const TElem & Val)
{
	if (isFull()) throw exc::queue_is_full;
	Hi = GetNextIndex(Hi);
	pMem[Hi] = Val;
	ElemCount++;
}

TElem TQueue::Get(void)
{
	if (isEmpty()) throw exc::queue_is_empty;
	TElem tmp = pMem[Li];
	Li = GetNextIndex(Li);
	ElemCount--;
	return tmp;
}

int TQueue:: ElCount()
{
	return ElemCount;
}