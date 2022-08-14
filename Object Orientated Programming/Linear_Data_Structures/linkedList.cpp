#include "linkedList.h"
//#include "linearStructure.h"
//#include <iostream>
using namespace std;



//freind of the class
template<class T>
ostream& operator<< (ostream &myOut,LinkedList<T> &myList)
{
	cout<<"we made it to the output but my god where is it";
	myOut<<"[";
	if(myList.head==NULL)
	{
		myOut<<"]";
	}
	else
	{
		Node<T> * myPointer=myList.head;
		while(myPointer)
		{
			myOut<<myPointer->element;
			if(myPointer->next!=NULL)
				myOut<<",";
			myPointer=myPointer->next;
		}
		myOut<<"]";
	}
	return myOut;
}
//These are all class functions and not friends of  class---------------------------------------------------------------------------
template<class T>
LinkedList<T>::LinkedList()
{
	 head=NULL;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other)
{
	
	if(other.head==NULL)
	{
		head=NULL;
	}
	else
	{
		//setting head to the same as the copy list
		T myTempData=other.head->element;
		Node<T>* myNewNode=new Node<T>(myTempData);
		head=myNewNode;
		//copying the rest of the nodes from the list
		Node<T>* myPointer=other.head->next;
		Node<T>* myPrevious=myNewNode;
		while(myPointer)
		{
			
			myTempData=myPointer->element;
			myNewNode=new Node<T>(myTempData);
			myPrevious->next=myNewNode;
			myPointer=myPointer->next;
			myPrevious=myPrevious->next;
	
		}
	}
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
{
	Node<T>* myCopyFrom=other.head;
	Node<T>* myCopyToo=head;
	if(myCopyFrom==NULL)
	{
		head=NULL; //check if this works or if we need to delete the nodes
		return *this;
	}
	else
	{
		if(head==NULL)
		{
			head=new Node<T>(other.head->element);
			myCopyToo=head;
		}
		while(myCopyFrom)
		{
			if(myCopyFrom->element!=myCopyToo->element)
				myCopyToo->element=myCopyFrom->element;
			
			if(myCopyFrom->next==NULL)
				myCopyToo->next=NULL;
			else if(myCopyFrom->next!=NULL&&myCopyToo->next==NULL)
				myCopyToo->next=new Node<T>(1);
			
			myCopyFrom=myCopyFrom->next;
			myCopyToo=myCopyToo->next;
		}
	}
	return *this;
}

template<class T>
LinkedList<T>* LinkedList<T>::clone()
{
	//cout<<"in clone ";
	//cout<<"this is what the list currently holds\n";
	//print(cout);
	LinkedList<T> * myLinkedList=new LinkedList(*this);
	return myLinkedList;
}

template<class T>
LinkedList<T>::~LinkedList()
{
	Node<T> * myCurrent=head;
	Node<T> * myNext;
	
	while(myCurrent!=nullptr)
	{
		myNext=myCurrent->next;
		myCurrent->next=nullptr;
		delete myCurrent;
		myCurrent=myNext;
	}
	head=NULL;
	
}

template<class T>
void LinkedList<T>::insert(int index, T element)
{
	//cout<<"index is"<<index<<":and we are adding "<<element<<endl;
	//cout<<"size is : "<<size();
	if((head==NULL)&&(index==0))
	{
		head=new Node<T>(element);
		//cout<<"first is success";
	}
	else if(head==NULL&&index!=0)
		throw "invalid index";
		//cout<<"1111111111111";
	else if(index<0||index>size())
	{
		throw "invalid index";
		//cout<<"222222222";
	}
	else if(index==0)
	{
		//cout<<"3333333333";
		Node<T>* myNewNode=new Node<T>(element);
		myNewNode->next=head;
		head=myNewNode;
	}
	else
	{
		Node<T>* myPointer=head;
		Node<T>* myNewNode=NULL;
		for(int i=0;i<index-1;i++)
		{
			myPointer=myPointer->next;
		}
		
		myNewNode=new Node<T>(element);
		myNewNode->next=myPointer->next;
		myPointer->next=myNewNode;
		
	}
	//cout<<"end";
}
	

template<class T>
T LinkedList<T>::remove(int index)
{
	//cout<<"in linked remove the index is"<<index<<endl;
	if(index<0||index>=size())
		throw "empty structure";
	else if(index==0)
	{
		Node<T>* myPointer=head->next;
		head->next=NULL;
		T myPassData=head->element;
		//delete head;
		head=myPointer;
		return myPassData;
		
	}else
	{
		Node<T>* myPointer=head;
		Node<T>* myPrevious=NULL;
		for(int i=0;i<index;i++)
		{
			myPrevious=myPointer;
			myPointer=myPointer->next;
		}
		T myPassData=myPointer->element;
		myPrevious->next=myPointer->next;
		myPointer->next=NULL;
		//delete myPointer; not sure if we need this
		return myPassData;
		
	}
}

template<class T>
T LinkedList<T>::get(int index) const
{
	if(head==NULL)
		throw "empty structure";
	else if(index<0||index>=size())
	{
		throw "empty structure";
	}
	else
	{
		Node<T>* myPointer=head;
		for(int i=0;i<index;i++)
		{
			myPointer=myPointer->next;
		}
		return myPointer->element;
	}
}

template<class T>
bool LinkedList<T>::isEmpty()
{
	if(head==NULL)
		return true;
	else
		return false;
}

template<class T>
void LinkedList<T>::clear()
{
	head=NULL;
}

template<class T>
Node<T>* LinkedList<T>::getLeader()
{
	return head;
}

template<class T>
ostream& LinkedList<T>::print(ostream& os)
{
	os<<"[";
	if(head==NULL)
	{
		os<<"]";
	}
	else
	{
		Node<T> * myPointer=head;
		while(myPointer)
		{
			os<<myPointer->element;
			if(myPointer->next!=NULL)
				os<<",";
			myPointer=myPointer->next;
		}
		os<<"]";
	}
	
	return os;
}

template<class T>
int LinkedList<T>::size() const
{
	int icount=0;
	if(head==NULL)
		return 0;
	Node<T>* myPointer=head;
	while(myPointer)
	{
		icount++;
		myPointer=myPointer->next;
	}
	return icount;
}