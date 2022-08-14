#include "linkedList.h"
#include "orderedContainer.h"
#include "queue.h"
#include "priorityQueue.h"
using namespace std;

template<class T>
PriorityQueue<T>::PriorityQueue(LinearStructure<T>* c):Queue<T>::Queue(c)
{
	Queue<T>::front=0;
	ascend=true;
}

template<class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T>& other):Queue<T>::Queue(other.PriorityQueue<T>::dataStructure->clone())
{
	ascend=other.ascend;
}

template<class T>
PriorityQueue<T>& PriorityQueue<T>::operator=(const PriorityQueue<T>& other)
{
	ascend=other.ascend;
	PriorityQueue<T>::front=other.PriorityQueue<T>::front;
	PriorityQueue<T>::rear=other.PriorityQueue<T>::rear;
	PriorityQueue<T>::dataStructure=other.PriorityQueue<T>::dataStructure->clone();
	return *this;
}

template<class T>
PriorityQueue<T>::~PriorityQueue()
{
	
}

template<class T>
void PriorityQueue<T>::insert(T el)
{
	int iIndex=0;
	bool bAdded=false;
	if(ascend==true)
	{
		while(iIndex<PriorityQueue<T>::rear&&bAdded==false)
		{
			if(PriorityQueue<T>::dataStructure->get(iIndex)>el)
			{
				Queue<T>::dataStructure->insert(iIndex,el);
				bAdded=true;
			}
			iIndex=iIndex+1;
		}
		if(bAdded==false)
			Queue<T>::dataStructure->insert(PriorityQueue<T>::rear,el);
	}else
	{
		while(iIndex<PriorityQueue<T>::rear&&bAdded==false)
		{
			if(PriorityQueue<T>::dataStructure->get(iIndex)<el)
			{
				Queue<T>::dataStructure->insert(iIndex,el);
				bAdded=true;
			}
			iIndex=iIndex+1;
		}
		if(bAdded==false)
			Queue<T>::dataStructure->insert(PriorityQueue<T>::rear,el);
	}
	
	PriorityQueue<T>::rear=PriorityQueue<T>::rear+1;
}

template<class T>
void PriorityQueue<T>::reverse()
{
	if (ascend==true)
		ascend=false;
	else
		ascend=true;
	Queue<T>::reverse();
}

