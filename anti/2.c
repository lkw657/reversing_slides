#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool testPassword(char* attempt) {
    if (strlen(attempt) != 8)
        return false;
    if (attempt[0] != 'p')
        return false;
    if (attempt[1] != 'a')
        return false;
    if (attempt[2] != 's')
        return false;
    if (attempt[3] != 's')
        return false;
    if (attempt[4] != 'w')
        return false;
    if (attempt[5] != 'o')
        return false;
    if (attempt[6] != 'r')
        return false;
    if (attempt[7] != 'd')
        return false;
    return true;
}

int main(int argc, char** argv) {
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
}
