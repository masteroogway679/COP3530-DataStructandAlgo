/******************************************************************************

Test harness for a double-linked list ADT implementation

*******************************************************************************/
#include <iostream>
#include <iomanip>

#include "List.h"

int main()
{

    // uncomment to test an integer linked list
    fgcu::List<int> theList;
    
    // uncomment to test a double linked list
    //fgcu::List<double> theList;
    //std::cout << std::fixed << std::setprecision(2);

    theList.print();
    
    std::cout <<  "insert a new value at the head of the list" << std::endl;
    theList.insertAtHead(1);
    theList.print();

    std::cout <<  "insert a new value at the head of the list" << std::endl;
    theList.insertAtHead(0);
    theList.print();

    std::cout <<  "insert a new value at the tail of the list" << std::endl;
    theList.insertAtTail(2);
    theList.print();
    
    std::cout <<  "insert a new value at the tail of the list" << std::endl;
    theList.insertAtTail(3);
    theList.print();
    
    std::cout <<  "delete 2" << std::endl;
    theList.deleteAtPos(2);
    theList.print();
    
    std::cout <<  "delete the head with value 0" << std::endl;
    theList.deleteAtPos(0);
    theList.print();
    
    std::cout <<  "delete the tail value 3 which should now be at pos 1" << std::endl;
    theList.deleteAtPos(1);
    theList.print();
    
    std::cout <<  "delete the last node value 1 which should be at the head and tail" << std::endl;
    theList.deleteAtPos(0);
    theList.print();
    
    std::cout <<  "now add values back into the list by position" << std::endl;
    for (int i = 0; i < 5; ++i) {
        theList.insertAtPos(i, i);
        theList.print();
    }
    
    std::cout << "The list has " << theList.getSize() << " nodes." << std::endl;
    
    std::cout <<  "read the value at position 3" << std::endl;
    std::cout << "Value at 3 is " << theList.getValueAtPos(3) << std::endl;
    
    std::cout <<  "change the value at position 3 to to 5" << std::endl;
    theList.updateValueAtPos(5, 3);
    theList.print();
    
    std::cout <<  "find the position of 5 in the list" << std::endl;
    std::cout << "The position of value 5 is " << theList.findValue(5) << std::endl;
    
    std::cout <<  "now empty the list from the head" << std::endl;
    for (int i = 0; i < 5; ++i) {
        theList.deleteAtPos(0);
        theList.print();
    }

    std::cout << "The list has " << theList.getSize() << " nodes." << std::endl;    

    return 0;
}