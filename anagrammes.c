#include "anagrammes.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fonction permettant d'augmenter la capacité d'un tableau de mot
static void word_array_grow(struct word_array *self) {
    size_t capacity = self->capacity * 2;
    char **new_array = calloc(capacity, sizeof(char *));
    memcpy(new_array, self->data, self->size * sizeof(char *));
    free(self->data);
    self->data = new_array;
    self->capacity = capacity;
}

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
    // On initialise toutes les valeurs du tableau à 0
    for (size_t i = 0; i < LETTER_NUMBER; i++) {
        tab_letters_count[i] = 0;
    }
    // On parcourt la première chaine et on incrémente le nombre de chaque
    // lettre à chaque fois qu'elle apparait dans le mot. En parallèle on
    // parcourt la deuxième chaine et on décrémente à chaque occurence des
    // lettres
    size_t letter_num_1 = 0;
    size_t letter_num_2 = 0;
    for (size_t i = 0; i < length; ++i) {
        letter_num_1 = str1[i] - 'a';
        letter_num_2 = str2[i] - 'a';
        assert(letter_num_1 < 26);
        assert(letter_num_2 < 26);
        tab_letters_count[letter_num_1]++;
        tab_letters_count[letter_num_2]--;
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

char *string_duplicate(const char *str) {
    char *st = calloc(strlen(str), sizeof(char));
    return strcpy(st, str);
}

void string_sort_letters(char *str) {
    for (size_t i = 1; i < strlen(str); ++i) {
        char x = str[i];
        size_t j = i;
        while (j > 0 && str[j - 1] > x) {
            str[j] = str[j - 1];
            j--;
        }
        str[j] = x;
    }
}

void clean_newline(char *buf, size_t size) {}

// Part 2

void word_array_create(struct word_array *self) {
    self->size = 0;
    self->capacity = 10;
    self->data = calloc(self->capacity, sizeof(char *));
    *self->data = NULL;
}

// Détruit un tableau de mot
void word_array_destroy(struct word_array *self) {
    for (size_t i = 0; i < self->capacity; i++) {
        free(*(self->data + i));
    }
    self->capacity = 0;
    self->size = 0;
    free(self->data);
}

// Ajoute une string à la fin du tableau
void word_array_add(struct word_array *self, const char *word) {
    char *p = string_duplicate(word);
    if (self->size >= self->capacity) {
        word_array_grow(self);
    }
    self->data[self->size] = p;
    self->size++;
}

void word_array_search_anagrams(const struct word_array *self, const char *word,
                                struct word_array *result) {}

static void array_swap(int *data, size_t i, size_t j) {
    int tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
}

static ptrdiff_t array_partition(int *data, ptrdiff_t i, ptrdiff_t j) {
    ptrdiff_t pivot_index = i;
    const int pivot = data[pivot_index];
    array_swap(data, pivot_index, j);
    ptrdiff_t l = i;
    for (ptrdiff_t k = i; k < j; ++k) {
        if (data[k] < pivot) {
            array_swap(data, k, l);
            l++;
        }
    }
    array_swap(data, l, j);
    return l;
}

static void array_quick_sort_partial(int *data, ptrdiff_t i, ptrdiff_t j) {
    if (i < j) {
        ptrdiff_t p = array_partition(data, i, j);
        array_quick_sort_partial(data, i, p - 1);
        array_quick_sort_partial(data, p + 1, j);
    }
}

static void array_quick_sort(int *data, size_t n) {
    array_quick_sort_partial(data, 0, n - 1);
}

void word_array_sort(struct word_array *self) {}

void word_array_print(const struct word_array *self) {
    for (size_t i = 0; i < self->size; i++) {
        printf("%s\n", self->data[i]);
    }
}

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
