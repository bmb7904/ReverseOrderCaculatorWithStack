// This class will act as a calculator
// Programmer: Brett Bernardi

#include <iostream>
#include <string.h>
#include <stdexcept>

using namespace std;

#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator
{
    
public:
    Calculator();
    ~Calculator();
    int add(int x, int y);
    int subtract(int x, int y);
    int multiply (int x, int y);
    double divide (int x, int y);
    
    
    
};

// constructor
Calculator:: Calculator()
{
    
}

// destructor
Calculator:: ~Calculator()
{
    
}

// every other function is self-explanatory


int Calculator::add(int x, int y)
{
    return x + y;
}
int Calculator::subtract(int x, int y)
{
    return x - y;
}
int Calculator::multiply(int x, int y)
{
    return x * y;
}
double Calculator::divide(int x, int y)
{

    if(y==0)
    {
        throw runtime_error("You cannot divide by zero!\n");
    }
    
    else
    {
        // if it gets to this point, then y is not 0
        //casts x as double first
        return (((double)x)/y);
    }
    
}


#endif /* CALCULATOR_H */

