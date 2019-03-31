//
// Created by msz on 3/19/19.
//

#ifndef STRUKTURYDANYCH_HASHMAP_H
#define STRUKTURYDANYCH_HASHMAP_H

#include <string>

#define MAX_SIZE 1000
#define SEED 179

template<typename KeyType ,typename ValueType >
class Map{
public:
    ValueType array[MAX_SIZE];


    int hashing(int key);
    int hashing(std::string key);
    void insert(const KeyType& key ,const ValueType& value);
    ValueType &operator[](const KeyType& key);
    void remove(const KeyType& key);
};

template<typename KeyType, typename ValueType>
int Map<KeyType, ValueType>::hashing(int key) {

    return key*SEED % MAX_SIZE;
}

template<typename KeyType, typename ValueType>
int Map<KeyType, ValueType>::hashing(std::string key) {

    int tmp = 0;

    for(int i = 0; i < key.size(); i++){

        tmp = tmp + key[i]*SEED;
    }

    return tmp % MAX_SIZE ;
}


template<typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::insert(const KeyType &key, const ValueType &value) {

    std::cout << "Inserting the value " << value << " at the index " << hashing(key) << "!" << std::endl;

    array[hashing(key)] = value;
}

template<typename KeyType, typename ValueType>
ValueType &Map<KeyType, ValueType>::operator[](const KeyType &key) {
    return array[hashing(key)];
}


template<typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::remove(const KeyType &key) {

    std::cout << "Removing the value with the index: " << hashing(key) << " from the map!" << std::endl;

    array[hashing(key)] = NULL; //TODO Problem z usuwaniem problemu
}




#endif //STRUKTURYDANYCH_HASHMAP_H
