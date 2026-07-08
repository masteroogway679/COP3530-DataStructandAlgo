#ifndef STACKISA_H
#define STACKISA_H

#include "List.h"

namespace fgcu {

template <typename T>
class Stack : public List<T> {
public:
    void push(T value) {
        this->insertAtHead(value);
    }

    T pop() {
        T value = this->getValueAtPos(0);
        this->deleteAtPos(0);
        return value;
    }

    T top() {
        return this->getValueAtPos(0);
    }
};

}

#endif