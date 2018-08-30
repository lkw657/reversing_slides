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
    asm volatile (
        "mov_ins:\n"
        "mov rax, 0x8eb\n"
        "xor rax, rax\n"
        "jz mov_ins+3\n"
        ".byte 0x38\n"
        : :
        : "%rax"
    );
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
