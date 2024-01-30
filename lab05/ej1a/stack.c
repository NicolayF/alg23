#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack {
    stack_elem elem;
    stack next;
};

stack stack_empty() {
    stack new_stack = NULL;
    return new_stack;
}

stack stack_push(stack s, stack_elem e) {
    stack new_stack = stack_empty();
    new_stack = malloc(sizeof(struct _s_stack));
    new_stack->elem = e;
    new_stack->next = s;
    s = new_stack;
    return s;
}

stack stack_pop(stack s) {
    assert(!stack_is_empty(s));
    stack s_temp = s;
    s = s->next;
    free(s_temp);
    return s;
}

unsigned int stack_size(stack s) {
    unsigned int length = 0;
    stack s_temp = s;

    while (s_temp != NULL){ 
        length++;
        s_temp = s_temp->next;
    }
    return length; 
}

stack_elem stack_top(stack s) {
    assert(!stack_is_empty(s));
    return s->elem;
}

bool stack_is_empty(stack s) {
    return s == NULL;
}

stack_elem *stack_to_array(stack s) {
    stack_elem *array = NULL;
    if(stack_size(s) > 0){
        array = calloc(stack_size(s), sizeof(stack_elem));
        stack s_temp = s;
        for (unsigned int i = 0; i < stack_size(s); i++) {
            array[i] = s_temp->elem;
            s_temp = s_temp->next;
        }
    }
    return array;
}

stack stack_destroy(stack s) {
    stack s_temp = s;
    while(s == NULL){
        s = s->next;
        free(s_temp);
        s_temp = s;
    }
    return s;
}