// https://www.eolymp.com/en/problems/21
// problem classification: greedy algorithm
// https://habr.com/ru/articles/120343/

#include <stdio.h>
#include <stdlib.h>

#define FLOAT double

void merge(FLOAT a[], FLOAT aux[], int lo, int mid, int hi) 
{
    // copy
    for (int k = lo; k <= hi; k++)
        aux[k] = a[k];

    // merge 
    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; k++)
    {
        if (i > mid)
            a[k] = aux[j++];
        else if (j > hi)
            a[k] = aux[i++];
        else if (aux[j] < aux[i])
            a[k] = aux[j++];
        else
            a[k] = aux[i++];
    }
}

void merge_sort(FLOAT a[], FLOAT aux[], int lo, int hi)
{
    if (lo >= hi) return;
    int mid = lo + (hi - lo) / 2;
    
    // sort first half
    merge_sort(a, aux, lo, mid);
    
    // sort second half
    merge_sort(a, aux, mid + 1, hi);
    
    // merge sorted halves 
    merge(a, aux, lo, mid, hi);
}

// void insertion_sort(FLOAT a[], int n) {

// }

void print_arr(FLOAT a[], int n) 
{
    for (int i = 0; i < n; i++)
    {
        printf("a[%d]=%f\n", i, a[i]);
    }
}

// void merge_bank_accounts_(FLOAT a[], int p) {
    
// }

void merge_bank_accounts_obvious(FLOAT a[], int p, int n) {
    for (int i = 0; i < n - 1; i++)
    {
        a[i + 1] = (a[i] + a[i + 1]) * p / 100;
        printf("i=%d\n", i);
        print_arr(a, n);
        printf("\n");
    }
}

// p - percent 
void merge_bank_accounts(FLOAT a[], FLOAT aux[], int p, int lo, int hi) {
    if (hi <= lo) {
        return;
    } 
    int mid = lo + (hi - lo + 1) / 2;

    for (int i = mid; i <= hi; i++)
    {
        int indexOfPair = mid - (i - mid) - 1;
        if (mid - (i - mid) - 1 < lo)
        {
            continue;
        }
        float sum = a[i] + a[indexOfPair];
        sum = sum * p / 100;
        a[i] = sum; 
    }
#ifdef DEBUG
    printf("BEFORE SORT\n");
    print_arr(a, hi + 1);
    printf("\n");
#endif
    merge_sort(a, aux, mid, hi);
#ifdef DEBUG
    printf("AFTER SORT\n");
    print_arr(a, hi + 1);
    printf("\n");
#endif
    merge_bank_accounts(a, aux, p, mid, hi);
} 

int main() {
    int N = 0, P = 0; 
    scanf("%d %d", &N, &P);
    FLOAT a[100000];
    FLOAT aux[100000];
    for (int i = 0; i < N; i++)
    {
        int m = 0;
        scanf("%d", &m);
        a[i] = m;
    }

#ifdef DEBUG
    print_arr(a, N);
    printf("\n");
#endif
    merge_sort(a, aux, 0, N - 1);
#ifdef DEBUG
    print_arr(a, N);
    printf("\n");
#endif
    // merge_bank_accounts(a, aux, 100 - P, 0, N-1);
    merge_bank_accounts_obvious(a, 100 - P, N);
    printf("%f\n", a[N-1]);
#ifdef DEBUG
    print_arr(a, N);
    printf("\n");
#endif
    return 0;
}