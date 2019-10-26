// This class will generate nodes to add to the stack
// Programmer: Brett Bernardi

#include <iostream>
#include <string.h>

using namespace std;


#ifndef STACKNODE_H
#define STACKNODE_H

class stackNode
{
public:
    
    stackNode *nextPointer;
    int num;
    stackNode(int n);
    stackNode();
    ~stackNode();
    
    
private:
};

// constructor for each node created. Sets the nextPointer = NULL initially.
// also sets the parameter n = to the integer that the node contains
stackNode::stackNode(int n)
{
    num = n;
    nextPointer = NULL;
}

// destructor
stackNode::~stackNode()
{
    
}

#endif /* STACKNODE_H */



