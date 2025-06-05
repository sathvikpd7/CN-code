#include <stdio.h>
int knapsack(int W, int wt[], int val[], int n) 
{
    int dp[n+1][W+1];
    for (int i = 0; i <= n; i++) 
    {
        for (int w = 0; w <= W; w++) 
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i-1] <= w)
                dp[i][w] = (val[i-1] + dp[i-1][w - wt[i-1]] > dp[i-1][w]) ? val[i-1] + dp[i-1][w - wt[i-1]] : dp[i-1][w];
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    return dp[n][W];
}
int main()
 {
    int n, W;
    printf("Enter items and capacity: ");
    scanf("%d %d", &n, &W);
    int wt[n], val[n];
    printf("Enter weights: ");
    for (int i = 0; i < n; i++)
    scanf("%d", &wt[i]);
    printf("Enter values: ");
    for (int i = 0; i < n; i++) 
    scanf("%d", &val[i]);
    printf("Max value = %d\n", knapsack(W, wt, val, n));
    return 0;
}
