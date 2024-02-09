#include "domino_line.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "domino.h"

struct _s_line
{
    unsigned int size;
    int points;
    line_iterator fst;
    line_iterator lst;
};

struct _line_node
{
    domino dom;
    line_iterator next;
};

domino_line line_new(domino first)
{
    assert(domino_is_double(first));
    domino_line new_dl = malloc(sizeof(struct _s_line));
    line_iterator new_lit = malloc(sizeof(struct _line_node));
    domino first_domino = domino_new(domino_up(first), domino_down(first));
    new_lit->dom = first_domino;
    new_lit->next = NULL;
    new_dl->size = 1;
    new_dl->points = domino_up(first) + domino_down(first);
    new_dl->fst = new_lit;
    new_dl->lst = new_lit;
    assert(new_dl != NULL);
    return new_dl;
}

domino_line line_add(domino_line line, domino t)
{
    line_iterator new_lit = malloc(sizeof(struct _line_node));
    domino new_domino = domino_new(domino_up(t), domino_down(t));
    new_lit->dom = new_domino;
    new_lit->next = NULL;
    line->lst->next = new_lit;
    line->lst = new_lit;
    line->points += domino_up(t) + domino_down(t);
    line->size++;
    return line;
}

unsigned int line_length(domino_line line)
{
    assert(line != NULL);
    return line->size;
}

bool line_n_correct(domino_line line, unsigned int n)
{
    assert(n < line_length(line));
    bool is_correct = true;
    if(n > 0){
        line_iterator current = line->fst;
        line_iterator checker = line->fst;
        for (unsigned int i = 0; i < n-1; i++) {
            current = current->next;
            checker = checker->next;
        }
        current = current->next;
        if(!domino_matches(current->dom, checker->dom)){
            return false;
        }
        checker = current->next;
        if(checker != NULL){
            if(!domino_matches(checker->dom ,current->dom)){
                return false;
            }
        }
    }
    return is_correct;
}

int line_total_points(domino_line line)
{
    assert(line != NULL);
    return line->points;
}

domino* line_to_array(domino_line line)
{
    domino *new_array = malloc(sizeof(domino) * line_length(line));
    line_iterator aux = line->fst;
    for (unsigned int i = 0; i < line_length(line); i++) {
        new_array[i] = aux->dom;
        aux = aux->next;
    }
    return new_array;
}

void line_dump(domino_line line)
{
    domino* array = line_to_array(line);
    for (unsigned int i = 0u; i < line_length(line); i++)
    {
        domino_dump(array[i]);
    }
    free(array);
}

domino_line line_destroy(domino_line line)
{
    line_iterator aux = line->fst;
    while (aux!= NULL){
        aux = aux->next;
        domino_destroy(aux->dom);
        free(line->fst);
        line->fst = aux;
    }
    free(line);
    assert(line == NULL);
    return line;
}

line_iterator line_iterator_begin(domino_line line)
{
    line_iterator lit = line->fst;
    assert(line_length(line) == 0 || lit != NULL);
    return lit;
}

domino line_iterator_get(line_iterator lit)
{
    return lit->dom;
}

line_iterator line_iterator_next(line_iterator lit)
{
    lit = lit->next;
    return lit;
}

bool line_iterator_end(line_iterator lit)
{
    return lit == NULL;
}
