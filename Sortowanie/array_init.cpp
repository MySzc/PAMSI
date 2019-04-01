//
// Created by msz on 3/31/19.
//

#include "array_init.h"

#include<iostream>
#include <cstdlib>
#include <ctime>


void initialize_array_w_random_numbers(int array[], unsigned int size, int upper_boundary) {



    std::cout << "Initialization begins.";

    for(int i = 0; i < size; i++){

        array[i] = rand() % upper_boundary+1;

    };

    std::cout << std::endl << "Initialization complete.";
}
