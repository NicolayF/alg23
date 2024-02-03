/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "abb.h" /* TAD abb */


void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

abb abb_from_file(const char *filepath) {
    FILE *file = NULL;
    abb read_tree;

    read_tree = abb_empty();
    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    unsigned int i = 0u;
    unsigned int size = 0u;
    int res = 0;
    res = fscanf(file, " %u ", &size);
    if (res != 1) {
        fprintf(stderr, "Invalid format.\n");
        exit(EXIT_FAILURE);
    }
    while (i < size) {
        abb_elem elem;
        res = fscanf(file," %d ", &(elem));
        if (res != 1) {
            fprintf(stderr, "Invalid array.\n");
            exit(EXIT_FAILURE);
        }
        read_tree = abb_add(read_tree, elem);
        ++i;
    }
    fclose(file);
    return read_tree;
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* parse the file to obtain an abb with the elements */
    abb tree = abb_from_file(filepath);

    /*dumping the tree*/
    abb_dump(tree);

    /*
     * Modificar e implementar con un ciclo una interfaz que permita al usuario
     * realizar una de las siguientes operaciones en cada iteración:
     *
     * 1 ........ Mostrar árbol por pantalla
     * 2 ........ Agregar un elemento
     * 3 ........ Eliminar un elemento
     * 4 ........ Chequear existencia de elemento
     * 5 ........ Mostrar longitud del árbol
     * 6 ........ Mostrar raiz, máximo y mínimo del árbol
     * 7 ........ Salir
     *
     * Se debe solicitar un número de entrada para realizar una de las acciones.
     *
     * Para las opciones 2, 3 y 4 se le deberá pedir al usuario que ingrese el
     * elemento a agregar, eliminar o chequear respectivamente.
     *
     * Al salir debe liberarse toda la memoria utilizada.
     *
     */
    bool exit = true;
    unsigned int menu;
    while(exit){
        printf("\n"
        "Ingrese\n"
        "* 1 ........ Mostrar árbol por pantalla\n"
        "* 2 ........ Agregar un elemento\n"
        "* 3 ........ Eliminar un elemento\n"
        "* 4 ........ Chequear existencia de elemento\n"
        "* 5 ........ Mostrar longitud del árbol\n"
        "* 6 ........ Mostrar raiz, máximo y mínimo del árbol\n"
        "* 7 ........ Salir\n");
        scanf("%u", &menu);
        switch(menu){
            case 1:
                abb_dump(tree);
                if(abb_is_empty(tree)){
                    printf("El árbol está vacío\n");
                }
                break;
            case 2:
                printf("Ingrese el elemento a agregar\n");
                abb_elem elem;
                scanf("%d", &elem);
                tree = abb_add(tree, elem);
                break;
            case 3:
                printf("Ingrese el elemento a eliminar\n");
                abb_elem elem2;
                scanf("%d", &elem2);
                tree = abb_remove(tree, elem2);
                break;
            case 4:
                printf("Ingrese el elemento a buscar\n");
                abb_elem elem3;
                scanf("%d", &elem3);
                if (abb_exists(tree, elem3)) {
                    printf("El elemento %d existe\n", elem3);
                } else {
                    printf("El elemento %d no existe\n", elem3);
                }
                break;
            case 5:
                printf("La longitud del arbol es %u", abb_length(tree));
                break;
            case 6:
                if(!abb_is_empty(tree)){
                    printf("raiz: %d\nminimo: %d\nmaximo: %d\n", abb_root(tree),
                                                        abb_min(tree),
                                                        abb_max(tree));
                }
                else{
                    printf("El árbol está vacío\n");
                }
                break;
            case 7:
                tree = abb_destroy(tree);
                exit = false;
        }
    }
    return (EXIT_SUCCESS);
}
