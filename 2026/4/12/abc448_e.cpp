//https://atcoder.jp/contests/abc448/tasks/abc448_e
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
// const int mod = 998244353;
//随机化
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> Tp(1, 100);
// cout<<fixed<<setprecision(10);
int c[N],l[N];
ll qmi(ll a,ll b,ll mod){
    ll res=1;
    while(b){
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
        res%=mod;
    }
    return res;
}
int k,m;
ll f(int mod){
    ll w=0,sum=0;
    for(int i=k;i>=1;i--){
        ll rt=qmi(10,w,mod)*c[i];
        ll p=((qmi(10,l[i],(mod*9))-1+(mod*9))%(mod*9))/9;
        // cout<<i<<" "<<c[i]<<" "<<l[i]<<" "<<(rt*p)%mod<<" "<<mod<<'\n';
        sum=(sum+(rt*p)%mod)%mod;
        w+=l[i];
    }
    return sum;
}
void solve(){
    cin>>k>>m;
    for(int i=1;i<=k;i++){
        cin>>c[i]>>l[i];
    }
    int Mod=10007;
    cout<<((f(Mod)-f(m)+Mod)%Mod*(qmi(m,Mod-2,Mod))%Mod)%Mod<<'\n';

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
