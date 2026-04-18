//https://atcoder.jp/contests/abc447/tasks/abc447_f
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



//树形dp 分类讨论 
//就当节点不作为头尾的时候 要有4个度 然后再取最大跟次大+1
//其他的感觉都没啥 正常可以想到
vector<vector<int>> e(N);
vector<int> dp(N);
int ans=0;
void dfs(int x,int f){
    int mx1=-1,mx2=-1;
    for(auto y:e[x]){
        if(f==y)continue;
        dfs(y,x);
        if(dp[y]>mx1){
            mx2=mx1;
            mx1=dp[y];
        }else{
            if(dp[y]>mx2){
                mx2=dp[y];
            }
        }
    }
    int ct=e[x].size()-1;
    if(ct>=3){
        dp[x]=max(mx1+1,dp[x]);
    }else if(ct==2)dp[x]=1;
    else dp[x]=0;
    if(ct+1>=4)ans=max(ans,mx1+mx2+1);
    else if(ct+1==3) ans=max(ans,mx1+1);
    else if(ct+1==2) ans=max(ans,1);
    else ans=max(ans,0);
}
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)e[i].clear(),dp[i]=0;
    for(int i=1;i<n;i++){
        int u,v;cin>>v>>u;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    ans=0;
    dfs(1,0);
    cout<<ans<<'\n';
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
