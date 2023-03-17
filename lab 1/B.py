n = int(input())
a = list(map(int, input().split()))
el1 = a[0]
a[0] = a[-1]
for i in range(1, n):
    el2 = a[i]
    a[i] = el1
    el1 = el2
print(*a)