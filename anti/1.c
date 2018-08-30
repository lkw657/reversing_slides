#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char password[] = "password";

bool testPassword(char* attempt) {
    return strcmp(attempt, password) == 0;
}

int main(int argc, char** argv) {
    printf("Enter password: ");

    char buff[200];
    fgets(buff, sizeof(buff), stdin); // get input
    buff[strlen(buff) - 1] = '\0'; // remove the newline

    if (testPassword(buff)) {
        puts("You win!");
    }
    else {
        puts("You fail");
    }
}
