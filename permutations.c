#include <stdio.h>
#include <string.h>

void ExchangeCharacters(char str[], int i, int j) {
    char tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
}

void RecursivePermute(char str[], int k) {
    int j;
    // Base-case: Since all letters are fixed, we can ONLY print what's stored in str.
    if (k == strlen(str))
        printf("%s\n", str);
    else {
        // Loop through each possible starting letter for index k, the first index for which we have a choice.
        for (j = k; j < strlen(str); j++) {
            // Place the character stored in index j in location k.
            ExchangeCharacters(str, k, j);

            // Print out all of the permutations with that character just chosen above fixed.
            RecursivePermute(str, k + 1);

            // Put the original character that used to be there back in its place.
            ExchangeCharacters(str, j, k);
        }
    }
}

int main() {
    char str[] = "CAT";
    RecursivePermute(str, 0);
    return 0;
}