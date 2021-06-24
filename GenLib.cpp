#include "GenLib.h"
#include<iostream>
//============================================Singly Linked List Definitions==========================================================//

//
//	Constructor
//
template <class T>
SinglyLL<T> :: SinglyLL()
{
	Head = NULL;
	iSize = 0; 
}


//
//	Destructor
//
template <class T>
SinglyLL<T> :: ~SinglyLL()
{
	struct GENNODE_SLL<T> *temp = NULL;
	
	while(NULL != Head)
	{
		temp = Head;
		Head = Head->next;
		delete temp;	
	}
}


//
//	Overloaded [] operator for indexing support
//
// Don't use for frequent accesing time complexity is O(n) for EVERY access
// Same as at() or get() 
template <class T>
T& SinglyLL<T> :: operator [](int iIndex)
{
	if(iIndex > (iSize-1))
	{
		std::cout<<"Index out of bounds"<<endl;
		std::exit(1);
	}
	
	struct GENNODE_SLL<T> *temp = Head;
	
	for(int i = 0; i < iSize && temp->next != NULL;++i)
	{
		if(i == iIndex)
		{
			break;
		}
		temp = temp->next;
	}
	 
	return (temp->data);
}

template <class T>
void SinglyLL<T> :: InsertFirst(T* num)
{
	struct GENNODE_SLL<T> *newn = new struct GENNODE_SLL<T>;
	newn->data = *num;
	newn->next = NULL;
	
	newn->next = Head;
	Head = newn;
	iSize++;
}

template <class T>
void SinglyLL<T> :: InsertLast(T* num)
{
	struct GENNODE_SLL<T> *newn = new struct GENNODE_SLL<T>;
	newn->next = NULL;
 	newn->data = *num;
 	
	if(iSize == 0)
	{
		Head = newn;
	}
	else
	{
		struct GENNODE_SLL<T> *temp = Head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
	}
	iSize++;
}

template <class T>
void SinglyLL<T> :: InsertAt(T* Num, int iPos)
{
	if(iPos < 1 || iPos > iSize+1)
	{
		return;
	}
			
	struct GENNODE_SLL<T> *newn = NULL;
			
	newn = new struct GENNODE_SLL<T>;
	newn->next = NULL;
	newn->data = *Num;
 	
	if(iPos == 1)
	{
		InsertFirst(Num);
	}
	else if(iPos == iSize + 1)
	{
		InsertLast(Num);
	}
	else
	{
		struct GENNODE_SLL<T> *Temp = Head;
		for(int i = 1; i < iPos-1; i++)
		{
			Temp = Temp->next;
		}
				
		newn->next = Temp->next;
		Temp->next = newn;
		iSize++;
	}
}

template <class T>
void SinglyLL<T> ::  DeleteFirst()
{
	if(NULL != Head)
	{
		struct GENNODE_SLL<T> *temp = Head;
		Head = Head->next;
		delete temp;
		iSize--;
	}
}

template <class T>
void SinglyLL<T> :: DeleteLast()
{
	if(NULL == Head)				// If linked list is empty
	{
		return;
	}
	else if(NULL == Head->next)		// If linked list has only one GENNODE_SLL
	{
		delete Head;
		Head = NULL;
	}
	else							// If linked list has more than one GENNODE_SLL
	{
		struct GENNODE_SLL<T> *temp = Head;
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}
		delete temp->next;
		temp->next = NULL;
	}
	iSize--;
}


template <class T>
void SinglyLL<T> :: DeleteAt(int iPos)
{
	if(iPos < 1 || iPos > iSize)
	{
		return;
	}
			
	if(iPos == 1)
	{
		DeleteFirst();
	}
	else if(iPos == iSize)
	{
		DeleteLast();
	}
	else
	{
		struct GENNODE_SLL<T> *temp = Head;
		struct GENNODE_SLL<T> * Target = NULL;	
		for(int i = 1; i < iPos-1; i++)
		{
			temp = temp->next;
		}
				
		Target = temp->next;
		temp->next = Target->next;
		delete Target;
		iSize--;
	}
}

template <class T>
int SinglyLL<T> :: Count()
{
	return iSize;
}

//
// Function to display data in the list
// 
// Note: Should not be used for user defined datatypes
template <class T>
void SinglyLL<T> :: Display()
{
	struct GENNODE_SLL<T> *temp = Head;
	while(NULL != temp)
	{
		std::cout<<temp->data<<"=>";
		temp = temp->next;
	}
	std::cout<<"NULL\n";
}

//============================================Singly Linked List Definitions End==========================================================//

//=======================================Singly Circular Linked List Definitions==========================================================//

//
//	Constructor
//
template <class T>
SinglyCLL<T> :: SinglyCLL()
{
	Head = NULL;
	Tail = NULL;
	iSize = 0;
}

//
//	Destructor
//
template <class T>
SinglyCLL<T> :: ~SinglyCLL()
{
	struct GENNODE_SCLL<T> *temp = NULL;
	std::cout<<"Inside destructor\n\n";
	for(int i = 0; i < iSize; ++i)
	{
		temp = Head;
		Head = Head->next;
		delete temp;	
	}
}

//
//	Overloaded [] operator for indexing support
//
// Don't use for frequent accesing time complexity is O(n) for EVERY access
template <class T>
T& SinglyCLL<T> :: operator [](int iIndex)
{
	if(iIndex > (iSize-1))
	{
		std::cout<<"Index out of bounds"<<endl;
		std::exit(1);
	}
	
	struct GENNODE_SCLL<T> *temp = Head;
	
	for(int i = 0; i < iSize && temp->next != NULL;++i)
	{
		if(i == iIndex)
		{
			break;
		}
		temp = temp->next;
	}
	 
	return temp->data;
}

template <class T>		
void SinglyCLL<T> :: InsertFirst(T* Num)
{
	struct GENNODE_SCLL<T> * newn = new struct GENNODE_SCLL<T>;
	newn->next = NULL;
	newn->data = *Num;
			
	if(NULL == Head && NULL == Tail)	// Linked List is empty
	{
		Head = newn;
		Tail = Head;
	}
	else								// Linked List has more than one element
	{
		newn->next = Head;
		Head = newn;
	}
	Tail->next = Head;
	iSize++;
}

template <class T>
void SinglyCLL<T> :: InsertLast(T* Num)
{
	struct GENNODE_SCLL<T> * newn = new struct GENNODE_SCLL<T>;
	newn->next = NULL;
	newn->data = *Num;
			
	if(NULL == Head && NULL == Tail)	// Linked List is empty
	{
		Head = newn;
		Tail = Head;
	}
	else								// Linked List has more than one element
	{
		Tail->next = newn;
		Tail = newn;
	}
	Tail->next = Head;
	iSize++;
}

template <class T>		
void SinglyCLL<T> :: InsertAt(T* Num, int iPos)
{
	if(iPos < 1 || iPos > iSize+1)
	{
		return;
	}
			
	struct GENNODE_SCLL<T> * newn = NULL;
	struct GENNODE_SCLL<T> * Temp = Head;
			
	newn = new struct GENNODE_SCLL<T>;
	newn->data = *Num;
	newn->next = NULL;
			
	if(iPos == 1)
	{
		InsertFirst(Num);
	}
	else if(iPos == iSize)
	{
		InsertLast(Num);
	}
	else
	{
		for(int i = 1; i < iPos-1; i++)
		{
			Temp = Temp->next;
		}
				
		newn->next = Temp->next;
		Temp->next = newn;
		iSize++;
	}
}

template <class T>
void SinglyCLL<T> :: DeleteFirst()
{
	if(iSize == 0)		// Empty LL
	{
		return;
	}
			
	if(iSize == 1)		// Only one GENNODE_SCLL in LL
	{
		delete Head;
		Head = NULL;
		Tail = NULL;
	}
	else				// More than one GENNODE_SCLL in LL
	{
		Head = Head->next;
		delete Tail->next;
		Tail->next = Head;
	}
	iSize--;
}

template <class T>		
void SinglyCLL<T> :: DeleteLast()
{
	if(iSize == 0)		// Empty LL
	{
		return;
	}
			
	if(iSize == 1)		// Only one GENNODE_SCLL in LL
	{
		delete Head;
		Head = NULL;
		Tail = NULL;
	}	
	else				// More than one GENNODE_SCLL in LL
	{
		struct GENNODE_SCLL<T> * Temp = Head;
		while(Temp->next != Tail)
		{
			Temp = Temp->next;
		}
				
		delete Tail;
		Tail = Temp;
		Tail->next = Head;
	}
	iSize--;
}
	
template <class T>	
void SinglyCLL<T> :: DeleteAt(int iPos)
{
	if(iPos < 1 || iPos > iSize)
	{
		return;
	}
			
	if(iPos == 1)
	{
		DeleteFirst();
	}
	else if(iPos == iSize)
	{
		DeleteLast();
	}
	else
	{
		struct GENNODE_SCLL<T> *Temp = Head;
		struct GENNODE_SCLL<T> *Target = NULL;
		for(int i = 1; i < iPos-1; i++)
		{
			Temp = Temp->next;
		}
				
		Target = Temp->next;
		Temp->next = Target->next;
		delete Target;
		iSize--;
	}

}

template <class T>	
int SinglyCLL<T> :: Count()
{
	return iSize;
}

template <class T>
void SinglyCLL<T> :: Display()
{
	int i = 0;
	struct GENNODE_SCLL<T> * Temp = Head;
	for(i = 1; i <= iSize; ++i)
	{
		std::cout<<"| "<<Temp->data<<" |->";
		Temp = Temp->next;
	}
	std::cout<<"HEAD"<<endl;
}

//===================================Singly Circular Linked List Definitions End==========================================================//

//============================================Doubly Linked List Definitions End==========================================================//

//
//	Constructor
//
template <class T>
DoublyLL<T> :: DoublyLL()
{
	Head = NULL;
	iSize = 0;
}

//
//	Destructor
//
template <class T>
DoublyLL<T> :: ~DoublyLL()
{
	struct GENNODE_DLL<T> *temp = NULL;
	
	while(NULL != Head)
	{
		temp = Head;
		Head = Head->next;
		delete temp;	
	} // End of while
}

//
//	Overloaded [] operator for indexing support
//
// Don't use for frequent accesing time complexity is O(n) for EVERY access
template <class T>
T& DoublyLL<T> :: operator [](int iIndex)
{
	if(iIndex > (iSize-1))
	{
		std::cout<<"Index out of bounds"<<endl;
		std::exit(1);
	}
	
	struct GENNODE_DLL<T> *temp = Head;
	
	for(int i = 0; i < iSize && temp->next != NULL;++i)
	{
		if(i == iIndex)
		{
			break;
		}
		temp = temp->next;
	}
	 
	return temp->data;
}

template <class T>
void DoublyLL<T> :: InsertFirst(T* num)
{
	struct GENNODE_DLL<T> *newn = new struct GENNODE_DLL<T>;
	newn->data = *num;
	newn->next = NULL;
	newn->prev = NULL;
	
	if(NULL == Head)
	{
		Head = newn;
	}
	else
	{
		newn->next = Head;
		Head->prev = newn;
		Head = newn;
	}
	iSize++;
}

template <class T>
void DoublyLL<T> :: InsertLast(T* num)
{	
	struct GENNODE_DLL<T> *newn = new struct GENNODE_DLL<T>;
	newn->next = NULL;
	newn->data = *num;
	newn->prev = NULL;
	
	if(NULL == Head)				// Linked List is empty
	{
		Head = newn;
	}
	else							// Linked List has atleast one GENNODE_DLL
	{
		struct GENNODE_DLL<T> *temp = Head;
		
		while(NULL != temp->next)
		{
			temp = temp->next;
		} // End of while
		
		temp->next = newn;
		newn->prev = temp;
	}
	iSize++;
}

template <class T>
void DoublyLL<T> :: InsertAt(T* num, int iPos)
{
	if(iPos < 0 || iPos > (iSize + 1))
	{
		return;
	}
	
	if(iPos == 1)
	{
		InsertFirst(num);	
	}
	else if(iPos == (iSize + 1))
	{
		InsertLast(num);
	}
	else
	{
		struct GENNODE_DLL<T> *newn = new struct GENNODE_DLL<T>;
		newn->next = NULL;
		newn->prev = NULL;
		newn->data = *num;
		
		struct GENNODE_DLL<T> *temp = Head;
		for(int i = 1; i < iPos-1; ++i)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next->prev = newn;
		temp->next = newn;
		newn->prev = temp;
		iSize++;
	}
}

template <class T>
void DoublyLL<T> :: DeleteFirst()
{
	if(NULL != Head)
	{
		Head = Head->next;
		delete Head->prev;
		Head->prev = NULL;
		iSize--;
	}
}

template <class T>
void DoublyLL<T> :: DeleteLast()
{	
	if(NULL == Head)				// Linked List is empty
	{
		return;
	}
	else if(NULL == Head->next)		// Only one GENNODE_DLL is Linked List
	{
		delete Head;
		Head = NULL;
	}
	else							// More than one GENNODE_DLL is Linked List
	{
		struct GENNODE_DLL<T> *temp = Head;
		
		while(NULL != temp->next->next)
		{
			temp = temp->next;
		} // End of while
		
		delete temp->next;
		temp->next = NULL;
	}
	iSize--;
}

template <class T>
void DoublyLL<T> :: DeleteAt(int iPos)
{
	if(iPos < 1 || iPos > iSize)
	{
		return;
	}
			
	if(iPos == 1)
	{
		DeleteFirst();
	}
	else if(iPos == iSize)
	{
		DeleteLast();
	}
	else
	{
		struct GENNODE_DLL<T> *temp = Head;
		for(int i = 1; i < iPos-1; i++)
		{
			temp = temp->next;
		}
			
		temp->next = temp->next->next;
		delete temp->next->prev;
		temp->next->prev = temp;
		iSize--;
	}
}

template <class T>
int DoublyLL<T> :: Count()
{
	return iSize;
}

template <class T>
void DoublyLL<T> :: Display()
{
	struct GENNODE_DLL<T> *temp = Head;
	std::cout<<"NULL<=>";
	while(NULL != temp)
	{
		std::cout<<temp->data<<"<=>";
		temp = temp->next;
	}
	std::cout<<"NULL"<<endl;
}

//============================================Doubly Linked List Definitions End==========================================================//

//======================================Doubly Circular Linked List Definitions==========================================================//
//
//	Constructor
//
template <class T>
DoublyCLL<T> :: DoublyCLL()
{
	Head = NULL;
	Tail = NULL;
	iSize = 0;
}

//
//	Destructor
//
template <class T>
DoublyCLL<T> :: ~DoublyCLL()
{
	struct GENNODE_DCLL<T> *temp = NULL;
	//cout<<"Inside destructor\n\n";
	for(int i = 0; i < iSize; ++i)
	{
		temp = Head;
		Head = Head->next;
		delete temp;	
	}
}

//
//	Overloaded [] operator for indexing support
//
// Don't use for frequent accesing time complexity is O(n) for EVERY access
template <class T>
T& DoublyCLL<T> :: operator [](int iIndex)
{
	if(iIndex > (iSize-1))
	{
		std::cout<<"Index out of bounds"<<endl;
		std::exit(1);
	}
	
	struct GENNODE_DCLL<T> *temp = Head;
	
	for(int i = 0; i < iSize && temp->next != NULL;++i)
	{
		if(i == iIndex)
		{
			break;
		}
		temp = temp->next;
	}
	 
	return temp->data;
}

template <class T>
void DoublyCLL<T> :: InsertFirst(T* num)
{
	struct GENNODE_DCLL<T> *newn = new struct GENNODE_DCLL<T>;
	newn->data = *num;
	newn->next = NULL;
	newn->prev = NULL;
	
	if(Head == NULL && Tail == NULL)
	{
		Head = newn;
		Tail = newn;
	}
	else
	{
		newn->next = Head;
		Head->prev = newn;
		Head = newn;
	}		
	Tail->next = Head;
	Head->prev = Tail;
	iSize++;
}

template <class T>
void DoublyCLL<T> :: InsertLast(T* num)
{	
	struct GENNODE_DCLL<T> *newn = new struct GENNODE_DCLL<T>;
	newn->next = NULL;
	newn->data = *num;
	newn->prev = NULL;
	
	if((Head == NULL) && (Tail == NULL))
	{
		Head = newn;
		Tail = newn;
	}
	else
	{
		Tail->next = newn;
		newn->prev = Tail;
		Tail = newn;
	}	
	Head->prev = Tail;
	Tail->next = Head;
	iSize++;
}

template <class T>
void DoublyCLL<T> :: InsertAt(T* num, int iPos)
{
	if((iPos < 1) || (iPos > iSize + 1))
	{
		return;
	}

	if(iPos == 1)
	{
		InsertFirst(num);
	}
	else if(iPos == iSize + 1)
	{
		InsertLast(num);
	}
	else
	{
		struct GENNODE_DCLL<T> *newn = new struct GENNODE_DCLL<T>;
		newn->data = *num;
		newn->next = NULL;
		newn->prev = NULL;
		
		struct GENNODE_DCLL<T> *temp = Head;
		
		for(int i = 1; i < iPos - 1; i++)
		{
			temp = temp->next;
		}
		
		newn->next = temp->next;
		temp->next->prev = newn;
		temp->next = newn;
		newn->prev = temp;
		iSize++;
	}
}

template <class T>
void DoublyCLL<T> :: DeleteFirst()
{
	if(iSize == 0)
	{
		return;
	}
	else if(iSize == 1)
	{
		delete Head;
		Head = NULL;
		Tail = NULL;	
	}
	else
	{
		Head = Head->next;
		delete Head->prev;
		Head->prev = Tail;
		Tail->next = Head;
	}
	iSize--;
}

template <class T>
void DoublyCLL<T> :: DeleteLast()
{	
	if(iSize == 0)			// If List is empty
	{
		return;
	}
	else if(iSize == 1)		// If list has only one element
	{
		delete Tail;
		Head = NULL;
		Tail = NULL;	
	}
	else					// If list has more than one element
	{
		Tail = Tail->prev;
		delete Tail->next;
		Tail->next = Head;
		Head->prev = Tail;
	}
	iSize--;
}

template <class T>
void DoublyCLL<T> :: DeleteAt(int iPos)
{
	if((iPos < 1) || (iPos > iSize))
	{
		return;
	}

	if(iPos == 1)
	{
		DeleteFirst();
	}
	else if(iPos == iSize)
	{
		DeleteLast();
	}
	else
	{
		struct GENNODE_DCLL<T> *temp = Head;
		
		for(int i = 1; i < iPos - 1; i++)
		{
			temp = temp->next;
		}
		temp->next = temp->next->next;
		delete temp->next->prev;
		temp->next->prev = temp;
		iSize--;
	}
}

template <class T>
int DoublyCLL<T> :: Count()
{
	return iSize;
}

template <class T>
void DoublyCLL<T> :: Display()
{
	struct GENNODE_DCLL<T> *temp = Head;
	int i = 0;
	std::cout<<"TAIL=>";
	for(i = 1; i <= iSize; ++i)
	{
		std::cout<<"| "<<temp->data<<" |=>";
		temp = temp->next;
	}
	std::cout<<"HEAD"<<endl;
}

//======================================Doubly Circular Linked List Definitions End======================================================//

//=====================================================Stack Definitions=================================================================//

//
//	Constructor
//
template <class T>
Stack<T> :: Stack()
{
	this->Head = NULL;
	this->iSize = 0;
}


//
//	Destructor
//
template <class T>
Stack<T> :: ~Stack()
{
	struct GENNODE_STACK<T> *Temp = NULL;
	
	while(Head != NULL)
	{
		Temp = Head;
		Head = Head->next;	
		delete Temp;
	} // End of while
}

template <class T>
void Stack<T> :: Push(T* Num)
{
	struct GENNODE_STACK<T> * newn = new struct GENNODE_STACK<T>;
	newn->next = NULL;
	newn->data = *Num;
	
	newn->next = Head;
	Head = newn;
	iSize++;
}

template <class T>
T Stack<T> :: Pop()
{	
	T Ret;
	if(iSize == 0)		// If Stack is empty
	{
		std::cout<<"Stack is empty"<<endl;
	}
	else				// If stack has atleast one GENNODE_STACK
	{	
		Ret = Head->data;
		struct GENNODE_STACK<T> * Target = Head;
		Head = Head->next;	
		delete Target;
		iSize--;
	}
	return Ret;
}

template <class T>
T Stack<T> :: Peek()
{
	if(iSize == 0)
	{
		std::cout<<"Stack is empty!"<<endl;	
		std::exit(1);
	}
	else
	{
		return Head->data;
	}
}

template <class T>
void Stack<T> :: Display()
{
	struct GENNODE_STACK<T> * Temp = Head;
	while(Temp != NULL)
	{
		std::cout<<"\t\t"<<Temp->data<<endl;
		Temp = Temp->next;
	}
}

template <class T>
int Stack<T> :: Count()
{
	return this->iSize;
}

//=====================================================Stack Definitions End================================================================//

//=====================================================Queue Definitions====================================================================//

//
//	Constructor
//
template <class T>
Queue<T> :: Queue()
{
	this->Head = NULL;
	this->Tail = NULL;
	this->iSize = 0;
}

//
//	Destructor
//
template <class T>
Queue<T> :: ~Queue()	// Destructor
{
	struct GENNODE_QUEUE<T> *Temp = NULL;
	while(Head != NULL)
	{
		Temp = Head;
		Head = Head->next;	
		delete Temp;
	}
}

template <class T>
void Queue<T> :: Enqueue(T* Num)
{
	struct GENNODE_QUEUE<T> * newn = new struct GENNODE_QUEUE<T>;
	newn->next = NULL;
	newn->data = *Num;
	
	if(iSize == 0)
	{
		Head = newn;
		Tail = newn;
	}
	else
	{	
		Tail->next = newn;
		Tail = newn;
	}
	iSize++;
}

template <class T>
T Queue<T> :: Dequeue()
{
	T iRet;
	
	if(iSize == 0)
	{
		std::cout<<"Queue is empty!"<<endl;
		std::exit(1);
	}
	else
	{
		struct GENNODE_QUEUE<T> * Temp = Head;
		iRet = Head->data;
		Head = Head->next;
		delete Temp;
		iSize--;
	}
	return iRet;
}

template <class T>
T Queue<T> :: Front()
{
	if(iSize == 0)
	{
		std::cout<<"Queue is empty"<<endl;
		std::exit(1);
	}
	else
	{
		return this->Head->data;
	}
}

template <class T>
void Queue<T> :: Display()
{
	struct GENNODE_QUEUE<T> *Temp = Head;
	while(Temp != NULL)
	{
		std::cout<<"\t"<<Temp->data;
		Temp = Temp->next;
	}
	std::cout<<endl;
}

template <class T>
int Queue<T> :: Count()
{
	return this->iSize;
}

//=====================================================Queue Definitions End================================================================//
