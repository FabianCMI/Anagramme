#include "anagrammes.h"
#include "assert.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 512

int main(int argc, char *argv[]) {
    char buf[BUFSIZE];
    // Création du tableau pour stocker les mots
    struct word_array *word_array = malloc(sizeof(struct word_array));
    word_array_create(word_array);
    word_array_read_file(word_array, "dictionnaire.txt");

    // On assure de bien avoir réussi à charger tout les mots
    assert(word_array->size = 325129);

    for (;;) {
        // On crée le tableau de mots résultat
        struct word_array *result = malloc(sizeof(struct word_array));
        word_array_create(result);
        printf("Letters: ");
        fgets(buf, BUFSIZE, stdin);
        clean_newline(buf, BUFSIZE);
        word_array_search_anagrams(word_array, buf, result);
        word_array_print(result);
        // Si l'utilisateur envoi une chaine vide on arrête le programme
        if (buf[0] == '\0') {
            break;
        }
        word_array_destroy(result);
    }

    // On libère la mémoire prise par le dictionnaire
    word_array_destroy(word_array);

    return 0;
}
