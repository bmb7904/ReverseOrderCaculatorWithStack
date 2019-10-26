// This class will generate the stack as well as perform different functions like counting the nodes, and summing the entire stack
// Programmer: Brett Bernardi

#include <iostream>
#include <string.h>
#include "stackNode.h"

using namespace std;

#ifndef STACKCLASS_H
#define STACKCLASS_H

class stackClass
{
    
    
public:
    stackClass();
    ~stackClass();
    void push(int n);
    int pop();
    bool isStackEmpty();
    int numOfNodes();
    void deleteStack();
    int sumEntireStack();
    
    
private:
    stackNode *top;
    
    
    
};

// constructor for the stackClass
stackClass::stackClass()
{
    top = NULL;
}

// destructor for the stackClass
stackClass::~stackClass()
{

}

// pushes the stack down by creating a new node and adding to the top
// of the stack.
void stackClass::push(int n)
{
    stackNode *newStackNode = new stackNode(n);
    
    // i.e. the stack is empty
    if(top == NULL)
    {
        top = newStackNode;
        return;
    }
    
    newStackNode ->nextPointer=top;
    top = newStackNode;
    return;
}

// returns a boolean
// true if stack is empty
bool stackClass::isStackEmpty()
{
    if(top == NULL)
    {
        return true;
    }
    
    else
    {
        return false;
    }
    
}

// deletes the top node and returns the value of the integer from it
int stackClass::pop()
{
    if(isStackEmpty() == true)
    {
        cout << "Stack is empty!" << endl;
        return 0;
    }
    stackNode *tempPointer = top;
    int returnInt = top -> num;
    top = top ->nextPointer;
    delete tempPointer;
    
    return returnInt;
    
}

// creates tempPointer and has it pointing at top node in the stack
// sequentially goes through the stack and deletes every single node
void stackClass::deleteStack()
{
    if(isStackEmpty() == true)
    {
        return;
    }
    while (isStackEmpty() != true)
    {
        stackNode *tempPointer = top;
        top = top ->nextPointer;
        delete tempPointer;
    }
}

// counts the number of nodes in the entire stack
// returns an int
// does not alter the stack in any way
int stackClass::numOfNodes()
{
    if(isStackEmpty() == true)
    {
        return 0;
    }
    
    stackNode *counterPointer = top;
    int counter = 0;
    
    // this while loop will stop when the counter pointer is pointing at the
    // second to last node because counterPointer -> next = NULL
    // will give exactly n-1 number of nodes
    while(counterPointer ->nextPointer != NULL)
    {
        counter++;
        counterPointer = (counterPointer -> nextPointer);
    }
    
    // have to add 1 to the counter in order to get the correct total
    return (counter + 1);
    
}

// sums every single integer in every node in the stack
// does not alter the stack in any way.
int stackClass::sumEntireStack()
{
    int sum = 0;
    stackNode *tempPointer = top;
    
    while(tempPointer ->nextPointer != NULL)
    {
        sum +=(tempPointer ->num);
        tempPointer = (tempPointer ->nextPointer);
    }
    
    // at this point, tempPointer is pointing to the very bottom node of the stack
    // this step is needed to add the value of the bottom node of the stack into the sum
    sum += (tempPointer ->num);
    
    return sum;
}



#endif /* STACKCLASS_H */

