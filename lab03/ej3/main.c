#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

unsigned int data_from_file(const char *path,
                            unsigned int indexes[],
                            char letters[],
                            unsigned int max_size) {
    FILE *file;
    file = fopen(path, "r");
    if(file == NULL) {
        perror("error de archivo\n");
        return 0;
    }
    unsigned int i = 0;
    while(!feof(file)) {
        fscanf(file, "%u -> *%c*\n", &indexes[i], &letters[i]);
        i++;
    }
    fclose(file);
    return i;
}

int main(int argc, char *argv[]) {
    const char *file = argv[1];
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length=0; 
    //  .----------^
    //  :
    // Debe guardarse aqui la cantidad de elementos leidos del archivo
    if(argc != 2) {
        printf("pocos argumentos\n");
        return 1;
    }
    
    length = data_from_file(file, indexes, letters, MAX_SIZE);

    dump(letters, length);

    for (unsigned int i = 0; i < length; i++) {
        sorted[indexes[i]] = letters[i];
    }

    dump(sorted, length);

    return EXIT_SUCCESS;
}