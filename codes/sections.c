int a = 1; // data
int b; // bss
char str[5]; // bss

int main(int argc, char **argv) {
    char str2[10]; // stack
    char str3[] = "abcdef"; // data or stack?
    int i = 0; // stack
    for (;i<4;i++) {
        char c = str3[i]; // stack
    }
}
