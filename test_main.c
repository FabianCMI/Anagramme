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
    printf("%d", is_ana);

    return 0;
}
