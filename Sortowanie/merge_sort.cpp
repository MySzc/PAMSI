//
// Created by msz on 3/31/19.
//

#include "merge_sort.h"

void mergesort_merge(int array[], int start_index, int middle_index, int end_index) {

    int array_size = (end_index - start_index) + 1;

    int* tempArray = new int[array_size];

    int left_index = start_index;
    int right_index = middle_index+1;

    int final_array_index = 0;

    while(left_index <= middle_index && right_index <= end_index){

        if(array[left_index] >= array[right_index]){

            tempArray[final_array_index] = array[right_index];

            right_index++;

        }else{

            tempArray[final_array_index] = array[left_index];

            left_index++;

        };

        final_array_index++;

    };


    while(left_index <= middle_index){

        tempArray[final_array_index] = array[left_index];

        left_index++;
        final_array_index++;

    };

    while(right_index <= end_index){
        tempArray[final_array_index] = array[right_index];

        right_index++;
        final_array_index++;

    };


    for (int i = 0; i < array_size; i++) {

        array[start_index + i] = tempArray[i];
    };

    delete[] tempArray;

}

void mergesort_sort(int array[], int start_index, int end_index) {

    if(start_index < end_index){

        int middle_index = (end_index - start_index)/2;

        mergesort_sort(array,start_index,middle_index);
        mergesort_sort(array,middle_index+1,end_index);

        mergesort_merge(array,start_index,middle_index,end_index);

    };

}
