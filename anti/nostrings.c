#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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

int main(int argc, char** argv) {
    char enter[] = {240,219,193,208,199,149,197,212,198,198,194,218,199,209,143,149,181};
    decStr(enter);
    printf(enter);
    fflush(stdout);

    char buff[200];
    fgets(buff, sizeof(buff), stdin); // get input
    buff[strlen(buff) - 1] = '\0'; // remove the newline

    if (testPassword(buff)) {
	char win[] = {236,218,192,149,194,220,219,148,181};
	decStr(win);
	puts(win);
    }
    else {
	char fail[] = {236,218,192,149,211,212,220,217,181};
	decStr(fail);
        puts(fail);
    }
}
