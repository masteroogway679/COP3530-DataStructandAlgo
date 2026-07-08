#ifndef STACKHASA_H
#define STACKHASA_H

#include "List.h"

namespace fgcu {

template <typename T>
class Stack {
private:
    List<T> list;

public:
    void push(T value) {
        list.insertAtHead(value);
    }

    T pop() {
        T value = list.getValueAtPos(0);
        list.deleteAtPos(0);
        return value;
    }

    T top() {
        return list.getValueAtPos(0);
    }
};

}

#endif