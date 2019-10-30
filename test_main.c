#include "anagrammes.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char str1[] = "hello";
    char str2[] = "ehllo";
    bool is_ana = string_are_anagrams(str1, str2);
    printf("%d\n", is_ana);
    struct word_array *test = malloc(sizeof(struct word_array));
    word_array_create(test);
    word_array_add(test, str1);
    word_array_add(test, str2);
    word_array_add(test, string_duplicate(str1));
    // test pour voir si le array_grow marche bien
    for (size_t i = 0; i < 15; i++) {
        word_array_add(test, str1);
    }
    string_sort_letters(*test->data);
    word_array_print(test);
    word_array_destroy(test);
    return 0;
}
