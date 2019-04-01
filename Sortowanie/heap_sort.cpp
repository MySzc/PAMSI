//
// Created by msz on 4/1/19.
//

#include "heap_sort.h"


void heapsort_heap(int array[], int array_size, int root_index) {

    int largest_index = root_index;

    int left_child_index = 2*root_index + 1;
    int right_child_index = 2*root_index + 2;

    if (left_child_index < array_size && array[left_child_index] > array[largest_index] )
        largest_index = left_child_index;

    if (right_child_index < array_size && array[right_child_index] > array[largest_index] )
        largest_index = right_child_index;


    if(largest_index != root_index){

       int tmp = array[root_index];
       array[root_index] = array[largest_index];
       array[largest_index] = tmp;

       heapsort_heap(array, array_size, largest_index);
    };
}

void heapsort_sort(int array[], int array_size) {

    for(int i = (array_size/2 -1); i >= 0; i--)
        heapsort_heap(array, array_size, i);

    for(int i = array_size -1; i >= 0; i--){

        int tmp = array[0];
        array[0] = array[i];
        array[i] = tmp;

        heapsort_heap(array, i, 0);
    };
}
