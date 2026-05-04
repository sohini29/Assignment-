#include <stdio.h>
#include <string.h>

int main() {
    char str[100005];
    printf("Enter a string:");
    scanf("%s", str);

    int n = strlen(str);
    
    char t[200005];
    strcpy(t, str);
    strcat(t, str);

    int freq[26] = {0};
    int left = 0;
    int sum = 0, maxSum = 0;

    for (int right = 0; right < 2 * n; right++) {

        int current = t[right] - 'a';   
        while (freq[current] > 0) {
            int l = t[left] - 'a';
            sum -= (l + 1);
            freq[l]--;
            left++;
        }

        freq[current]++;
        sum += (current + 1);
        if (right - left + 1 > n) {
            int l = t[left] - 'a';
            sum -= (l + 1);
            freq[l]--;
            left++;
        }
        if (sum > maxSum)
            maxSum = sum;
    }

    printf("The maximum possible sum is : %d\n", maxSum);
    return 0;
}
