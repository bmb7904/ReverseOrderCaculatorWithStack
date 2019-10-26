/*
 * Project: Reverse Order Calculator using Stacks
 * Due Date: 10/23/2019
 * -- This entire program contains 4 files: main.cpp, stackClass.h, stackNode.h, and Calculator.h
 *
 * Programmer and author: Brett Bernardi
 *
 * Do not reproduce this beautiful code without my permission!!!!!
 */


#include <iostream>
#include "string.h"
#include <stdexcept>
#include <cctype>
#include "stackClass.h"
#include "Calculator.h"

using namespace std;


// free function that will pause the program so the user can read the output and press enter to continue
// program works better this way, in my opinion!
void pressEnterToCont()
{
    // clears the buffer to prevent unwanted presses
    cin.ignore();
    cout << "Press enter to continue...";
    cin.get();
}

//free function that will display an error message when stack contains less than two nodes
void errorEmptyStackMessage()
{
    cout << endl;
    cout << "ERROR!" << endl;
    cout << "This stack currently doesn't contain enough numbers to proceed." << endl;
    cout << "Please try again and keep in mind the stack must contain at least two nodes to do any calculations!" << endl << endl;
    pressEnterToCont();
}

//prints menu. lists all of the options available to the user
void printMenu()
{
    cout << endl;
    cout << "*****************************************************" << endl;
    cout << "Here is a list of commands and what they do: " << endl << endl;
    cout << "=  Add a number to the stack" << endl;
    cout << "+  Pops the last two numbers and adds them" << endl;
    cout << "-  Pops the last two numbers and subtracts them" << endl;
    cout << "*  Pops the last two numbers and multiplies them" << endl;
    cout << "/  Pops the last two numbers and divides them" << endl;
    cout << "C  Clears the stack" << endl;
    cout << "S  Sums the entire stack" << endl;
    cout << "N  Gives the number of nodes currently in the stack" << endl;
    cout << "Q  Quit the program" << endl;
    cout << endl << "Please enter a command: ";
}


int main ()
{
    // creates stackClass object
    stackClass myStack;
    
    // creates Calculator object
    Calculator myCalculator;
    
    string userName;
    bool loopValue = true;
    int dumbCounter = 0;
    
    
    cout << "Hello. Please enter your name: ";
    cin  >> userName;
    cout << endl << endl;
    cout << "Hello, " << userName << "." << " We're going to create a stack! " << endl << endl;
    cout << "*******************************************************************" << endl;
    cout << "*************************STACK CREATED*****************************" << endl;
    cout << "*******************************************************************" << endl << endl;
    
    // main loop that will run for as long as user desires.
    while(loopValue)
    {
        char userCommand;
        int userInput1;
        int number1;
        int number2;
        
        printMenu();
        
        // takes user input. 
        // user input is a char
        cin >> userCommand;
        
        // converts user input to uppercase, if needed
        userCommand = toupper(userCommand);
        
        // switch statement which controls the flow of the program based on the user input
        switch(userCommand)
        {
            case '=': cout << endl << "Please enter an integer: ";
                cin >> userInput1;
                myStack.push(userInput1);
                break;
                
            case '+':
                // checks if number of nodes is >=2
                // if not prints error message and breaks
                if(myStack.numOfNodes()<=1)
                {
                    errorEmptyStackMessage();
                    break;
                }
                number1 = myStack.pop();
                number2 = myStack.pop();
                cout << endl << number1 << " " << userCommand << " " << number2 << " = " << myCalculator.add(number1,number2) << endl << endl;
                pressEnterToCont();
                break;
                
            case '-':
                // checks if number of nodes is >=2
                // if not prints error message and breaks
                if(myStack.numOfNodes()<=1)
                {
                    errorEmptyStackMessage();
                    break;
                }
                number1 = myStack.pop();
                number2 = myStack.pop();
                cout << endl << number1 << " " << userCommand << " " << number2 << " = " << myCalculator.subtract(number1,number2) << endl << endl;
                pressEnterToCont();
                break;
                
            case '*':
                // checks if number of nodes is >=2
                // if not prints error message and breaks
                if(myStack.numOfNodes()<=1)
                {
                    errorEmptyStackMessage();
                    break;
                }
                number1 = myStack.pop();
                number2 = myStack.pop();
                cout << endl << number1 << " " << userCommand << " " << number2 << " = " << myCalculator.multiply(number1,number2) << endl << endl;
                pressEnterToCont();
                break;
                
            case '/':
                // checks if number of nodes is >=2
                // if not prints error message and breaks
                if(myStack.numOfNodes()<=1)
                {
                    errorEmptyStackMessage();
                    break;
                }
                
                // this tries to divide the top two numbers in the nodes of the stack
                // will throw an error if division by zero occurs
                
                try
                {
                    number1 = myStack.pop();
                    number2 = myStack.pop();
                    double quotient = myCalculator.divide(number1,number2);
                    cout << endl << number1 << " " << userCommand << " " << number2 << " = " << quotient << endl << endl;
                    pressEnterToCont();
                    
                }
                
                catch(runtime_error& e)
                {
                    //prints the exception if it occurred
                    //checks for division by zero
                    cout << endl <<"ERROR" << endl;
                    cout << e.what() << endl << endl;
                    pressEnterToCont();
                }
                break;
                
            case 'Q': loopValue = false;
                break;
                
            case 'C': myStack.deleteStack();
                cout << endl << "The stack has been deleted!" << endl << endl;
                pressEnterToCont();
                break;
                
            case 'S':
                // checks if number of nodes is >=2
                // if not prints error message and breaks
                if(myStack.numOfNodes()<=1)
                {
                    errorEmptyStackMessage();
                    break;
                }
                cout << endl << "The sum of the entire stack = " << myStack.sumEntireStack() << endl << endl;
                pressEnterToCont();
                break;
                
            case 'N':
                cout << endl <<  "Your stack currently contains " << myStack.numOfNodes() << " node(s)!" << endl << endl;
                pressEnterToCont();
                break;
                
            default:
                if(dumbCounter < 1)
                {
                    cout << endl << "You didn't enter valid input. Try again." << endl << endl;
                    // clears the buffer to prevent unwanted presses
                    pressEnterToCont();
                }
                else
                {
                    cout << endl << "Apparently, you're having some trouble reading. Try again by entering valid input only. Thanks." << endl << endl;
                    // clears the buffer to prevent unwanted presses
                    pressEnterToCont();
                }
                dumbCounter ++;
                break;
                
                
        }
    }
    
    cout << endl << "Thanks for playing!" << endl;
    cout << "Programmer: Brett Bernardi" << endl;
    return 0;
}
