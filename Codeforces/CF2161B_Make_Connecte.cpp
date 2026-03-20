//https://codeforces.com/contest/2161/problem/B
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

// 要么是只有一个2*2,要么就是都在两个相邻的对角45度线上
void solve(){
    int n;
    cin>>n;
    int t=1e9,d=0,l=1e9,r=0;
    int lxmi=1e9,lxmx=-1e9,rxmi=1e9,rxmx=-1e9;
    vector<vector<char>> a(n+1,vector<char>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]=='#'){
                lxmi=min(lxmi,i-j);
                lxmx=max(lxmx,i-j);
                rxmi=min(rxmi,i+j);
                rxmx=max(rxmx,i+j);
                t=min(i,t);
                d=max(i,d);
                l=min(l,j);
                r=max(j,r);
            }
        }
    }
    if((d-t<=1&&r-l<=1)||lxmx-lxmi<=1||rxmx-rxmi<=1){
        cout<<"YES"<<'\n';
    }else{
        cout<<"NO"<<'\n';
    }
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
