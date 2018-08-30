#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char password[] = "password";

bool testPassword(char* attempt) {
    return strcmp(attempt, password) == 0;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        puts("Give the password as a command line argument");
        exit(EXIT_FAILURE);
    }
    if (testPassword(argv[1])) { // 0 is name of program/command
        puts("You win!");
    }
    else {
        puts("You fail");
    }
}
