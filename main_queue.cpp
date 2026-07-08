/******************************************************************************

Test harness for Queue ADT implementation (enqueue / dequeue / front)

*******************************************************************************/
#include <iostream>

#include "QueueHasA.h"

int main()
{
    fgcu::Queue<int> theQueue;

    std::cout << "enqueue 10" << std::endl;
    theQueue.enqueue(10);
    std::cout << "front is " << theQueue.front() << std::endl;

    std::cout << "enqueue 20" << std::endl;
    theQueue.enqueue(20);
    std::cout << "front is " << theQueue.front() << std::endl;

    std::cout << "enqueue 30" << std::endl;
    theQueue.enqueue(30);
    std::cout << "front is " << theQueue.front() << std::endl;

    std::cout << "dequeue -> " << theQueue.dequeue() << std::endl;
    std::cout << "front is now " << theQueue.front() << std::endl;

    std::cout << "dequeue -> " << theQueue.dequeue() << std::endl;
    std::cout << "front is now " << theQueue.front() << std::endl;

    std::cout << "dequeue -> " << theQueue.dequeue() << std::endl;

    std::cout << "queue should be empty now" << std::endl;

    return 0;
}