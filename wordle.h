#define WORD_LEN 5
#define MAX_ATTEMPTS 6
#define MAX_WORDS 10000

int load_dictionary(const char *filename, char words[MAX_WORDS][WORD_LEN+1]);
int is_valid_guess(char *guess, char words[MAX_WORDS][WORD_LEN+1], int word_count);
void give_feedback(char *guess, char *target);
