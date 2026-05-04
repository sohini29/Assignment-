#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return ((long long)a - (long long)b);
}

int main() {
    int n,i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    long long A[100005];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%lld", &A[i]);
    }

    long long K;
    printf("Enter value of K: ");
    scanf("%lld", &K);

    long long rem = A[0] % K;

    for ( i = 1; i < n; i++) {
        if (A[i] % K != rem) {
            printf("Output: -1\n");
            return 0;
        }
    }
   long long B[100005];
    for ( i = 0; i < n; i++) {
        B[i] = (A[i] - rem) / K;
    }

    qsort(B, n, sizeof(long long), compare);

    long long median = B[n / 2];
    long long operations = 0;
    for ( i = 0; i < n; i++) {
        if (B[i] > median)
            operations += B[i] - median;
        else
            operations += median - B[i];
    }

    printf("Minimum operations: %lld\n", operations);

    return 0;
}
