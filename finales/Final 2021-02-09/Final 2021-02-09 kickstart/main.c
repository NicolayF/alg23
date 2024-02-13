#include <stdio.h>
#include <stdlib.h>
#include "sorted_list.h"
#include "sort.h"
#define MAX_SIZE 8

int main()
{
    elem_t array[MAX_SIZE] = {3,4,1,5,7,0,8,6};
    sorted_list_t new_list = sorted_list_empty();
    sorted_list_t new_list_take = sorted_list_empty();
    sorted_list_t new_list_drop = sorted_list_empty();

    printf("array: ");
    for (unsigned int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    sort(array, MAX_SIZE);
    printf("sorted array: ");
    for (unsigned int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("sorted list: ");
    for (unsigned int i = 0; i < MAX_SIZE; i++){
        new_list = sorted_list_append(new_list, array[i]);
    }
    sorted_list_print(new_list);
    printf(",");
    printf("list length: %u ,",sorted_list_length(new_list));
    printf("index 2: %d",sorted_list_elem_at(new_list, 2));
    printf("\n");

    printf("take func: ");
    new_list_take = sorted_list_take(new_list, 5);
    sorted_list_print(new_list_take);
    printf("\n");

    printf("drop func: ");
    new_list_drop = sorted_list_drop(new_list, 5);
    sorted_list_print(new_list_drop);
    printf("\n");

    new_list = sorted_list_destroy(new_list);
    new_list_take = sorted_list_destroy(new_list_take);
    new_list_drop = sorted_list_destroy(new_list_drop);
    return 0;
}