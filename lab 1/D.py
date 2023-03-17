n = int(input())
a = list(map(int, input().split()))
k = 0
for i in range(1, n-1):
    if a[i-1] < a[i] and a[i+1] < a[i]:
        k += 1
print(k)