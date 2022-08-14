#include "linearStructure.h"
#include "orderedContainer.h"

#include "stack.h"



using namespace std;

template<class T>
Stack<T>::Stack(LinearStructure<T>* c) :OrderedContainer<T>::OrderedContainer(c)
{
	//cout<<"stack constructor\n";
	stackTop=0;
	//cout<<*OrderedContainer<T>::dataStructure;
	//cout<<*Stack<T>::dataStructure;
	//orderedContainer(c);
	//Stack<T>::dataStructure=c;
}

template<class T>
Stack<T>::Stack(const Stack<T>& other):OrderedContainer<T>::OrderedContainer(other.Stack<T>::dataStructure->clone())
{
	stackTop=other.stackTop;
	Stack<T>::dataStructure=other.Stack<T>::dataStructure->clone();
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
	stackTop=other.stackTop;
	delete 	Stack<T>::dataStructure;
	Stack<T>::dataStructure=other.Stack<T>::dataStructure->clone();
	return *this;
}

template<class T>
Stack<T>::~Stack()
{
	//delete Stack<T>::dataStructure;
}

template<class T>
T Stack<T>::remove()
{
	
	T myTemp= Stack<T>::dataStructure->remove(stackTop-1);
	stackTop--;
	return myTemp;
	
}

template<class T>
T Stack<T>::next()
{
	return Stack<T>::dataStructure->get(stackTop-1);
	
}

template<class T>
void Stack<T>::insert(T el)
{
	//cout<<"the input is "<<el<<endl;
	//cout<<"current index is"<<stackTop<<endl;
	Stack<T>::dataStructure->insert(stackTop,el);
	//cout<<"current index is"<<stackTop<<endl;
	stackTop=stackTop+1;
}

template<class T>
void Stack<T>::reverse()
{
	int myStackCount=stackTop;//,myInsertIndex=0;
	LinearStructure<T>* myTempHolder=Stack<T>::dataStructure->clone();
	myTempHolder->clear();
	//T myData;
	
	
	while(!Stack<T>::dataStructure->isEmpty()&&stackTop>0)
	{
		//cout<<"at index"<<stackTop-1<<endl;
		//T myData=Stack<T>::dataStructure->remove(stackTop-1);
		
		//cout<<"my data is "<<myData<<endl;
		myTempHolder->insert(myStackCount-stackTop,Stack<T>::dataStructure->remove(stackTop-1));
		stackTop=stackTop-1;
	}
	Stack<T>::dataStructure=myTempHolder;
	stackTop=myStackCount;
	
		
}


   
