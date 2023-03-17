n = int(input())
a = list(map(int, input().split()))
x = int(input())
diff = float("inf")

for i in range(n):
    if abs(x - a[i]) < diff:
        k = a[i]
        diff = abs(x - a[i])
print(k)