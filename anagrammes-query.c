#include "anagrammes.h"
#include "assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define BUFSIZE 512
#define MILLION 1E6

int main(int argc, char *argv[]) {
    char buf[BUFSIZE];
    // Création du tableau pour stocker les mots
    struct word_array *word_array = malloc(sizeof(struct word_array));;
    word_array_create(word_array);
    word_array_read_file(word_array, "dictionnaire.txt");

    // On assure de bien avoir réussi à charger tout les mots
    assert(word_array->size = 325129);
    for (;;) {
        int test = gettimeofday();
        //struct timespec start, end;

        printf("Letters: ");
        fgets(buf, BUFSIZE, stdin);
        clean_newline(buf, BUFSIZE);
        // Si l'utilisateur envoi une chaine vide on arrête le programme
        if (buf[0] == '\0') {
            break;
        }
        // Sinon on crée un tableau de mot pour stocker les anagrammes
        struct word_array *result = malloc(sizeof(struct word_array));
        word_array_create(result);
        printf("%zu \n",result->size);
        //clock_gettime(CLOCK_MONOTONIC, &start);
        word_array_search_anagrams(word_array, buf, result);
        //clock_gettime(CLOCK_MONOTONIC, &end);
        //double elapse = (end.tv_sec - start.tv_sec) +
        //                (end.tv_nsec - start.tv_nsec) / BILLION;
        word_array_print(result);
        printf("%zu anagrammes trouvés en 0seconde !\n\n", result->size);
        // Libération de la mémoire prise par le tableau de réponses
        word_array_destroy(result);
    }
    // On libère la mémoire prise par le dictionnaire
    word_array_destroy(word_array);
    return 0;
}
