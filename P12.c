#include <stdio.h>
#define M 10
int s[M], c[M], t, n;
void f(int sum, int i)
 {
    if (sum == t) 
    {
        for (int j = 1; j < i; j++)
            if (c[j]) printf("%d ", s[j]);
        printf("\n");
        return;
    }
    if (i > n || sum > t) 
     return;
    c[i] = 1;
    f(sum + s[i], i + 1);
    c[i] = 0;
    f(sum, i + 1);
}
int main() 
{
    int total = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d numbers (in increasing order): ", n);
    for (int i = 1; i <= n; i++) 
    {
        scanf("%d", &s[i]);
        total += s[i];
    }
    printf("Enter target sum: ");
    scanf("%d", &t);
    if (total < t)
     {
        printf("No subset possible\n");
    } 
    else 
    {
        f(0, 1);
    }
    return 0;
}
