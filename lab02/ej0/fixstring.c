#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    unsigned int i = 0;
    // if s[i] is '\0' (null char)
    while (s[i]) {
        i++;
    }
    return i;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    if (fstring_length(s1) != fstring_length(s2)) {
        return false;
    }
    for (unsigned int i = 0; i < fstring_length(s1); i++) {
        if (s1[i] != s2[i]) {
            return false;
        }
    }
    return true;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    unsigned int i = 0;
    // if s[i] is '\0' (null char)
    while (s1[i] && s2[i] && s1[i] == s2[i]) {
        i++;
    }
    return s1[i] <= s2[i];
}

