#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

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

void moved() {
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
    exit(EXIT_SUCCESS);
}

int main(int argc, char** argv) {
    struct sigaction sigint = {};
    sigint.sa_flags = SA_SIGINFO;
    sigint.sa_sigaction = moved;
    sigaction(SIGTRAP, &sigint, NULL);
    // send SIGTRAP
    kill(getpid(), SIGTRAP);
    puts("No debugging!");
}
