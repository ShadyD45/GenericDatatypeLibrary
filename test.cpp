// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
// For testing library functions

#include "GenLib.cpp"
#include<iostream>

using namespace std;

class student
{
	private:
		string name;
		int rno;
	public:
		student()
		{
			name = "";
			rno = 0;
		}
		student(string nm, int no)
		{
			name = nm;
			rno = no;
		}
		
		int getRno()
		{
			return rno;
		}
		
		string getName()
		{
			return name;
		}
		
		void DisplayStudent()
		{
			cout<<"\t\tRno: "<<rno<<"\n";
			cout<<"\t\tName: "<<name<<"\n";
		}
};
int main()
{
	//------------------------------Singly Double type List-----------------------------//
	cout<<"-------------------------Singly Double type List---------------------------"<<endl;
	SinglyLL<double> *dList = new SinglyLL<double>();
	double no = 41.23;
	dList->InsertFirst(&no);
	dList->InsertFirst(&no);
	dList->InsertFirst(&no);
	dList->InsertFirst(&no);
	
	cout<<"List is: ";
	dList->Display();
	cout<<"Length of list: "<<dList->Count()<<"\n\n";
	
	no = 24.5;
	dList->InsertAt(&no, 3);
	cout<<"List after insert at 3: ";
	dList->Display();
	cout<<"Length of list: "<<dList->Count()<<"\n\n";
	
	dList->DeleteAt(2);
	cout<<"List after deleting at 2 position: ";
	dList->Display();
	cout<<"Length of list: "<<dList->Count()<<"\n\n";
	
	delete dList;
	
	
	//------------------------------Singly Character type List---------------------------------//
	cout<<"-------------------------Singly Character type  List---------------------------"<<endl;
	SinglyLL<char> *chList = new SinglyLL<char>();
	char ch = 'A';
	chList->InsertFirst(&ch);
	chList->InsertFirst(&ch);
	chList->InsertFirst(&ch);
	chList->InsertFirst(&ch);
	
	ch = 'B';
	cout<<"List is: ";
	chList->Display();
	cout<<"Length of list: "<<chList->Count()<<"\n\n";
	
	ch = 'R';
	chList->InsertAt(&ch, 3);
	cout<<"List after insert at 3: ";
	chList->Display();
	cout<<"Length of list: "<<chList->Count()<<"\n\n";
	
	ch = (*chList)[2];
	cout<<"Element at 2 (Using []): "<<ch<<endl<<endl;
	
	cout<<"Printing full list using []:";
	for(int i = 0; i < chList->Count(); ++i)
	{
		cout<<"\t"<<(*chList)[i];
	}
	
	chList->DeleteFirst();
	cout<<"\n\nList after deleting first: ";
	chList->Display();
	cout<<"Length of list: "<<chList->Count()<<"\n\n";
	
	
	chList->DeleteLast();
	cout<<"List after deleting Last: ";
	chList->Display();
	cout<<"Length of list: "<<chList->Count()<<"\n\n";
	
	delete chList;
	
	//------------------------------Singly Student type List----------------------------------//
	cout<<"-------------------------Singly Student type List---------------------------"<<endl;

	SinglyLL<student> *st1 = new SinglyLL<student>();
	
	student obj1("shubham", 1);
	student obj2("eminem", 2);
	student obj3("xyz", 3);
	student obj4("abc", 4);	

	st1->InsertFirst(&obj2);	// Passed address of object to be stored in list
	st1->InsertFirst(&obj1);
	st1->InsertLast(&obj3);
	st1->InsertAt(&obj4,2);
	
	cout<<"Printing student list using []:\n";
	for(int i = 0; i < st1->Count(); ++i)
	{
		(*st1)[i].DisplayStudent();
		cout<<endl;
	}
	
	cout<<"Length of student list: "<<st1->Count()<<"\n\n";

	delete st1;	
	
	//-------------------------Doubly List of float type--------------------------------//
	cout<<"-------------------------Doubly List of float type---------------------------"<<endl;
	DoublyLL<float> *fList = new DoublyLL<float>();
	float no1 = 5.3;
	fList->InsertFirst(&no1);
	fList->InsertFirst(&no1);
	fList->InsertFirst(&no1);
	fList->InsertFirst(&no1);
	
	cout<<"List is: ";
	fList->Display();
	cout<<"Length of list: "<<fList->Count()<<"\n\n";
	
	no1 = 2.5;
	fList->InsertAt(&no1, 3);
	cout<<"List after insert at 3: ";
	fList->Display();
	cout<<"Length of list: "<<fList->Count()<<"\n\n";
	
	fList->DeleteAt(2);
	cout<<"List after deleting at 2 position: ";
	fList->Display();
	cout<<"Length of list: "<<fList->Count()<<"\n\n";
	
	delete fList;
	
	
	//------------------------------Doubly List of char type---------------------------//
	cout<<"-------------------------Doubly List of Char type---------------------------"<<endl;
	DoublyLL<char> *chList_1 = new DoublyLL<char>();
	ch = 'A';
	chList_1->InsertFirst(&ch);
	chList_1->InsertFirst(&ch);
	chList_1->InsertFirst(&ch);
	chList_1->InsertFirst(&ch);
	
	cout<<"List is: ";
	chList_1->Display();
	cout<<"Length of list: "<<chList_1->Count()<<"\n\n";
	
	char ch1 = 'R';
	chList_1->InsertAt(&ch1, 3);
	cout<<"List after insert at 3: ";
	chList_1->Display();
	cout<<"Length of list: "<<chList_1->Count()<<"\n\n";
	
	char ch2 = (*chList_1)[2];
	cout<<"Element at 2 (Using []): "<<ch2<<endl<<endl;
	
	cout<<"Printing full list using []:";
	for(int i = 0; i < chList_1->Count(); ++i)
	{
		cout<<"\t"<<(*chList_1)[i];
	}
	
	chList_1->DeleteFirst();
	cout<<"\n\nList after deleting first: ";
	chList_1->Display();
	cout<<"Length of list: "<<chList_1->Count()<<"\n\n";
	
	
	chList_1->DeleteLast();
	cout<<"List after deleting Last: ";
	chList_1->Display();
	cout<<"Length of list: "<<chList_1->Count()<<"\n\n";
	
	delete chList_1;
	
	//-------------------------Doubly List of Student type---------------------------------//
	cout<<"-------------------------Doubly List of Student type---------------------------"<<endl;
	DoublyLL<student> *st2 = new DoublyLL<student>();
	//DoublyLL<student> st2;
	
	st2->InsertFirst(&obj2);	// Passed address of object to be stored in list
	st2->InsertFirst(&obj1);
	st2->InsertLast(&obj3);
	st2->InsertAt(&obj4,2);
	
	cout<<"Printing student list using []:\n";
	for(int i = 0; i < st2->Count(); ++i)
	{
		(*st2)[i].DisplayStudent();
		cout<<endl;
	}
	
	cout<<"Length of student list: "<<st2->Count()<<"\n\n";
	
	
	//-------------------------String Stack---------------------------//
	cout<<"-------------------------String Stack---------------------------"<<endl;
	Stack<string> *chStack = new Stack<string>();
	string str = "Shubham";
	chStack->Push(&str);
	chStack->Push(&str);
	chStack->Push(&str);
	str = "XYZ";
	chStack->Push(&str);
	chStack->Push(&str);
	
	cout<<"Stack is:\n";
	chStack->Display();
	cout<<"Size of stack: "<<chStack->Count()<<"\n\n";
	
	string chRet = chStack->Pop();
	cout<<"Popped element is: "<<chRet<<"\n";
	cout<<"Size of stack: "<<chStack->Count()<<"\n\n";
	
	cout<<"Stack is:\n";
	chStack->Display();
	str = "ABC";
	chStack->Push(&str);
	cout<<"Stack after pushin "<<str<<":\n";
	chStack->Display();
	cout<<"Size of stack: "<<chStack->Count()<<"\n\n";
	
	cout<<"Element at top: "<<chStack->Peek()<<"\n";
	cout<<"Size of stack: "<<chStack->Count()<<"\n\n";
	
	delete chStack;
	
	//-------------------------Float Stack--------------------------//
	cout<<"-------------------------Float Stack---------------------------"<<endl;
	
	Stack<float> *fStack = new Stack<float>();
	float fNo = 51.2;
	fStack->Push(&fNo);
	fStack->Push(&fNo);
	fStack->Push(&fNo);
	fNo = 71.2;
	fStack->Push(&fNo);
	fStack->Push(&fNo);
	
	cout<<"Stack is:\n";
	fStack->Display();
	cout<<"Size of stack: "<<fStack->Count()<<"\n\n";
	
	float fRet = fStack->Pop();
	cout<<"Popped element is: "<<fRet<<"\n";
	cout<<"Size of stack: "<<fStack->Count()<<"\n\n";
	
	cout<<"Stack is:\n";
	fStack->Display();
	
	fNo = 34.4;
	fStack->Push(&fNo);
	cout<<"Stack after pushing "<<fNo<<"\n";
	fStack->Display();
	cout<<"Size of stack: "<<fStack->Count()<<"\n\n";
	
	cout<<"Element at top: "<<fStack->Peek()<<"\n";
	cout<<"Size of stack: "<<fStack->Count()<<"\n\n";
	
	delete fStack;	
	
	//-------------------------Float Queue--------------------------//
	cout<<"-------------------------Float Queue---------------------------"<<endl;
	Queue<float> *fQueue = new Queue<float>();
	fNo = 51.2;
	fQueue->Enqueue(&fNo);
	fQueue->Enqueue(&fNo);
	fNo = 123.4;
	fQueue->Enqueue(&fNo);
	fNo = 34.2;
	fQueue->Enqueue(&fNo);
	
	cout<<"Queue is: ";
	fQueue->Display();
	cout<<"Size of Queue: "<<fQueue->Count()<<"\n";
	
	fRet = fQueue->Dequeue();
	cout<<"\nDequeue element is: "<<fRet<<"\n";
	cout<<"Size of Queue: "<<fQueue->Count()<<"\n";
	
	cout<<"Queue is: ";
	fQueue->Display();
	fNo = 23.3;
	fQueue->Enqueue(&fNo);
	cout<<"\nQueue after inserting "<<fNo<<": ";
	fQueue->Display();
	cout<<"Size of Queue: "<<fQueue->Count()<<"\n";
	
	cout<<"\nElement at front: "<<fQueue->Front()<<"\n";
	cout<<"Size of Queue: "<<fQueue->Count()<<"\n";
	
	fRet = fQueue->Dequeue();
	cout<<"\nDequeue element is: "<<fRet<<"\n";
	cout<<"Size of Queue: "<<fQueue->Count()<<"\n";
	
	cout<<"Queue is: ";
	fQueue->Display();

	fRet = fQueue->Dequeue();
	cout<<"\nDequeue element is: "<<fRet<<"\n";
	cout<<"Size of Queue: "<<fQueue->Count()<<"\n";
	
	cout<<"Queue is: ";
	fQueue->Display();
	
	fRet = fQueue->Dequeue();
	cout<<"\nDequeue element is: "<<fRet<<"\n";
	cout<<"Size of Queue: "<<fQueue->Count()<<"\n";
	
	cout<<"Queue is: ";
	fQueue->Display();
	
	fRet = fQueue->Dequeue();
	cout<<"\nDequeue element is: "<<fRet<<"\n";
	cout<<"Size of Queue: "<<fQueue->Count()<<"\n";
	fRet = fQueue->Dequeue();

	delete fQueue;
	
	return 0;
}
