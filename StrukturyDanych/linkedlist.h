//
// Created by msz on 3/17/19.
//

#ifndef STRUKTURYDANYCH_LINKEDLIST_H
#define STRUKTURYDANYCH_LINKEDLIST_H

#include "node.h"

template<typename T>
class List{
public:
    Node<T> *head;

    List();
    void pushBack(const T& newElement);
    void pushFront(const T& newElement);
    void insert(const T& newElement ,int index);
    void remove(const T& element);
    T&operator[](int index);

};

template<typename T>
List<T>::List() {
    head = nullptr;
}

template<typename T>
void List<T>::pushBack(const T &newElement) {

    std::cout << "Pushing the value: '" << newElement << "' to the back of the queue!" << std::endl;

    Node<T> *tmp = new Node<T>;
    Node<T> *tmpIterator = new Node<T>;
    tmpIterator = head;
    tmp->data = newElement;

    // Gdy lista jest pusta
    if(tmpIterator == nullptr){
        head = tmp;
    }else{


    while(tmpIterator->next != nullptr){

      tmpIterator = tmpIterator->next;

    };

    tmpIterator->next = tmp;
    tmp->previous = tmpIterator;
    };

}

template<typename T>
void List<T>::pushFront(const T &newElement) {

    std::cout << "Pushing the value: '" << newElement << "' to the front of the queue!" << std::endl;

    Node<T> *tmp = new Node<T>;
    tmp->data = newElement;

    tmp->next = head;
    tmp->previous = nullptr;

    if(head != nullptr)
        head->previous = tmp;

    head = tmp;

}

template<typename T>
void List<T>::insert(const T &newElement, int index) {

    Node<T> *tmpIterator = new Node<T>;
    Node<T> *tmp = new Node<T>;
    tmpIterator = head;
    tmp->data = newElement;


    if(head == nullptr){ // lista jest pusta

        std::cout << "Inserting the value " << newElement << " at the index " << index << "!" << std::endl;

        pushFront(newElement);

    }else {

        std::cout << "Inserting the value " << newElement << " at the index " << index << "!" << std::endl;

        for (int i = 0; i < index; i++) {
            tmpIterator = tmpIterator->next;
        };

        tmp->next = tmpIterator;
        tmp->previous = tmpIterator->previous;
        tmpIterator->previous->next = tmp;
        tmpIterator->previous = tmp;


    };

}

template<typename T>
void List<T>::remove(const T &element) {

    Node<T> *tmpIterator = new Node<T>;
    tmpIterator = head;

    if(head == nullptr){ // lista jest pusta

        std::cout << "The list is empty!" << std::endl;

    }else if(head->data == element || head->next == nullptr){ // lista ma jeden element i jest on elementem ktory chcemy usunac

        std::cout << "Deleting the value: " << element << " from the list!" << std::endl;

        head = nullptr;

    }else {

        std::cout << "Deleting the value: " << element << " from the list!" << std::endl;

        while (tmpIterator->next != nullptr){


            if(tmpIterator->data == element){

                tmpIterator->previous->next = tmpIterator->next;
                tmpIterator->next->previous = tmpIterator->previous;

                delete tmpIterator;

                return;

            };

            tmpIterator = tmpIterator->next;
        };



    };
}

template<typename T>
T &List<T>::operator[](int index) {

    Node<T> *tmp = new Node<T>;
    tmp = head;

    for(int i = 0; i < index; i++){
        tmp = tmp->next;
    };

    return tmp->data;
}


#endif //STRUKTURYDANYCH_LINKEDLIST_H
