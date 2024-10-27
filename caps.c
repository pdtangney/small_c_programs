/* Caps is a little program which takes a sentence and CaPiTaLiZes every other
 * letter in it.
 *
 * This is a stand-alone console program which can be compiled on its own.
 * LINUX:
 * COMPILING: gcc -caps.c -o caps
 * RUN IT: ./caps
 */

#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

/* maximum length of input: */
#define MAX_LEN 1024

void caps(char *sentence) {
    int cap_or_small_first = (rand() % 2);
    switch (cap_or_small_first) {
        case 0:
            for (; *sentence; sentence++) {
                *sentence = tolower(*sentence);
                sentence++;
                *sentence = toupper(*sentence);
            }
            break;
        case 1:
            for (; *sentence; sentence++) {
                *sentence = toupper(*sentence);
                sentence++;
                *sentence = tolower(*sentence);
            }
    }
}

int main(void) {
    char input[MAX_LEN];

    srand(time(NULL));

    printf("Enter sentence to be ReCaPiTaLiZeD >");
    fgets(input, MAX_LEN, stdin);
    /* search for \n and replace with null */
    input[strcspn(input, "\n")] = 0;
    printf("Before: %s\n", input);
    caps(input);
    printf("After:  %s\n", input);

    return 0;
}
