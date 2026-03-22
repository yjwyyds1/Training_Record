//https://atcoder.jp/contests/abc450/tasks/abc450_d
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

// 因为+n*k,所以对k同余定理 分类考虑搞一下就行了
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1);
    set<int> s; 
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        x%=k;
        a[i]=x;
        s.insert(x);
    }
    sort(a.begin()+1,a.end());
    deque<int> r;
    for(int i=1;i<=n;i++){
        r.push_back(a[i]);
    }
    // 1 3 9
    // 9 1 3
    // 3 9 1
    // 1 3 9
    int cnt=1;
    int ans=2e9;
    while(cnt<=n){
        int Mx=r.back();
        int Mi=r.front();
        if(Mx>Mi)ans=min(ans,Mx-Mi);
        else ans=min(ans,Mx+k-Mi);
        cnt++;
        r.pop_back();
        r.push_front(Mx);
    }
    if(s.size()==1)ans=0;
    cout<<ans<<'\n';
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

// 00 c1
// 11
// 01 c2
// 10 c3
