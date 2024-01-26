#include "pair.h"
#include <stdlib.h>

struct s_pair_t {
    elem fst;
    elem snd;
};

pair_t pair_new(elem x, elem y) {
    pair_t new_pair = malloc(sizeof(pair_t));
    new_pair->fst = x;
    new_pair->snd = y;
    return new_pair;
}

int pair_first(pair_t p) {
    return p->fst;
}

int pair_second(pair_t p) {
    return p->snd;
}

pair_t pair_swapped(pair_t p) {
    pair_t new_pair = malloc(sizeof(pair_t));
    new_pair->fst = p->snd;
    new_pair->snd = p->fst;
    return new_pair;
}

pair_t pair_destroy(pair_t p) {
    free(p);
    p = NULL;
    return p;
}
