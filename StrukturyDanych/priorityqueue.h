//
// Created by msz on 3/16/19.
//

#ifndef STRUKTURYDANYCH_PRIORITYQUEUE_H
#define STRUKTURYDANYCH_PRIORITYQUEUE_H

#include "node.h"

template<typename T>
class PriorityQueue{
public:

    Node<T> *first;

    PriorityQueue();
    void enqueue(const T& newElement , unsigned int priority);
    T dequeue ();
};

template<typename T>
PriorityQueue<T>::PriorityQueue() {

    first = nullptr;
}

template<typename T>
void PriorityQueue<T>::enqueue(const T &newElement, unsigned int priority) {

    std::cout << "Enqueueing the value: " << newElement << " with the priority of " << priority << "!" << std::endl;

    Node<T> *tmp = new Node<T>;
    Node<T> *tmpIterator = new Node<T>;
    tmp->data = newElement;
    tmp->importance = priority;
    tmpIterator = first;

    // gdy nic nie ma w kolejce
    if(first == nullptr ){
        tmp->next = first;
        first = tmp;
    }
    else{

        if(first->next == nullptr || tmpIterator->importance >= priority){

            tmp->next = first;
            first = tmp;

        }else {

            while (tmpIterator->importance <= priority && tmpIterator->next != nullptr) {

                tmp->next = tmpIterator;
                tmpIterator = tmpIterator->next;
                //tmp->next = tmpIterator;
                //tmpIterator->next = tmp;
            };

            tmpIterator->next = tmp;
            tmp->next = nullptr;
        };
    };

}

template<typename T>
T PriorityQueue<T>::dequeue() {

    if(first == nullptr){
        std::cout << "The queue is empty!" << std::endl;
        return NULL; // TODO Co zwrocic gdy kolejka jest pusta? (NULL = warning)
    }else {
        std::cout << "Dequeueing the value: " << first->data << " with the priority of " << first->importance << "!" << std::endl;

        Node<T> *tmp = first;
        first = tmp->next;

        return tmp->data;
    }
}




#endif //STRUKTURYDANYCH_PRIORITYQUEUE_H
