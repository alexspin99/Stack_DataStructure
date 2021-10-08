

#include "stack.h"

using namespace std;


Stack::Stack()
{
	//set pointer to null, initialize empty stack
	topPtr = NULL; 
}

Stack::~Stack()
{
	//delete all members of stack
	MakeEmpty();
}

//add node to stack with value n
void Stack::Push(int n)
{
	
	//if stack is full
	if(IsFull())
		throw StackFull();
		
	//if stack is empty
	if (IsEmpty())
	{
		Node* newNode = new Node;
		newNode->previous = NULL;
		newNode->next = NULL;
		newNode->data = n;
		topPtr = newNode;
	}
	//if stack isn't empty and isn't full
	else 
	{
		Node* newNode = new Node;
		newNode->previous = NULL;
		newNode->next = topPtr;
		newNode->data = n;
		topPtr->previous = newNode;
		topPtr = newNode;
	}

		
	
}

void Stack::Pop()
{
	//pop stack item
	Node* deleteNode = topPtr;
	
	// 0 items in stack
	if(IsEmpty())
		throw StackEmpty();
		
	// if there's 1 item in stack
	if(deleteNode->next == NULL)
	{
		topPtr = NULL;
	}
	// >1 item in stack
	else
	{
		Node* nextNode = deleteNode->next;
		nextNode->previous = NULL;
		deleteNode->next = NULL;
		topPtr = nextNode;
	}

	delete deleteNode;
}

bool Stack::IsEmpty() const
{
	if (topPtr == NULL)
		return true;
	return false;
}

bool Stack::IsFull() const
{
	//tries to allocate space for an additional node
	try
	{
		Node* temp;
		temp = new Node;
		delete temp;
		return false;
	}
	//catches if it runs out of space
	catch (bad_alloc exception)
	{
		return true;
	}
	
}

void Stack::MakeEmpty()
{
	//empties all items in stack
	while (!IsEmpty())
		Pop();
}

int Stack::Top() const
{
	//returns value in top node
	if (IsEmpty())
	{
		throw StackEmpty();
	}
	return topPtr->data;
}

int Stack::Size() const 
{
	int size = 0;
	
	if(IsEmpty())
		return size;
	
	//returns size of non-empty stack
	for (Node* tempPtr = topPtr; tempPtr != NULL; tempPtr = tempPtr->next)
	{
		size++;
	}
	return size;

}

int Stack::Max() const
{
	if (IsEmpty())
	{
		throw StackEmpty();
	}
	
	int max = topPtr->data;
	
	//find largest int in stack
	for (Node* tempPtr = topPtr->next; tempPtr != NULL; tempPtr = tempPtr->next)
	{
		if (tempPtr->data > max)
			max = tempPtr->data;
	}
	return max;
}

int Stack::Min() const
{
	if (IsEmpty())
	{
		throw StackEmpty();
	}
	
	int min = topPtr->data;
	//find min number in stack
	for (Node* tempPtr = topPtr->next; tempPtr != NULL; tempPtr = tempPtr->next)
	{
		if (tempPtr->data < min)
			min = tempPtr->data;
	}
	return min;
}

int Stack::Peek(int n) const
{


	Node* tempPtr = topPtr;
	int count = 0;
	//returns value of nth item in stack
	for (tempPtr; tempPtr != NULL; tempPtr = tempPtr->next)
	{
		if (count == n)
		{
			break;
		}
		count++;
	}
	if(tempPtr == NULL) 
		throw(StackInvalidPeek());
	return tempPtr->data;
}

