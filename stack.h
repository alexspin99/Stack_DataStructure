//
// stack.h   
//
// Specification file for Stack class, a stack of integers implemented
// using doubly-linked nodes.
//
// ***** DO NOT MODIFY OR SUBMIT THIS FILE *****
//
#include <iostream>
using namespace std;


#ifndef STACK_H
#define STACK_H

class StackEmpty        {  /* No Code */  };
// StackEmpty exception class - throw an object of this type when stack is empty
// Hint: there is no code for exception classes

class StackFull         {  /* No Code */  };
// StackFull exception class - throw an object of this type when stack is full

class StackInvalidPeek  {  /* No Code */  };
// StackInvalidPeek exception class - throw an object of this type when invalid peek position is used


struct Node                // Node data type for storing a single stack entry along with pointers to
{                          // neighboring entries (previous and next) in the stack
  Node* previous;          // Member variable that holds the address of the predessor node in the stack sequence
  Node* next;              // Member variable that holds the address of the successor node in the stack sequence
  int   data;              // Member variable that holds the data value
};


class Stack                // Implements stack of integers ADT using doubly-linked sequence of nodes
{
  private:
    Node* topPtr;          // Points to the top node on the stack array
	
  public:
    Stack();               // Default constructor initializes empty stack
                           

    ~Stack();              // Destructor deallocates all nodes from stack 
                           // Must not create a memory leak

    void Push(int n);      // Pushes integer n onto top of stack.  
                           // If unable to push, throws StackFull exception.

    void Pop();            // Removes top integer from stack
                           // If stack is already empty, throws StackEmpty exception

    bool IsEmpty() const;  // Returns true if stack is empty; false otherwise
	

    bool IsFull() const;   // Returns true if stack is full; false otherwise
	

    void MakeEmpty();      // Removes all nodes from stack leaving an empty, but usable stack
                           // Must not create a memory leak
	
    int Top() const;       // Returns value of top integer on stack WITHOUT modifying the stack
                           // If stack is empty, throws StackEmpty exception

    int Size() const;      // Returns number of items on stack WITHOUT modifying the stack


    int Max() const;       // Returns value of largest integer within stack WITHOUT modifying the stack
                           // If stack is empty, throws StackEmpty

    int Min() const;       // Returns value of smallest integer within stack WITHOUT modifying the stack
                           // If stack is empty, throws StackEmpty

    int Peek( int n) const; // Returns stack value n levels down from top of stack. Peek(0) = Top()
	                         // If position n does not exist, throws StackInvalidPeek
	
	
    /*******  DO NOT MODIFY ANY OF THE CODE FOR PRINT()             *******/
    /******   DO NOT PLACE A COPY OF PRINT() CODE IN STACK.CPP!!!   *******/
		
    void Print() const     
    // Prints stack contents to stdout in both top-to-bottom and bottom-to-top order 
    {                      
      Node* temp = topPtr; 
      cout << "Top { ";
		
      // Forward print
      while (temp != NULL)
      {
        cout << temp->data << " "; 

        if (temp->next == NULL)
          break; 

        temp = temp->next;
      }
      cout << "} Bottom      Bottom { ";

      // Reverse print
      while (temp != NULL)
      {
        cout << temp->data << " ";  
        temp = temp->previous;
      }
      cout << "} Top" << endl;
    } // End Print()
	
};  // End Class Stack

#endif


