//
// Created by msz on 4/2/19.
//

#include "insert_sort.h"

void insertionsort_sort(int array[], int array_size) {

    for (int i = 1; i < array_size; ++i) {

        int boundary = array[i];

        int j = i - 1;

        while (j >= 0) {

            if (array[j] > boundary)
                array[j + 1] = array[j];
            else
                break;

            j--;

        };

        array[j+1] = boundary;

    };

}
