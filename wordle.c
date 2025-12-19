#include <stdio.h>
#include <string.h>
#include "wordle.h"

int load_dictionary(const char *filename, char words[MAX_WORDS][WORD_LEN+1]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Could not open dictionary file.\n");
        return 0;
    }

    int count = 0;
    while (fscanf(file, "%5s", words[count]) == 1 && count < MAX_WORDS) {
        count++;
    }
    fclose(file);
    return count;
}

int is_valid_guess(char *guess, char words[MAX_WORDS][WORD_LEN+1], int word_count) {
    if (strlen(guess) != WORD_LEN) return 0;
    for (int i = 0; i < word_count; i++) {
        if (strcmp(guess, words[i]) == 0) return 1;
    }
    return 0;
}

void give_feedback(char *guess, char *target) {
    for (int i = 0; i < WORD_LEN; i++) {
        if (guess[i] == target[i]) {
            // Case verte
            printf("\033[42m %c \033[0m", guess[i]);
        } else if (strchr(target, guess[i])) {
            // Case jaune
            printf("\033[43m %c \033[0m", guess[i]);
        } else {
            // Case grise
            printf("\033[47m %c \033[0m", guess[i]);
        }

        // Espace entre les cases, mais pas après la dernière
        if (i < WORD_LEN - 1) {
            printf(" ");
        }
    }
    printf("\n");
    }

