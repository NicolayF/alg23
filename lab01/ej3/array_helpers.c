#include "array_helpers.h"
#include <stdio.h>

unsigned int array_from_file(int array[],
           unsigned int max_size,
           const char *filepath) {
    //your code here!!!
    FILE *path;
    path = fopen(filepath, "r");

    unsigned int length;
    fscanf(path, "%u", &length);

    for (unsigned int i = 0; i < max_size; i++){
        fscanf(path, "%d", &array[i]);
    }
    
    fclose(path);
    return length;
}

void array_dump(int a[], unsigned int length) {
    //your code here!!!!!
    for (unsigned int i = 0; i < length; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    
}