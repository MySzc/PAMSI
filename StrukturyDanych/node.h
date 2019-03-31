//
// Created by msz on 3/15/19.
//

#ifndef STRUKTURYDANYCH_NODE_H
#define STRUKTURYDANYCH_NODE_H

//Node struct to hold the data in
template <typename T>
struct Node{
public:
    T data;
    Node *next;

    unsigned int importance; // For the priority queue - the lower the importance the more it's prioritised
    Node *previous; //For the linked list

    Node();
};

template<typename T>
Node<T>::Node() {
    data = 0;
    next = nullptr;
    importance = 0;
    previous = nullptr;
}



#endif //STRUKTURYDANYCH_NODE_H
