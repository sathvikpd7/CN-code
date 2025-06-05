#include <stdio.h>
int w[10], p[10], n;
int max(int a, int b) 
{
    return (a > b) ? a : b;
}
int knap(int i, int m) 
{
    if (i == n) 
        return 0;
    if (w[i] > m)
        return knap(i + 1, m);
    int skip = knap(i + 1, m);
    int take = p[i] + knap(i + 1, m - w[i]);
    return max(skip, take);
}
int main()
 {
    int m;
    printf("Enter number of items and knapsack capacity: ");
    scanf("%d %d", &n, &m);
    printf("Enter profit and weight of each item:\n");
    for (int i = 0; i < n; i++)
        scanf("%d %d", &p[i], &w[i]);
    int result = knap(0, m);
    printf("Max profit = %d\n", result);
    return 0;
}
