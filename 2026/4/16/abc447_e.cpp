//https://atcoder.jp/contests/abc447/tasks/abc447_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
using PIII=pair<int,pair<int,int>>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
const int N=1e5+10;
const int M=2e6+10;
// const int mod = 1000000007;
const int mod = 998244353;
//随机化
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> Tp(1, 100);
// cout<<fixed<<setprecision(10);

ll qmi(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
        res%=mod;
    }
    return res%mod;
}
struct dsu{
    int n;
    vector<int>  f;
    void init(int _){
        n=_;
        f.resize(n+1);
        for(int i=1;i<=n;i++)f[i]=i;
    }
    int find(int x){
        if(f[x]==x)return f[x];
        else{
            f[x]=find(f[x]);
            return f[x];
        }
    }
    void merge(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return ;
        f[x]=y;
        return ;
    }
    bool same(int x,int y){
        return find(x)==find(y);
    }
};
void solve(){
    int n,m;cin>>n>>m;
    dsu d;d.init(n);
    int u[m+1],v[m+1];
    ll ans=0;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i];
        ans=ans+qmi(2,i);
        ans%=mod;
    }
    ll sum=0;
    int k=n;
    for(int i=m;i>=1;i--){
        if(d.same(u[i],v[i])){
            sum+=qmi(2,i);
            sum%=mod;
        }else{
            if(k>2){
                k--;
                sum+=qmi(2,i);
                sum%=mod;
                d.merge(u[i],v[i]);
            }
        }
    }
    cout<<(ans-sum+mod)%mod<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
