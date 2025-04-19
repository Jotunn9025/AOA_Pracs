values = [10, 40, 30, 50, 35]
weights = [1, 3, 4, 5, 6]
maxweight = 15

def knapsack01(values, weights, maxweight):
    n = len(values)
    table = [[0 for w in range(maxweight + 1)] for i in range(n + 1)]

    for i in range(1, n + 1):  
        for w in range(1, maxweight + 1):  
            if weights[i - 1] <= w:#once we reach the point where its viable to add in our new item
                include = values[i - 1] + table[i - 1][w - weights[i - 1]]#values if add item=valbe4 adding item in prev row
                exclude = table[i - 1][w]#not adding item
                table[i][w] = max(include, exclude)#get max val
            else:
                table[i][w] = table[i - 1][w]#if cant add new item just get prev val

    for row in table:
        print(row)

    return table[n][maxweight]

max_profit = knapsack01(values, weights, maxweight)
print(f"Maximum profit: {max_profit}")
