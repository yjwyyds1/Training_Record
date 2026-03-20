//https://codeforces.com/contest/2152/problem/D
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
// 没想到结论啊
// 其实想到了左边有连续的1就会多一个,然后也想到了5的特殊情况也是多一个,还是太菜了
// 如果是2的幂次就不会有多余的贡献每次+1之后就没删了 ,
// 但是如果是2^{k}+1,最低位有1就可以进位,然后就可以一直让这个进的1留着,知道之后是3的时候进位让贡献+1
// 再就是中间有1 也是类似的
// 其他的前缀和的思路查询也很常见....
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> s(n+1,0),c(n+1,0),v(n+1,0);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        s[i]+=(int)log2(x);
        if(x!=(x&-x)){
            x--;
            if(x==(x&-x)){
                c[i]++;
            }else{
                v[i]++;
            }
        }
        // cout<<s[i]<<" "<<c[i]<<" "<<v[i]<<'\n';
        s[i]+=s[i-1];
        v[i]+=v[i-1];
        c[i]+=c[i-1];
    }
    for(int i=1;i<=q;i++){
        int l,r;
        cin>>l>>r;
        cout<<s[r]-s[l-1]+(c[r]-c[l-1])/2+(v[r]-v[l-1])<<'\n';
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
