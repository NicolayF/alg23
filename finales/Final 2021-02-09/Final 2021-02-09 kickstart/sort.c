#include <stdlib.h>
#include <stdio.h>
#include "sorted_list.h"
#include "sort.h"

void sort(int a[], unsigned int length)
{
    sorted_list_t new_list = sorted_list_empty();
    for (unsigned int i = 0; i < length; i++){
        new_list = sorted_list_append(new_list, a[i]);
    }
    for (unsigned int i = 0; i < length; i++){
        a[i] = sorted_list_head(new_list);
        new_list = sorted_list_tail(new_list);
    }
    new_list = sorted_list_destroy(new_list);
}
