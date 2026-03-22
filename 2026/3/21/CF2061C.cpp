//https://codeforces.com/contest/2061/problem/C
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
// const int mod = 1000000007;
const int mod = 998244353;
//随机化
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> Tp(1, 100);
// cout<<fixed<<setprecision(10);

// 0/1 dp 考虑当前的人有没有说谎 0为说谎了, 1为诚实
// 因为不能两个人连续说谎 所以如果当前是dp[i][0]那么上一个一定是dp[i-1][1]转移而来的
// 如果当前为诚实则是dp[i][1] 可以由 dp[i-1][0] 跟 dp[i-1][1] 转移而来 
// 然后 a[i]=a[i-2]+1 因为上一个人说谎了就比上上个真话的说的人数多一个
// 连着两个诚实真话的情况就是 a[i]==a[i-1] 
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    a[0]=0;
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    for(int i=1;i<=n;i++){
        if(i==1){
            if(a[i]==0){
                dp[i][0]=dp[i][1]=1;
            }else{
                dp[i][1]=0;
                dp[i][0]=1;
            }
        }else{
            dp[i][0]=dp[i-1][1];
            dp[i][0]%=mod;
            if(a[i]==a[i-2]+1)dp[i][1]=dp[i][1]+dp[i-1][0];
            dp[i][1]%=mod;
            if(a[i]==a[i-1])dp[i][1]=dp[i][1]+dp[i-1][1];
            dp[i][1]%=mod;
        }
    }   
    // for(int i=1;i<=n;i++){
    //     cout<<dp[i][0]<<" "<<dp[i][1]<<'\n';
    // }
    cout<<(dp[n][0]+dp[n][1])%mod<<'\n';
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
