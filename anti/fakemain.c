#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void decStr(char* str) {
    int len = strlen(str);
    for (int i=0; i<len; i++) {
        str[i] ^= 181;
    }
}

bool testPassword(char* attempt) {
    if (strlen(attempt) != 8)
        return false;
    char password[] = {197, 212, 198, 198, 194, 218, 199, 209};
    decStr(attempt);
    for (int i=0; i < 8; i++) {
        if (attempt[i] != password[i])
            return false;
    }
    return true;
}

// This happens before main
void __attribute__((constructor)) start() {
    printf("Enter password: ");
    fflush(stdout);

    char buff[200];
    fgets(buff, sizeof(buff), stdin); // get input
    buff[strlen(buff) - 1] = '\0'; // remove the newline

    if (testPassword(buff)) {
        puts("You win!");
    }
    else {
        puts("You fail");
    }
    // exit before main is run
    exit(EXIT_SUCCESS);
}


int main() {
    printf("Enter password: ");
    fflush(stdout);

    char buff[200];
    fgets(buff, sizeof(buff), stdin);
    buff[strlen(buff) - 1] = '\0';

    if (strcmp(buff, "1234") == 0) {
        puts("You win!");
    }
    else {
        puts("You fail");
    }
}
