#include "linkedList.h"
#include "orderedContainer.h"
#include "queue.h"
using namespace std;

template<class T>
Queue<T>::Queue(LinearStructure<T>* c):OrderedContainer<T>::OrderedContainer(c)
{
	front=0;
	rear=0;
	T myData=0;
	//bool btest=false;

	
	//getting rear of array
	LinearStructure<T>* myDeleting=c->clone();
	rear=0;
	int icount=0;
	while(!myDeleting->isEmpty())
	{
		myData=0;
		try { myData=myDeleting->remove(icount); } catch (const char * e) { icount=icount+1; rear=rear+1;}
		if(myData!=0)
				rear=rear+1;
	}
	//front=0;
	//cout<<"so my front is"<<front<<endl;
	//cout<<"so my rear is"<<rear<<endl;
}

template<class T>
Queue<T>::Queue(const Queue<T>& other):OrderedContainer<T>::OrderedContainer(other.Queue<T>::dataStructure->clone())
{
	front=other.front;
	rear=other.rear;
}

template<class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
	front=other.front;
	rear=other.rear;
	Queue<T>::dataStructure=other.Queue<T>::dataStructure->clone();
	return *this;
}

template<class T>
Queue<T>::~Queue()
{

}

template<class T>
T Queue<T>::remove()
{
	T myTemp= Queue<T>::dataStructure->remove(front);
	rear--;
	return myTemp;
}

template<class T>
T Queue<T>::next()
{
	return Queue<T>::dataStructure->get(front);
}

template<class T>
void Queue<T>::insert(T el)
{
	//cout<<"inserting "<<el<<" into index "<<rear<<endl;
	Queue<T>::dataStructure->insert(rear,el);
	//cout<<"current index is"<<stackTop<<endl;
	rear=rear+1;
}

template<class T>
void Queue<T>::reverse()
{
	int myStackCount=rear;//,myInsertIndex=0;
	LinearStructure<T>* myTempHolder=Queue<T>::dataStructure->clone();
	myTempHolder->clear();
	T myData;
	bool myTest=true;
	//cout<<"got here";
	while(!Queue<T>::dataStructure->isEmpty()&&rear>0)
	{
		myTest=true;
		try { myData=Queue<T>::dataStructure->remove(rear-1); } catch (string * e) {rear=rear-1;myTest=false;}
		if(myTest==true)
		{
			myTempHolder->insert(myStackCount-rear,myData);
			rear=rear-1;
		}
		
	}
	Queue<T>::dataStructure=myTempHolder;
	rear=myStackCount;
}


