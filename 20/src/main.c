#include <stdio.h>

// https://www.eolymp.com/en/problems/20

int main() {
    int n = 0;
    scanf("%d", &n);
    int cn = n;
    int operationCount = 0;
    while (n > 0) {
        n -= cn % 10;
        cn /= 10;
        if (cn == 0) {
            cn = n;
            operationCount++;
        }
    }
    printf("%d\n", operationCount);
    return 0;
}