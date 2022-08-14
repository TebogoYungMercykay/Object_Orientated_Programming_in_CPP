#include "orderedContainer.h"
#include "linearStructure.h"

using namespace std;

template<class T>
OrderedContainer<T>::OrderedContainer(LinearStructure<T>* c)
{
	//cout<<"ordered container constructor\n";
	dataStructure=c;
	/*
	LinearStructure<T>*myDeleting=c->clone();
	dataStructure=c->clone();
	dataStructure->clear();
	int myIndex=0;
	int myNewIndex=0;
	T myData;
	while(!myDeleting->isEmpty())
	{
		cout<<"before"<<*myDeleting<<endl;
		myData=0;
		try { myData=myDeleting->remove(myIndex); } catch (const char * e) { myIndex=myIndex+1; }
		if(myData!=0)
		{
			dataStructure->insert(myNewIndex,myData);
			myNewIndex=myNewIndex+1;
				//myIndex=myIndex+1;
			cout<<"my current growing datastructure is "<<*dataStructure<<endl;
		}
		
	}*/
}

template<class T>
OrderedContainer<T>::OrderedContainer(const OrderedContainer<T>& other)
{
	dataStructure=other.dataStructure->clone();
}

template<class T>
OrderedContainer<T>& OrderedContainer<T>::operator=(const OrderedContainer<T>& other)
{
	delete dataStructure;
	dataStructure=other.dataStructure->clone();
	return *this;
}

template<class T>
OrderedContainer<T>::~OrderedContainer()
{
	dataStructure=NULL;
}

template<class T>
bool OrderedContainer<T>::isEmpty()
{
	
	if(dataStructure->isEmpty())
		return true;
	else 
		return false;
}

template<class T>
LinearStructure<T>* OrderedContainer<T>::getImplementation()
{
	LinearStructure<T>* myReturn=dataStructure->clone();
	//cout<<"is empty?"<<myReturn->isEmpty()<<endl;
	//cout<<"trying to output";
	//cout<<*myReturn;
	return myReturn;
}

