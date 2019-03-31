//
// Created by msz on 3/16/19.
//

#ifndef STRUKTURYDANYCH_QUEUE_H
#define STRUKTURYDANYCH_QUEUE_H

#include "node.h"

template<typename T>
class Queue{
public:
    Node<T> *first;
    Node<T> *last;

    Queue();
    void enqueue(const T& newElement);
    T dequeue ();

};

template<typename T>
Queue<T>::Queue() {
    first = nullptr;
    last = nullptr;
}


template<typename T>
void Queue<T>::enqueue(const T &newElement) {

    std::cout << "Enqueueing the value: " << newElement << "!" << std::endl;

    Node<T> *tmp = new Node<T>;
    tmp->data = newElement;


    if(first == nullptr){
        first = tmp;
        last = tmp;
    }
    else{
        last->next = tmp;
        last = tmp;
    };
}

template<typename T>
T Queue<T>::dequeue() {

    if(first == nullptr){
        std::cout << "The queue is empty!" << std::endl;
        return NULL; // TODO Co zwrocic gdy kolejka jest pusta? (NULL = warning)
    }else {
        std::cout << "Dequeueing the value: " << first->data << "!" << std::endl;

        Node<T> *tmp = first;
        first = tmp->next;

        return tmp->data;
    }
}



#endif //STRUKTURYDANYCH_QUEUE_H
