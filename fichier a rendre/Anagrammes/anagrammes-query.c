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
    struct word_array *word_array = malloc(sizeof(struct word_array));
    word_array_create(word_array);
    word_array_read_file(word_array, "dictionnaire.txt");

    // On assure de bien avoir réussi à charger tout les mots
    assert(word_array->size == 325129);

    // Création du dictionnaire
    struct word_dict *dictionnaire = malloc(sizeof(struct word_dict));
    word_dict_create(dictionnaire);
    // On rempli la table avec les valeurs du tableau contenant tous les mots
    word_dict_fill_with_array(dictionnaire, word_array);

    // Boucle de saisie
    for (;;) {
        struct timeval start, end, start_dict, end_dict;

        printf("Letters: ");
        fgets(buf, BUFSIZE, stdin);
        clean_newline(buf, BUFSIZE);
        // Si l'utilisateur envoi une chaine vide on arrête le programme
        if (buf[0] == '\0') {
            break;
        }
        // Sinon on crée un tableau de mots pour stocker les anagrammes
        struct word_array *result = malloc(sizeof(struct word_array));
        word_array_create(result);

        // On mesure le temps de l'exécution avec gettimeofday()
        gettimeofday(&start, NULL);
        word_array_search_anagrams_wildcard(word_array, buf, result);
        gettimeofday(&end, NULL);

        // On transforme le temps en secondes
        double elapse = (end.tv_sec - start.tv_sec) +
                        (end.tv_usec - start.tv_usec) / MILLION;

        // On affiche le résultat du tableau de mot
        word_array_print(result);
        printf("%zu anagrammes trouvés en %lfs pour le mot %s avec le tableau "
               "de mots !\n\n",
               result->size, elapse, buf);

        // Libération de la mémoire prise par le tableau de réponses
        word_array_destroy(result);
        free(result);

        /************ Table de hachage *************/

        // On répête toutes les étapes précédentes
        struct word_array *result_dict = malloc(sizeof(struct word_array));
        word_array_create(result_dict);

        gettimeofday(&start_dict, NULL);
        word_dict_search_anagrams_wildcard(dictionnaire, buf, result_dict);
        word_array_sort(result_dict);
        gettimeofday(&end_dict, NULL);

        double elapse_dict = (end_dict.tv_sec - start_dict.tv_sec) +
                             (end_dict.tv_usec - start_dict.tv_usec) / MILLION;

        // On affiche le résultat de la table de hachage
        word_array_print(result_dict);
        printf("%zu anagrammes trouvés en %lfs pour le mot %s avec la table de "
               "hâchage !\n\n",
               result_dict->size, elapse_dict, buf);
        // Libération de la mémoire prise par le tableau de réponses
        word_array_destroy(result_dict);
        free(result_dict);
    }
    // On libère la mémoire prise par les structures
    word_array_destroy(word_array);
    free(word_array);
    word_dict_destroy(dictionnaire);
    free(dictionnaire);
    return 0;
}
