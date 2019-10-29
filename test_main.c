#include "anagrammes.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char str1[] = "hello";
    char str2[] = "heklw";
    bool is_ana = string_are_anagrams(str1, str2);
    printf("%d\n", is_ana);
    struct word_array *test;
    word_array_create(test);
    *(test->data) = str1;
    *(test->data + 1) = str2;
    *(test->data + 2) = string_duplicate(str1);
    test->size = 3;
    word_array_print(test);
    return 0;
}
