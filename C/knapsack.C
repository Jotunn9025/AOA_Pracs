#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void knapsack(int n, int W, int value[], int weight[])
{
    int dp[20][20];

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (w == 0)
                dp[i][w] = 0;
            else if (weight[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w], value[i - 1] + dp[i - 1][w - weight[i - 1]]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    printf("Maximum value in Knapsack = %d\n", dp[n][W]);

    printf("Selected items: ");
    int w = W;
    for (int i = n; i > 0 && dp[i][w] != 0; i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            printf("%d ", i);
            w -= weight[i - 1];
        }
    }
    printf("\n");
}

int main()
{
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter maximum weight of knapsack: ");
    scanf("%d", &W);

    int value[20], weight[20];

    printf("Enter values and weights of items:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Item %d - Value Weight: ", i + 1);
        scanf("%d %d", &value[i], &weight[i]);
    }

    knapsack(n, W, value, weight);

    return 0;
}
