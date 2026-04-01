//https://codeforces.com/contest/1418/problem/C
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
using PIII=pair<int,pair<int,int>>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
const int N=2e5+10;
const int M=2e6+10;
const int mod = 1000000007;
// const int mod = 998244353;
//随机化
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> Tp(1, 100);
// cout<<fixed<<setprecision(10);

//简单dp一下,先后手转移最后取min
void solve(){
    int n;cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)cin>>a[i];
    vector<vector<int>>dp(n+1,vector<int>(2,1e9));
    dp[1][0]=(a[1]==1);
    if(n>=2)dp[2][0]=(a[1]==1)+(a[2]==1);
    for(int i=2;i<=n;i++){
        for(int j=0;j<=1;j++){
            if(j==0){
                int p=(a[i]==1);
                int r=(a[i]==1)+(a[i-1]==1);
                dp[i][j]=min(dp[i-1][j^1]+p,dp[i][j]);
                dp[i][j]=min(dp[i-2][j^1]+r,dp[i][j]);
            }else{
                dp[i][j]=min(dp[i-1][j^1],dp[i][j]);
                dp[i][j]=min(dp[i-2][j^1],dp[i][j]);
            }
        }
    }
    cout<<min(dp[n][0],dp[n][1])<<'\n';
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
