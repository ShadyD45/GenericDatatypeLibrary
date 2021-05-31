#pragma once

using namespace std;

//============================================Singly Linked List Declaration==========================================================//

template <class T>
struct GENNODE_SLL
{
	//T* pData;			
	T data;				// To store primitive datatypes (But is able to store userdefined datatypes too)
	struct GENNODE_SLL<T> *next;
};

template <class T>
class SinglyLL
{
	private:
		struct GENNODE_SLL<T> *Head;
		int iSize;
	public:
		SinglyLL();		// Constructor
		~SinglyLL();	// Destructor
		void Display();
		int  Count();
		void InsertFirst(T*);
		void InsertLast(T*);
		void InsertAt(T*, int);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAt(int);
		T& operator [](int);
};

//============================================Singly Linked List Declaration End==========================================================//

template <class T>
struct GENNODE_SCLL
{
	//T* pData;
	T data;
	struct GENNODE_SCLL<T> *next;
};

template <class T>
class SinglyCLL
{
	private:
		struct GENNODE_SCLL<T> *Head;
		struct GENNODE_SCLL<T> *Tail;
		int iSize;
	
	public:
		SinglyCLL();		// Constructor
		~SinglyCLL();		// Destructor
		void Display();
		int  Count();
		void InsertFirst(T*);
		void InsertLast(T*);
		void InsertAt(T*, int);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAt(int);
		T& operator [](int);
};


//=======================================Singly Circular Linked List Declaration==========================================================//



//============================================Doubly Linked List Declaration End==========================================================//

template <class T>
struct GENNODE_DLL
{
	struct GENNODE_DLL<T> *prev;
	//T* pData;		// Pointer to user defined datatypes 
	T data;			// To store primitive datatypes
	struct GENNODE_DLL<T> *next;	
};

template <class T>
class DoublyLL
{
	private:
		struct GENNODE_DLL<T> *Head;
		int iSize;
		
	public:
		DoublyLL();		// Constructor
		~DoublyLL();	// Destructor
		void Display();
		int  Count();
		void InsertFirst(T*);
		void InsertLast(T*);
		void InsertAt(T*, int);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAt(int);
		T& operator [](int);
};

//======================================Doubly Circular Linked List Declaration==========================================================//

template <class T>
struct GENNODE_DCLL
{
	struct GENNODE_DCLL<T> *prev;
	//T* pData;
	T data;
	struct GENNODE_DCLL<T> *next;
};

template <class T>
class DoublyCLL
{
	private:
		struct GENNODE_DCLL<T> *Head;
		struct GENNODE_DCLL<T> *Tail;
		int iSize;
		
	public:
		DoublyCLL();		// Constructor
		~DoublyCLL();		// Destructor
		void Display();
		int  Count();
		void InsertFirst(T*);
		void InsertLast(T*);
		void InsertAt(T*, int);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAt(int);
		T& operator [](int);
};


//======================================Doubly Circular Linked List Declaration End======================================================//

//=====================================================Stack Declaration=================================================================//

template <class T>
struct GENNODE_STACK
{
	//T* pData;
	T data;
	struct GENNODE_STACK<T> *next;
};

template <class T>
class Stack
{
	private:
		struct GENNODE_STACK<T> *Head;
		int iSize;
	
	public:
		Stack();		// Constructor
		~Stack();		// Destructor
		void Push(T*);
		void Display();
		int  Count();
		T    Pop();
		T    Peek();
};
//=====================================================Stack Declaration End================================================================//

//=====================================================Queue Declaration====================================================================//

template <class T>
struct GENNODE_QUEUE
{
	//T* pData;
	T data;
	struct GENNODE_QUEUE *next;
};

template <class T>
class Queue
{
	private:
		struct GENNODE_QUEUE<T> *Head;
		struct GENNODE_QUEUE<T> *Tail;
		int iSize;
	
	public:
		Queue();		// Constructor
		~Queue();		// Destructor
		void Enqueue(T*);
		T Dequeue();
		void Display();
		int Count();
		T Front();
};

//=====================================================Queue Declaration End================================================================//
