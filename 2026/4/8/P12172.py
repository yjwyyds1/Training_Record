# https://www.luogu.com.cn/problem/P12172
# a,b,c=eval(input())
a,b,c=map(int,input().split())
for i in range(0,b):
    t=''
    for j in range(0,a):
        t=t+'Q'
    print(t)
for i in range(0,a):
    t=''
    for j in range(0,a+c):
        t=t+'Q'
    print(t)
