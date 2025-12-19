#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordle.h"

int main() {
    char words[MAX_WORDS][WORD_LEN+1];
    int word_count = load_dictionary("words.txt", words);

    // Ask the user to enter the target word FIRST
    char target[WORD_LEN+1];
    printf("Enter the target word (must be in dictionary): ");
    scanf("%5s", target);

    // Validate that the target word exists in dictionary
    if (!is_valid_guess(target, words, word_count)) {
        printf("Invalid target word. Exiting.\n");
        return 1;
    }

    // Now start the game
    printf("Welcome to Wordle!\n");

    char guess[WORD_LEN+1];
    int won = 0;

    for (int attempt = 1; attempt <= MAX_ATTEMPTS; attempt++) {
        printf("Attempt %d/%d: ", attempt, MAX_ATTEMPTS);
        scanf("%5s", guess);

        if (!is_valid_guess(guess, words, word_count)) {
            printf("Invalid guess. Try again.\n");
            attempt--; // invalid guesses don’t consume attempts
            continue;
        }

        give_feedback(guess, target);

        if (strcmp(guess, target) == 0) {
            printf("\033[1;32mYou win in %d attempts!\033[0m\n", attempt);
            won = 1;
            break;
        }
    }

    if (!won) {
        printf("\033[1;31mYou lost. The word was: %s\033[0m\n", target);
    }

    return 0;
}
