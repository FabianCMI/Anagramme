#include "anagrammes.h"
#include "assert.h"
#include <stdio.h>

#define BUFSIZE 512

int main(int argc, char *argv[]) {
    char buf[BUFSIZE];
    // Création du dictionnaire
    struct word_array *dico;
    word_array_create(dico);
    word_array_read_file(dico, "dictionnaire.txt");
    word_array_print(dico);
    // On assure de bien avoir réussi à charger tout les mots
    assert(dico->size = 325129);
    for (;;) {
        printf("Letters: ");
        fgets(buf, BUFSIZE, stdin);
        clean_newline(buf, BUFSIZE);
        // Si l'utilisateur envoi une chaine vide on arrête le programme
        if (buf[0] == '\0') {
            return 0;
        }
    }
    // On libère la mémoire prise par le dictionnaire
    word_array_destroy(dico);
    return 0;
}
