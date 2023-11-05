#include <stdio.h>

// https://www.eolymp.com/en/problems/22
// https://www.rookieslab.com/posts/fastest-way-to-check-if-a-number-is-prime-or-not#c-implementation---osqrtn

int reverse_num(int n) {
    int result = 0;
    
    while (n > 0) {
        result *= 10;
        result += n % 10;
        n /= 10;
    }
    return result;
}

int is_prime(int n) {
    if (n == 1)
        return 0;
    
    int i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            return 0;
        }
        i++;
    }
    return 1;
}

int main() {
    int a;
    int b;
    scanf("%d %d", &a, &b);

    int count = 0;
    for (int i = a; i <= b; i++)
    {
        if (is_prime(i)) {
            int ri = reverse_num(i);
            if (is_prime(ri)) {
                count++;
            }
        }
    }
    printf("%d\n", count);
    
    return 0;
}