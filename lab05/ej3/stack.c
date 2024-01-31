#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

stack stack_empty() {
    stack s = malloc(sizeof(struct _s_stack));
    s->capacity = 1;
    s->size = 0;
    s->elems = malloc(sizeof(stack_elem));
    return s;
}

stack stack_push(stack s, stack_elem e) {
    if (s->size == s->capacity) {
        s->capacity *= 2;
        s->elems = realloc(s->elems, sizeof(stack_elem) * s->capacity);
    }
    s->elems[s->size] = e;
    s->size++;
    return s;
}

stack stack_pop(stack s) {
    assert(s->size > 0);
    s->size--;
    return s;
}

unsigned int stack_size(stack s) {
    return s->size;
}

stack_elem stack_top(stack s) {
    assert(s->size > 0);
    return s->elems[s->size - 1];
}

bool stack_is_empty(stack s) {
    return s->size == 0;
}

stack_elem *stack_to_array(stack s) {
    return s->elems;
}

stack stack_destroy(stack s) {
    free(s->elems);
    free(s);
    return s;
}