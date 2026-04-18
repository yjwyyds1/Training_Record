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


//分类讨论一下 对应的列1的总和不超过2 
//然后用那个并查集 分成两种情况有约束的建边 判断会不会冲突
// 11 00 同时操作或者都不同操作 
// 10 01 只操作其中一个
struct dsu{
    int n;
    vector<int> f;
    void init(int _){
        n=_;
        f.resize(n+10);
        for(int i=1;i<=n;i++)f[i]=i;
    }
    int find(int x){
        if(x==f[x])return x;
        else {
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
ll qmi(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1){
            res=res*a%mod;
        }
        a=a*a%mod;
        b>>=1;
        res%=mod;
    }
    return res%mod;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> a(n+1,vector<char>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    dsu d;d.init(2*n);
    for(int j=1;j<=(m+1)/2;j++){
        if(m%2&&j==(m+1)/2){
            int c=0;
            for(int i=1;i<=n;i++){
                if(a[i][j]=='1')c++;
            }
            if(c>=2){
                cout<<0<<'\n';
                return ;
            }
        }else{
            int c1=0,c2=0;
            vector<int> p;
            for(int i=1;i<=n;i++){
               if(a[i][j]=='1')c1++,p.push_back(i);
            }
            for(int i=1;i<=n;i++){
               if(a[i][m-j+1]=='1')c2++,p.push_back(i);
            }
            if(c1+c2>2){
                cout<<0<<'\n';
                return ;
            }
            else{
                if(c1+c2==2){
                    if(c1==2||c2==2){//11 00
                        d.merge(p[0],p[1]+n);
                        d.merge(p[0]+n,p[1]);
                    }else{//10 01
                        d.merge(p[0],p[1]);
                        d.merge(p[0]+n,p[1]+n);
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(d.same(i,i+n)){
            cout<<0<<'\n';
            return ;
        }
    }
    for(int i=1;i<=n;i++){
        if(d.find(i)==i)ans++;
    }
    cout<<qmi(2,ans)<<'\n';
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
