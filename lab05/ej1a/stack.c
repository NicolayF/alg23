#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack {
    unsigned int size;
    node top;
};

struct _s_node {
    stack_elem elem;
    node next;
};

stack stack_empty() {
    stack new_stack = malloc(sizeof(struct _s_stack));
    new_stack->size = 0;
    new_stack->top = NULL;
    return new_stack;
}

stack stack_push(stack s, stack_elem e) {
    node new_node = malloc(sizeof(struct _s_node));
    new_node->elem = e;
    new_node->next = s->top;
    s->top = new_node;
    s->size++;
    return s;
}

stack stack_pop(stack s) {
    assert(!stack_is_empty(s));
    node n_temp = s->top;
    s->top = s->top->next;
    free(n_temp);
    s->size--;
    return s;
}

unsigned int stack_size(stack s) {
    return s->size;
}

stack_elem stack_top(stack s) {
    assert(!stack_is_empty(s));
    return s->top->elem;
}

bool stack_is_empty(stack s) {
    return s->size == 0;
}

stack_elem *stack_to_array(stack s) {
    stack_elem *array = NULL;
    if(stack_size(s) > 0){
        array = calloc(stack_size(s), sizeof(stack_elem));
        node n_temp = s->top;
        for (unsigned int i = 0; i < stack_size(s); i++) {
            array[i] = n_temp->elem;
            n_temp = n_temp->next;
        }
    }
    return array;
}

stack stack_destroy(stack s) {
    node n_temp = s->top;
    while(s->top != NULL){
        s->top = s->top->next;
        free(n_temp);
        n_temp = s->top;
    }
    free(s);
    return s;
}