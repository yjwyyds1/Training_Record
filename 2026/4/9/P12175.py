#https://www.luogu.com.cn/problem/P12175
n=eval(input())
a=list(map(int,input().split()))
ans=1
for len in range(1,n):
    if ans>(n//len):
        break
    dp=[1 for i in range(n+1)]
    for i in range(0,n):
        if i-len>=0 and a[i]>a[i-len]:
            dp[i]=max(dp[i-len]+1,dp[i])
        ans=max(dp[i],ans)
print(ans)
