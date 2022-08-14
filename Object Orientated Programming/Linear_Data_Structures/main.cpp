#include <iostream>
#include "dynamicArray.h"
#include "dynamicArray.cpp"
#include "linkedList.h"
#include "linkedList.cpp"
#include "circularList.h"
#include "circularList.cpp"
#include "stack.h"
#include "stack.cpp"
#include "orderedContainer.cpp"
#include "queue.h"
#include "queue.cpp"
#include "priorityQueue.h"
#include "priorityQueue.cpp"

using namespace std;

void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();
void task8() ;
void task9() ;
void task10();
void task11();

int main()
{
    // Uncomment these as you implement the tasks.
  // task1(); //dynamic array
	
	
  // task2(); //linked list
	
	
  // task3(); //circular
	
   //task4();// stack
	//task7(); //stack
	
	
	// task5(); ///queue
	//task9() ;// queue
	//task8() ; //queue
	task10() ;//queue
	
   
   //task6(); //priority que
	//task11(); //priorityque
	
	
	
	
	
    // Add your own code for more thorough testing!
    // These examples will not be used on Fitchfork, but testing will be similar

    return 0;
}
	
void task1() {

    DynamicArray<int> arr1(1);
	
   DynamicArray<int> arr2(arr1);
   DynamicArray<int> arr3(5);
  arr3 = arr2;
 
      cout << arr1 << endl;
     cout << arr2 << endl;
    cout << arr3 << endl;

    cout << endl;

    arr1.insert(0,5);
   cout << arr1 << endl;

     arr2.insert(0,2);
    arr2.insert(0,7);
    cout << arr2 << endl;

    arr3.insert(1,8);
    cout << arr3 << endl;

    cout << endl;
  

    cout << arr2.get(1) << endl;
    cout << arr2.remove(0) << endl;
    cout << arr2 << endl;

    cout << endl;

    arr3.clear();
    //cout<<"here is array 3";
   // cout<<arr3<<endl;
    if(arr3.isEmpty()) cout << "Clear works correctly" << endl;
    cout << arr3 << endl;

    cout << endl;

    DynamicArray<int> * aPtr = arr2.clone();
    cout << *aPtr << endl;
    aPtr->insert(10,3);
    cout << *aPtr << endl;
    cout << arr2 << endl;
    delete aPtr;
    cout<<"new testing======================"<<endl;
    DynamicArray<int> myTest1(1);
    myTest1.insert(0,5);
    myTest1.insert(0,4);
    myTest1.insert(0,3);
    myTest1.insert(0,2);
    myTest1.insert(0,1);
    cout<<myTest1<<endl;
    cout<<"checking copy constructo======================"<<endl;
    DynamicArray<int> myTest2(myTest1);
    cout<<myTest2<<endl;
    cout<<"checking equals ======================"<<endl;
    DynamicArray<int> myTest3(1);
    myTest3=myTest2;
    cout<<myTest3<<endl;
 
    
}

/*
void task2() {
    LinkedList<char> list1;
    for(char i = 'a'; i < 'f'; i++) {
        list1.insert(0,i);
    }
    cout << list1 << endl;

    LinkedList<char> list2;
    for(char i = 'a', j = 0; i < 'f'; i++, j++) {
        list2.insert(j,i);
    }
    cout << list2 << endl;

    cout << endl;

    list1.remove(2);
    cout << list1 << endl;
    list1.remove(3);
    cout << list1 << endl;
    list1.remove(0);
    cout << list1 << endl;

    cout << endl;

    LinkedList<char> list3(list1);
    list2 = list1;

    list1.clear();
    if(list1.isEmpty()) cout << "Clear works correctly" << endl;
    cout << list1 << endl;
    cout << list2 << endl;
    cout << list3 << endl;
    cout << endl;

    Node<char> * node = list3.getLeader();
    node->element = 'z';
    cout << list3 << endl;
    cout << endl;

    LinkedList<char> * lPtr = list2.clone();
    cout << *lPtr << endl;
    cout << lPtr->get(0) << " " << lPtr->get(1) << endl;
    cout << *lPtr << endl;

    try { lPtr->get(10); } catch (const char * e) { cout << e << endl; }

    delete lPtr;
}
*/
/*
void task3() {
    CircularList<int> clist;
    cout << clist << endl;
    clist.insert(0,8);
    cout << clist << endl;
    clist.insert(1,5);
    cout << clist << endl;
    clist.insert(2,4);
    cout << clist << endl;
    clist.insert(0,0);
    cout << clist << endl;
    clist.insert(3,7);
    cout << clist << endl;
    clist.insert(5,9);
    cout << clist << endl;

    try { clist.insert(10,99); } catch (const char * e) { cout << e << endl; }

    cout << endl;

    CircularList<int> clist2(clist);

    cout << clist.remove(5) << ": " << clist <<  endl;
   cout << clist.remove(1) << ": " << clist << endl;
  cout << clist.remove(0) << ": " << clist << endl;;
 
    cout << endl;
	
   // cout << clist2 <<"this is the output"<< endl;
   // cout<<clist<<"before\n";
      clist = clist2;
   // cout<<clist<<"this is the output still"<< endl;
   clist2.clear();
     if(clist2.isEmpty()) cout << "Clear works correctly" << endl;
    cout << clist2 << endl;
    cout << clist << endl;
    cout << endl;

    CircularList<int> * cPtr = clist.clone();
    cout << *cPtr << endl;
      cout << cPtr->get(3) << " " << cPtr->get(0) << " " << cPtr->get(5) << endl;
   cout << *cPtr << endl;
   delete cPtr;
    
}
*/

void task4() 
{
	//cout<<"fuck";
    Stack<char> s1(new LinkedList<char>() );
    Stack<char> s2(new CircularList<char>() );
  Stack<char> s3(new DynamicArray<char>(1) );
	
	
    for(char i = 'a'; i < 'h'; i++) {
        s1.insert(i-25);
        s2.insert(i+5);
        s3.insert(i);
    }

    cout <<  *(s1.getImplementation()) << endl;
    cout <<  *(s2.getImplementation()) << endl;
    cout <<  *(s3.getImplementation()) << endl;

    cout << endl;

    s1.reverse();
    s2.reverse();
    s3.reverse();

    cout <<  *(s1.getImplementation()) << endl;
    cout <<  *(s2.getImplementation()) << endl;
    cout <<  *(s3.getImplementation()) << endl;

    cout << endl;

    while(!s1.isEmpty()) {
	cout << s1.remove() << ": " << *(s1.getImplementation()) << endl;

   }
    
    cout << endl;

   while(!s2.isEmpty()) {
        cout << s2.remove() << ": " << *(s2.getImplementation()) << endl;

    }
    cout << endl;

    while(!s3.isEmpty()) {
        cout << s3.remove() << ": " << *(s3.getImplementation()) << endl;
    }
    
}


void task5() {
    Queue<char> q1(new LinkedList<char>() );
    Queue<char> q2(new CircularList<char>() );
    Queue<char> q3(new DynamicArray<char>(1) );

    for(char i = 'a'; i < 'h'; i++) {
        q1.insert(i-15);
        q2.insert(i+3);
        q3.insert(i-32);
    }

    cout <<  *(q1.getImplementation()) << endl;
    cout <<  *(q2.getImplementation()) << endl;
    cout <<  *(q3.getImplementation()) << endl;

    cout << endl;

    q1.reverse();
    q2.reverse();
    q3.reverse();

    cout <<  *(q1.getImplementation()) << endl;
    cout <<  *(q2.getImplementation()) << endl;
    cout <<  *(q3.getImplementation()) << endl;

    cout << endl;

    while(!q1.isEmpty()) {
        cout << q1.remove() << ": " << *(q1.getImplementation()) << endl;
    }
    cout << endl;

    while(!q2.isEmpty()) {
        cout << q2.remove() << ": " << *(q2.getImplementation()) << endl;
    }
    cout << endl;
cout <<  *(q3.getImplementation()) << endl;
    while(!q3.isEmpty()) {
        cout << q3.remove() << ": " << *(q3.getImplementation()) << endl;
    }
}


void task6() {
    PriorityQueue<int> pq1(new LinkedList<int>() );
    PriorityQueue<int> pq2(new CircularList<int>() );
    PriorityQueue<int> pq3(new DynamicArray<int>(1) );

    pq1.insert(2);
    pq1.insert(5);
    pq1.insert(7);
    pq1.insert(1);
    pq1.insert(6);
    pq1.insert(3);
    pq1.insert(8);

    cout <<  *(pq1.getImplementation()) << endl;

    pq2.insert(1);
    pq2.insert(5);
    pq2.insert(3);
    pq2.insert(0);
    pq2.insert(2);
    pq2.insert(7);
    pq2.insert(4);

    cout <<  *(pq2.getImplementation()) << endl;

    pq3.insert(9);
    pq3.insert(1);
    pq3.insert(2);
    pq3.insert(6);
    pq3.insert(7);
    pq3.insert(3);
    pq3.insert(5);

    cout <<  *(pq3.getImplementation()) << endl;

    cout << endl;

    pq1.reverse();
    pq2.reverse();
    pq3.reverse();

    cout <<  *(pq1.getImplementation()) << endl;
    cout <<  *(pq2.getImplementation()) << endl;
    cout <<  *(pq3.getImplementation()) << endl;
    cout << endl;

    pq1.insert(25);
    pq1.insert(-1);

    pq2.insert(25);
    pq2.insert(-1);

    pq3.insert(25);
    pq3.insert(-1);

    cout <<  *(pq1.getImplementation()) << endl;
    cout <<  *(pq2.getImplementation()) << endl;
    cout <<  *(pq3.getImplementation()) << endl;
  
}
  
  void task7() 
{
    Stack<char> s1(new LinkedList<char>() );
    Stack<char> s2(new CircularList<char>() );
    Stack<char> s3(new DynamicArray<char>(1) );
	
	
    for(char i = 'a'; i < 'h'; i++) {
        s1.insert(i-25);
        s2.insert(i+5);
        s3.insert(i);
    }

    cout <<  *(s1.getImplementation()) << endl;
    cout <<  *(s2.getImplementation()) << endl;
    cout <<  *(s3.getImplementation()) << endl;
     cout<<"testing equals=========================="<<endl;
    s1=s2;
     cout <<  *(s1.getImplementation()) << endl;
    cout<<"testing second constructor=========================="<<endl;
     Stack<char> s4(s1);
    cout <<  *(s4.getImplementation()) << endl;
    cout<<"this is the head"<<s4.next()<<endl;
    cout<<"testing insert on stack =========================="<<endl;
    s4.insert('D');
    cout <<  *(s4.getImplementation()) << endl;
    

}
void task11()
{
	cout<<"myTesting======================================================================================"<<endl;
    PriorityQueue<int> q1(new LinkedList<int>() );
    PriorityQueue<int> q2(new CircularList<int>() );
    PriorityQueue<int> q3(new DynamicArray<int>(1) );
   PriorityQueue<int> q4(new DynamicArray<int>(1) );

    for(int i = 1; i < 10; i++) {
        q1.insert(i);
        q2.insert(i);
        q3.insert(i);
    }

    cout <<  *(q1.getImplementation()) << endl;
    cout <<  *(q2.getImplementation()) << endl;
    cout <<  *(q3.getImplementation()) << endl;
    cout<<"testing inserts of 1 5 9 and 3"<<endl;
	q1.insert(1);
	q1.insert(5);
        q1.insert(9);
	q1.insert(3);
    
        q2.insert(1);
        q2.insert(5);
	q2.insert(9);
        q2.insert(3);
    
        q3.insert(1);
	q3.insert(5);
        q3.insert(9);
        q3.insert(3);
    
           cout <<  *(q1.getImplementation()) << endl;
    cout <<  *(q2.getImplementation()) << endl;
    cout <<  *(q3.getImplementation()) << endl;
    cout<<"testing reverse==========================\n";
    q1.reverse();
    q2.reverse();
    q3.reverse();
               cout <<  *(q1.getImplementation()) << endl;
    cout <<  *(q2.getImplementation()) << endl;
    cout <<  *(q3.getImplementation()) << endl;
    cout<<"adding after reverse==========================\n";
    q1.insert(10);
    q1.insert(7);
    q2.insert(10);
    q2.insert(7);
    q3.insert(10);
    q3.insert(7);
                   cout <<  *(q1.getImplementation()) << endl;
    cout <<  *(q2.getImplementation()) << endl;
    cout <<  *(q3.getImplementation()) << endl;
  
    
     

}
  void task8() 
{
	cout<<"myTesting======================================================================================"<<endl;
    Queue<char> q1(new LinkedList<char>() );
    Queue<char> q2(new CircularList<char>() );
    Queue<char> q3(new DynamicArray<char>(1) );
   Queue<char> q4(new DynamicArray<char>(1) );

    for(char i = 'a'; i < 'h'; i++) {
        q1.insert(i-15);
        q2.insert(i+3);
        q3.insert(i-32);
    }

    cout <<  *(q1.getImplementation()) << endl;
    cout <<  *(q2.getImplementation()) << endl;
    cout <<  *(q3.getImplementation()) << endl;
    
     cout<<"testing equals=========================="<<endl;
    q4=q1;
     cout <<  *(q4.getImplementation()) << endl;
    q4=q2;
     cout <<  *(q4.getImplementation()) << endl;
    q4=q3;
     cout <<  *(q4.getImplementation()) << endl;
    Queue<char> blank(new DynamicArray<char>(1) );
    blank=q4;
    cout <<  *(blank.getImplementation()) << endl;
    
    cout<<"testing copy constructor=========================="<<endl;
     Queue<char> q5(q1);
    cout <<  *(q5.getImplementation()) << endl;
    Queue<char> q6(q2);
    cout <<  *(q6.getImplementation()) << endl;
    Queue<char> q7(q3);
    cout <<  *(q7.getImplementation()) << endl;
    
    cout<<"testing head function constructor=========================="<<endl;
    cout<<"this is the head"<<q5.next()<<endl;
    cout<<"this is the head"<<q6.next()<<endl;
    cout<<"this is the head"<<q7.next()<<endl;
    
    cout<<"testing insert on queue =========================="<<endl;
    q5.insert('F');
    q6.insert('F');
    q7.insert('S');
    cout <<  *(q5.getImplementation()) << endl;
    cout <<  *(q6.getImplementation()) << endl;
    cout <<  *(q7.getImplementation()) << endl;
    cout<<"testing remove on stack =========================="<<endl;
    q5.remove();
    q6.remove();
    q7.remove();
       q5.remove();
    q6.remove();
    q7.remove();
	cout <<  *(q5.getImplementation()) << endl;
    cout <<  *(q6.getImplementation()) << endl;
    cout <<  *(q7.getImplementation()) << endl;
    
        cout<<"testing insert on queue ===again======================="<<endl;
    q5.insert('F');
    q6.insert('F');
    q7.insert('S');
    cout <<  *(q5.getImplementation()) << endl;
    cout <<  *(q6.getImplementation()) << endl;
    cout <<  *(q7.getImplementation()) << endl;
    
cout<<"testing head function constructor=======again==================="<<endl;
    cout<<"this is the head"<<q5.next()<<endl;
    cout<<"this is the head"<<q6.next()<<endl;
    cout<<"this is the head"<<q7.next()<<endl;
    
cout<<"reverse==================="<<endl;
    q5.reverse();
    q6.reverse();
    q7.reverse();
        cout <<  *(q5.getImplementation()) << endl;
    cout <<  *(q6.getImplementation()) << endl;
    cout <<  *(q7.getImplementation()) << endl;
    cout<<"this is the head"<<q5.next()<<endl;
    cout<<"this is the head"<<q6.next()<<endl;
    cout<<"this is the head"<<q7.next()<<endl;

        cout<<"testing remove on stack ======again===================="<<endl;
    q5.remove();
    q6.remove();
    q7.remove();
       q5.remove();
    q6.remove();
    q7.remove();
	cout <<  *(q5.getImplementation()) << endl;
    cout <<  *(q6.getImplementation()) << endl;
    cout <<  *(q7.getImplementation()) << endl;
    cout<<"doing my own testing =============================\n";
    Stack<char> s3(new DynamicArray<char>(1) );
    cout <<  *(s3.getImplementation()) << endl;
    s3.insert('0');
    cout <<  *(s3.getImplementation()) << endl;
   
}
void task9() 
{
   Queue<char> q1(new DynamicArray<char>(1) );
    Queue<int> q2(new DynamicArray<int>(1) );
    //Queue<char> q3(new DynamicArray<char>(1) );
   //Queue<char> q4(new DynamicArray<char>(1) );
	cout<<"inserting 0 B C D E into second array\n";
	q1.insert('0');
	q1.insert('B');
	q1.insert('C');
	q1.insert('D');
	q1.insert('E');
	cout <<  *(q1.getImplementation()) << endl;
cout<<"inserting 0 1 2 3 4 0 into second array\n";
	q2.insert(0);
	q2.insert(1);
	q2.insert(2);
	q2.insert(3);
	q2.insert(4);
	q2.insert(0);
	cout <<  *(q2.getImplementation()) << endl;
	cout<<"removing 2 from each";
	q1.remove();
	q1.remove();
	q2.remove();
	q2.remove();
	cout <<  *(q1.getImplementation()) << endl;
	cout <<  *(q2.getImplementation()) << endl;

    //cout <<  *(q1.getImplementation()) << endl;
}
void task10()
{
	 
    Queue<char> q3(new DynamicArray<char>(1) );

    for(char i = 'a'; i < 'd'; i++) {
    q3.insert(i-32);
	   
    }
     cout<<*q3.getImplementation()<<endl;
	     while(!q3.isEmpty()) {
        cout << q3.remove() << ": " << *(q3.getImplementation()) << endl;
	     }
}
