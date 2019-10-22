#include "anagrammes.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Part 1

bool string_are_anagrams(const char *str1, const char *str2) {
    size_t length = strlen(str1);
    if (length != strlen(str2)) {
        return false;
    }
    const size_t LETTER_NUMBER = 26;
    // On crée un tableau pour compter les occurences des 26 lettres de
    // l'alphabet
    int *tab_letters_count = calloc(LETTER_NUMBER, sizeof(char));

    // On parcourt la première chaine et on incrémente le nombre de chaque
    // lettre à chaque fois qu'elle apparait dans le mot.En parallèle on
    // parcourt la deuxième chaine et on décrémente à chaque occurence des
    // lettres
    for (size_t i = 0; i < length; ++i) {
        tab_letters_count[str1[i] - 'a']++;
        tab_letters_count[str2[i] - 'a']--;
    }
    // Si toutes les cases (donc le compte des lettres) sont égales à 0, alors
    // les mots sont des anagrammes
    for (size_t i = 0; i < LETTER_NUMBER; i++) {
        if (tab_letters_count[i] != 0) {
            return false;
        }
    }
    return true;
}

char *string_duplicate(const char *str) { return NULL; }

void string_sort_letters(char *str) {}

void clean_newline(char *buf, size_t size) {}

// Part 2

void word_array_create(struct word_array *self) {}

void word_array_destroy(struct word_array *self) {}

void word_array_add(struct word_array *self, const char *word) {}

void word_array_search_anagrams(const struct word_array *self, const char *word,
                                struct word_array *result) {}

void word_array_sort(struct word_array *self) {}

void word_array_print(const struct word_array *self) {}

void word_array_read_file(struct word_array *self, const char *filename) {
    char word[WORD_LETTERS_MAX];

    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        fprintf(stderr, "Error when opening file '%s'\n", filename);
        return;
    }

    while (!feof(fp)) {
        fgets(word, WORD_LETTERS_MAX, fp);
        clean_newline(word, WORD_LETTERS_MAX);
        word_array_add(self, word);
    }

    fclose(fp);
}

// Part 3

void word_dict_bucket_destroy(struct word_dict_bucket *bucket) {}

struct word_dict_bucket *word_dict_bucket_add(struct word_dict_bucket *bucket,
                                              const char *word) {
    return NULL;
}

void word_dict_create(struct word_dict *self) {}

void word_dict_destroy(struct word_dict *self) {}

size_t fnv_hash(const char *key) { return 0; }

void word_dict_rehash(struct word_dict *self) {}

void word_dict_add(struct word_dict *self, const char *word) {}

void word_dict_fill_with_array(struct word_dict *self,
                               const struct word_array *array) {}

void word_dict_search_anagrams(const struct word_dict *self, const char *word,
                               struct word_array *result) {}

// Part 4

void wildcard_create(struct wildcard *self) {}

void wildcard_search(struct wildcard *self, const char *word) {}

void word_array_search_anagrams_wildcard(const struct word_array *self,
                                         const char *word,
                                         struct word_array *result) {}

void word_dict_search_anagrams_wildcard(const struct word_dict *self,
                                        const char *word,
                                        struct word_array *result) {}
