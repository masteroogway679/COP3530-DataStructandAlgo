// ---------------------------------------------------------
// Implementation of a double-linked list for type T values
// ---------------------------------------------------------

// header guard
#ifndef FGCU_LIST_H
#define FGCU_LIST_H

#include <iostream>

namespace fgcu {
    
template <typename T>
class List {
    
// private properties and methods
private:
    
    // data packet stored at each element of the list
    struct Node {
        T data;
        Node * next;
        Node * prev;
    }; // Node
    
    Node * head;    // pointer to head of the list
    Node * tail;    // pointer to tail of the list
    
    int size;       // number of nodes in the list
    
    /**
     * helper method to move a pointer to a specified
     * position in the list (assume list is not empty)
     * @param pos - position to move to
     * @return pointer to the node at given position
     */
     Node* moveToPos(int pos) {
         Node* ptr = head;
         
         // loop moving pointer to the positiont
         for ( ; pos > 0; --pos)
            ptr = ptr->next;
         
         return ptr;
     } // moveToPos
     
    
    /**
     * helper method to print a single value to the console
     * @param value - value to print
     */
    void printValue(const T& value) {
        std::cout << value;
    }


// public interface methods
public:    

    /**
     * Defuault constructor sets up an empty list
     * set head and tail null and size to 0
     */
    List() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    
    /**
     * Get the current size of the list
     */
    int getSize() const { return size; }
    
    
    /**
     * Insert a new value at the head of the list
     * @param value - value to hold in a new node 
     *                at the head position
     */
    void insertAtHead(T value){
        // create new node as temp
        Node * temp = new Node{value, nullptr, nullptr};
        
        // point temp to head
        temp->next = head;
        
        // point current head back to temp 
        if (head != nullptr)
            head->prev = temp;

        // move head to temp
        head = temp;

        // if empty set intial tail
        if (tail == nullptr)
            tail = head;
     
        // increment size
        size++;   

    } // insertAtHead
    
    
    /**
     * Insert a new value at the tail of the list
     * @param value - value to hold in a new node
     *                at the tail position
     */
    void insertAtTail(T value){
        // if empty then insert new head
        if (head == nullptr)
            insertAtHead(value);
        
        else {

            // create new node as temp
            Node * temp = new Node{value, nullptr, nullptr};
            
            // point temp to tail
            temp->prev = tail;
            
            // point tail to temp
            tail->next = temp;
            
            // move tail to temp
            tail = temp;
         
            // increment size
            size++;   
        }
        
    } // insertAtTail


    /**
     * Insert a new value at the head of the list
     * @param value - value to hold in a new node
     *                at the position given by the caller
     * @param pos - insert new node in-between current
     *              nodes at position prior and position given
     */
    void insertAtPos(T value, int pos){
        // insert at head if empty or first position
        if (pos == 0 || head == nullptr)
            insertAtHead(value);

        // insert at tail if last position 
        else if (pos == size - 1)
            insertAtTail(value);
            
        // insert at position given
        else {
            // create new node as temp
            Node * temp = new Node{value, nullptr, nullptr};
            
            // move to position prior to given
            Node * ptr = moveToPos(pos - 1);
            
            // point temp to prior
            temp->prev = ptr;
            
            // point temp to next
            temp->next = ptr->next;
            
            // point prior to temp
            ptr->next = temp;
            
            // if next then point next back to prior
            if (ptr->next != nullptr)
                ptr->next->prev = temp;
         
            // increment size
            size++;   
        }
        
    } // insertAtTail


    /**
     * Update the value of the node at given position
     * @param value - value to overwrite the node
     *                at the position given by the caller
     * @param pos - insert new node in-between current
     *              nodes at position prior and position given
     */
    void updateValueAtPos(T value, int pos) {

        // if not an empty list
        if (size > 0) {
         
            // move to position
            Node* ptr = moveToPos(pos);
            
            // set node value
            ptr->data = value;
        }
         
    } // updateValueAtPos
    
    
    /**
     * Get the value of the node at given position
     * @param pos - position of value in the list
     * @return - value or empty if list is empty
     */
    T getValueAtPos(int pos) {
        // start return value off as empty {}
        T retVal = T{};
         
        // if not an empty list and position in the list
        if (size > 0 && pos < size) {
         
            // move a pointer to position
            Node* ptr = moveToPos(pos);
            
            // get node value of pointer
            retVal = ptr->data;
        }
         
         // return empty or updated return value
         return retVal;
    } // getValueAtPos
    
    /**
     * remove the node at the position given
     * @param pos - position of node to remove
     */
    void deleteAtPos(int pos) {
        
        // if not an empty list and position in the list
        if (size > 0 && pos < size) {
        
            // get pointer to node to delete:
            
            // delcare temp pointer as null
            Node * temp = nullptr;
            
            // if first position
            if (pos == 0) {
                // assign head to temp
                temp = head;
            
                // go ahead an move temp forward one 
                // (may be null if last node)
                head = temp->next;
            }
            // else if last position
            else if (pos == size - 1) {
                // assign tail to temp
                temp = tail;
            
                // go ahead an move tail back one
                // (may be null if last node)
                tail = temp->prev;
            }
                
            // otherwise
            else {
                // move temp to position
                temp = moveToPos(pos);
            }
            
            // if prior node then point it to next node
            if (temp->prev)
                temp->prev->next = temp->next;
        
            // if next node then point it back to prior node
            if (temp->next)
                temp->next->prev = temp->prev;
        
            // free temp node
            delete temp;
                
            // decrement size
            size--;
            
            // last check to set head and tail to null if list is empty
            if (size == 0) {
                head = nullptr;
                tail = nullptr;
            }            
        }
        
    } // deleteAtPos
    
    
    /**
     * Get the position of a value in the list
     * @param - value to search for
     * @return - zero-indexed position or -1 if not found
     */
    int findValue(T value) {
        // start position off at -1
        int pos = -1;
        
        // if not an empty list
        if (size > 0) {
            
            // get a pointer to first node
            Node * ptr = head;
            
            // move pointer while searching for value
            for (int i=0; i < size; ++i) {
                
                // if current node has the value
                if (ptr->data == value) {
                    // update return position
                    pos = i;
                    
                    // break out of loop
                    break;
                }
                
                // move ptr to next position
                ptr = ptr->next;
            }

        }
        
        // return defaulted or updated position 
        return pos;
    } // findValue
    
     /**
      * helper to print the current list to the conosle
      */
    void print() {
        // check that list is not empty
        if (size == 0) 
            std::cout << "List is empty!" << std::endl;
            
        else {
            std::cout << '{';
            
            // get a pointer to first node
            Node * ptr = head;
            
            // loop through all nodes printing their values
            for (int i=0; i < size; ++i) {
                // print current node's value
                printValue(ptr->data);
            
                if (ptr->next)
                    std::cout << ',';
                
                // move to next node
                ptr = ptr->next;
            }
            
            std::cout << '}' << std::endl;
        }
         
    }
    

}; // List

    
} // fgcu

#endif // FGCU_LIST_H