#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 10000   // maximum dictionary size
#define WORD_LEN 5        // word length

// ANSI color codes
#define GREEN   "\x1b[42m\x1b[30m"   // green background, black text
#define ORANGE  "\x1b[43m\x1b[30m"   // orange/yellow background, black text
#define GRAY    "\x1b[100m\x1b[30m"  // dark gray background, black text
#define RESET   "\x1b[0m"

// Load dictionary from words.txt
int load_dictionary(const char *filename, char words[][WORD_LEN+1]) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("Error: cannot open %s\n", filename);
        return 0;
    }
    int count = 0;
    while (fscanf(f, "%5s", words[count]) == 1) {
        count++;
        if (count >= MAX_WORDS) break;
    }
    fclose(f);
    return count;
}

// Print feedback with colored letters
void print_colored_feedback(const char *guess, const char *target) {
    for (int i = 0; i < WORD_LEN; i++) {
        if (guess[i] == target[i]) {
            printf(GREEN " %c " RESET, guess[i]);   // correct position → green
        } else if (strchr(target, guess[i])) {
            printf(ORANGE " %c " RESET, guess[i]);  // wrong position → orange/yellow
        } else {
            printf(GRAY " %c " RESET, guess[i]);    // not in word → gray
        }
    }
    printf("\n");
}

// Filter candidates according to feedback
int filter_candidates(char words[][WORD_LEN+1], int count,
                      const char *guess, const char *target) {
    int new_count = 0;
    for (int i = 0; i < count; i++) {
        int valid = 1;
        for (int j = 0; j < WORD_LEN; j++) {
            if (guess[j] == target[j] && words[i][j] != guess[j]) valid = 0;
            if (strchr(target, guess[j]) && words[i][j] == guess[j] && guess[j] != target[j]) valid = 0;
            if (!strchr(target, guess[j]) && strchr(words[i], guess[j])) valid = 0;
        }
        if (valid) {
            strcpy(words[new_count], words[i]);
            new_count++;
        }
    }
    return new_count;
}

// Select the next guess (here: first candidate)
char* select_next_guess(char words[][WORD_LEN+1], int count) {
    if (count > 0) return words[0];
    return NULL;
}

// Main solver loop
void solver(char words[][WORD_LEN+1], int count, const char *target) {
    char guess[WORD_LEN+1] = "arise"; // starting word

    for (int attempt = 1; attempt <= 6; attempt++) {
        printf("Attempt %d: ", attempt);
        print_colored_feedback(guess, target);

        if (strcmp(guess, target) == 0) {
            printf("Found in %d attempts!\n", attempt);
            return;
        }

        count = filter_candidates(words, count, guess, target);
        char *next = select_next_guess(words, count);
        if (!next) break;
        strcpy(guess, next);
    }
    printf("Failed: word not found.\n");
}

int main() {
    char words[MAX_WORDS][WORD_LEN+1];
    int count = load_dictionary("words.txt", words);

    if (count == 0) return 1;

    srand(time(NULL));
    const char *target = words[rand() % count]; // choose random word

    printf("Secret word chosen (debug): %s\n", target);
    solver(words, count, target);

    return 0;
}



