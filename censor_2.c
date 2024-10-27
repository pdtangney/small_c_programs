/* Word censor program.
 * Searches str for term. Replaces every instance of term with censor_char.
 *
 * void censor(char *str, *char term, char censor_char);
 *
 * Parameters:
 * str - a null-terminated array of characters to examine.
 * term - a null-terminated array or string literal, which is the term
 * searched for in str.
 * censor_char - a single character which will replace all occurances of term.
 *
 * EXAMPLE:
 * Before: A foorking fool eats food for breakfast
 * After:  A ***rking ***l eats ***d for breakfast
 */

#include <string.h>
#include <stdio.h>

#define MAX_LEN 1024

void censor(char *string, char *term, char censor_char);

void censor(char *string, char *term, char censor_char) {
    int term_len = strlen(term);

    for (; *string; string++) {
        for (int i = 0; i < term_len;) {
            if (*(string + i) == *(term + i)) {
                i++;
            } else {
                break;
            }
            if (i == term_len) {
                while (i-- > 0) {
                    *(string + i) = censor_char;
                }
            }
        }
    }
}

int main(void) {
    char string[MAX_LEN];
    /* "offending" term to search for*/
    char *term = "foo";
    /* Replace term with replacement: */
    char replacement = '*';

    fgets(string, MAX_LEN, stdin);
    string[strcspn(string, "\n")] = 0;
    printf("Before: %s \n", string);
    censor(string, term, replacement);
    printf("Censored: %s\n", string);

    return 0;
}
