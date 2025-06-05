#include <stdio.h>
#define MAX 10
int set[MAX], include[MAX], target;
void findSubset(int sum, int i, int rem)
 {
    include[i] = 1;
    if (sum + set[i] == target) {
        for (int j = 1; j <= i; j++)
            if (include[j]) printf("%d ", set[j]);
        printf("\n");
    } 
    else if (sum + set[i] + set[i + 1] <= target)
        findSubset(sum + set[i], i + 1, rem - set[i]);
    include[i] = 0;
    if ((sum + rem - set[i]) >= target && (sum + set[i + 1]) <= target)
        findSubset(sum, i + 1, rem - set[i]);
}
int main()
 {
    int n, total = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d numbers (in increasing order): ", n);
    for (int i = 1; i <= n; i++) 
    { 
        scanf("%d", &set[i]);
         total += set[i]; 
        }
    printf("Enter target sum: ");
    scanf("%d", &target);
    if (total < target || set[1] > target)
     printf("No subset possible\n");
    else findSubset(0, 1, total);
    return 0;
}
