#include <iostream>
#include <chrono>
#include "array_init.h"
#include "merge_sort.h"
#include "heap_sort.h"
#include "insert_sort.h"


#define SIZE 1000000
#define UPPER_BOUNDARY_OF_RANDOMIZED_NUMBERS 10000000
#define NUMBER_OF_TESTS 10


int main() {

    srand( time( NULL ) );


    int Working_Array[SIZE];

    // MERGE SORT

    std::cout << std::endl << "###############################" << std::endl << "Conducting tests on: MERGE SORT" << std::endl << "##############################" << std::endl << std::endl << std::endl;

    for(int i = 0; i < NUMBER_OF_TESTS; i++){

        std::cout << "TEST " << i+1 << std::endl;

        initialize_array_w_random_numbers(Working_Array, SIZE, UPPER_BOUNDARY_OF_RANDOMIZED_NUMBERS);

        // UNCOMMENT TO SEE THE UNSORTED ARRAY
        /*
        std::cout << "UNSORTED ARRAY:" << std::endl;

        for (int j = 0; j < SIZE; ++j) {
            std::cout << Working_Array[j] << std::endl;
        }
        */

        //TIMING STARTS
        auto start = std::chrono::steady_clock::now();

        mergesort_sort(Working_Array, 0, SIZE-1);

        auto end = std::chrono::steady_clock::now();
        //TIMING ENDS

        std::cout << std::endl;

        // UNCOMMENT TO SEE THE SORTED ARRAY
        /*
        std::cout << "SORTED ARRAY:" << std::endl;

        for (int j = 0; j < SIZE; ++j) {
            std::cout <<  Working_Array[j] << std::endl;
        }
        */

        auto diff = end - start;


        std::cout << "Sorting the table with the size of: " << SIZE << "; completed in " << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl << std::endl << std::endl;
    }

    std::cout << "##############################" << std::endl << "Finished tests on: MERGE SORT" << std::endl << "##############################" << std::endl ;








    // HEAP SORT

    std::cout << std::endl << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl << "Conducting tests on: HEAP SORT" << std::endl << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl << std::endl << std::endl;;

    for(int i = 0; i < NUMBER_OF_TESTS; i++){

        std::cout << "TEST " << i+1 << std::endl;

        initialize_array_w_random_numbers(Working_Array, SIZE, UPPER_BOUNDARY_OF_RANDOMIZED_NUMBERS);

        // UNCOMMENT TO SEE THE UNSORTED ARRAY
        /*
        std::cout << "UNSORTED ARRAY:" << std::endl;

        for (int j = 0; j < SIZE; ++j) {
            std::cout << Working_Array[j] << std::endl;
        }
        */

        //TIMING STARTS
        auto start = std::chrono::steady_clock::now();

        heapsort_sort(Working_Array, SIZE);

        auto end = std::chrono::steady_clock::now();
        //TIMING ENDS

        std::cout << std::endl;

        // UNCOMMENT TO SEE THE SORTED ARRAY
        /*
        std::cout << "SORTED ARRAY:" << std::endl;

        for (int j = 0; j < SIZE; ++j) {
            std::cout <<  Working_Array[j] << std::endl;
        }
        */

        auto diff = end - start;


        std::cout << "Sorting the table with the size of: " << SIZE << "; completed in " << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl << std::endl << std::endl;
    }

    std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl << "Finished tests on: HEAP SORT" << std::endl << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl;






    // INSERTION SORT

    std::cout << std::endl << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl << "Conducting tests on: INSERTION SORT" << std::endl << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl << std::endl << std::endl;;

    for(int i = 0; i < NUMBER_OF_TESTS; i++){

        std::cout << "TEST " << i+1 << std::endl;

        initialize_array_w_random_numbers(Working_Array, SIZE, UPPER_BOUNDARY_OF_RANDOMIZED_NUMBERS);

        // UNCOMMENT TO SEE THE UNSORTED ARRAY
        /*
        std::cout << "UNSORTED ARRAY:" << std::endl;

        for (int j = 0; j < SIZE; ++j) {
            std::cout << Working_Array[j] << std::endl;
        }
        */

        //TIMING STARTS
        auto start = std::chrono::steady_clock::now();

        insertionsort_sort(Working_Array, SIZE);

        auto end = std::chrono::steady_clock::now();
        //TIMING ENDS

        std::cout << std::endl;

        // UNCOMMENT TO SEE THE SORTED ARRAY
        /*
        std::cout << "SORTED ARRAY:" << std::endl;

        for (int j = 0; j < SIZE; ++j) {
            std::cout <<  Working_Array[j] << std::endl;
        }
        */


        auto diff = end - start;


        std::cout << "Sorting the table with the size of: " << SIZE << "; completed in " << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl << std::endl << std::endl;
    }

    std::cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl << "Finished tests on: INSERTION SORT" << std::endl << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl;


    return 0;
}