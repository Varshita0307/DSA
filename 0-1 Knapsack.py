#0-1 Knapsack

weights = [5,20,40]
values = [50,80,100]
cap = 50

def loadTrolley(values,weights,capacity):
    n = len(weights)
    F = [[0 for i in range (cap+1)] for i in range (n+1)]
    for i in range(n+1):
        for j in range(cap+1):
            if i==0 or j==0:
                F[i][j] = 0
            elif weights[i-1]>j:
                F[i][j] = F[i-1][j]
            else:
                F[i][j] = max(values[i-1]+F[i-1][j-weights[i-1]],F[i-1][j])
    
    return F[n][cap]

print(loadTrolley(values,weights,cap))