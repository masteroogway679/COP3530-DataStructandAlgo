#ifndef QUEUEHASA_H
#define QUEUEHASA_H

#include "List.h"

namespace fgcu {

template <typename T>
class Queue {
private:
    List<T> list;

public:
    void enqueue(T value) {
        list.insertAtTail(value);
    }

    T dequeue() {
        T value = list.getValueAtPos(0);
        list.deleteAtPos(0);
        return value;
    }

    T front() {
        return list.getValueAtPos(0);
    }
};

}

#endif