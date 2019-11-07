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
    for (;;) {
        struct timeval start, end;

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
        gettimeofday(&start, NULL);
        word_array_search_anagrams_wildcard(word_array, buf, result);
        gettimeofday(&end, NULL);
        double elapse = (end.tv_sec - start.tv_sec) +
                        (end.tv_usec - start.tv_usec) / MILLION;
        word_array_print(result);
        printf("%zu anagrammes trouvés en %lfs pour le mot %s !\n\n",
               result->size, elapse, buf);
        // Libération de la mémoire prise par le tableau de réponses
        word_array_destroy(result);
    }
    // On libère la mémoire prise par le dictionnaire
    word_array_destroy(word_array);
    
    // Création du tableau pour stocker les mots
    struct word_array *word_dict = malloc(sizeof(struct word_array));
    word_array_create(word_dict);
    word_array_add(word_dict,"abc");
    word_array_add(word_dict,"tame");
    word_array_add(word_dict,"sa");
    word_array_add(word_dict,"sal");
    word_array_add(word_dict,"niqu");
    word_array_add(word_dict,"suce");
    word_array_add(word_dict,"pd");
    word_array_add(word_dict,"ess");
    word_array_add(word_dict,"sale");
    word_array_add(word_dict,"gros");
    struct word_dict *word_dict2 = malloc(sizeof(struct word_dict));
    word_dict_create(word_dict2);
    word_dict_fill_with_array(word_dict2,word_dict);

    for (size_t i =0 ; i< word_dict2->size; ++i){
        if (word_dict2->buckets[i]!=NULL){
        printf("%s \n",word_dict2->buckets[i]->word);
        }
    }

    return 0;
}