/******************************************************************************

Test harness for Stack ADT implementations (push / pop / top)

Swap the #include below to test either version you build --- the public
interface is identical, so nothing else in this file needs to change.

*******************************************************************************/
#include <iostream>

#include "StackIsA.h"
//#include "StackHasA.h"

int main()
{
    fgcu::Stack<int> theStack;

    std::cout << "push 10" << std::endl;
    theStack.push(10);
    std::cout << "top is " << theStack.top() << std::endl;

    std::cout << "push 20" << std::endl;
    theStack.push(20);
    std::cout << "top is " << theStack.top() << std::endl;

    std::cout << "push 30" << std::endl;
    theStack.push(30);
    std::cout << "top is " << theStack.top() << std::endl;

    std::cout << "pop -> " << theStack.pop() << std::endl;
    std::cout << "top is now " << theStack.top() << std::endl;

    std::cout << "pop -> " << theStack.pop() << std::endl;
    std::cout << "top is now " << theStack.top() << std::endl;

    std::cout << "pop -> " << theStack.pop() << std::endl;

    std::cout << "stack should be empty now" << std::endl;

    return 0;
}