#include <stdio.h>

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int len = sizeof(arr)/sizeof(int);
    for (int i=0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    puts("");
    // another way of looping, using pointer maths
    // Note: to the c comiler arrays aren't quite pointers
    // The main difference is that the an address stored in an array variable can't be changed
    for (int *a = arr; a < arr+len; a++) {
        printf("%d ", *a);
    }
    puts("");
}
