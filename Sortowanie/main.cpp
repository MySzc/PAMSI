#include <iostream>
#include <chrono>
#include "array_init.h"
#include "merge_sort.h"


#define SIZE 10
#define UPPER_BOUNDARY_OF_RANDOMIZED_NUMBERS 10000000
#define NUMBER_OF_TESTS 10


int main() {

    srand( time( NULL ) );

    int Working_Array_Merge[SIZE];

    // MERGE SORT

    std::cout << std::endl << "##############################" << std::endl << "Conducting tests on: MERGE SORT" << std::endl << "##############################" << std::endl;

    for(int i = 0; i < NUMBER_OF_TESTS; i++){

        initialize_array_w_random_numbers(Working_Array_Merge, SIZE, UPPER_BOUNDARY_OF_RANDOMIZED_NUMBERS);

        for (int j = 0; j < SIZE; ++j) {
            std::cout << Working_Array_Merge[j] << std::endl;
        }

        //TIMING STARTS
        auto start = std::chrono::steady_clock::now();

        mergesort_sort(Working_Array_Merge, 0, SIZE-1);

        auto end = std::chrono::steady_clock::now();
        //TIMING ENDS

        std::cout << std::endl;

        for (int j = 0; j < SIZE; ++j) {
            std::cout <<  Working_Array_Merge[j] << std::endl;
        }

        auto diff = end - start;


        std::cout << "Sorting the table with the size of: " << SIZE << ", completed within " << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;
    }

    std::cout << std::endl << "##############################" << std::endl << "Finished tests on: MERGE SORT" << std::endl << "##############################" << std::endl;


    return 0;
}