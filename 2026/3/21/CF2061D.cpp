//https://codeforces.com/contest/2061/problem/D
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

//逆向思维 set维护一下,因为删去x,y,并且|x-y|<=1 然后加入x+y,最终构成B的话
//那么考虑b[i]的分解,按奇偶讨论一下就行了
void solve(){
    int n,m;
    cin>>n>>m;
    multiset<int> a;
    multiset<int>b;
    ll sa=0,sb=0;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        sa+=x;
        a.insert(x);
    }for(int i=1;i<=m;i++){
        int x;cin>>x;
        sb+=x;
        if(a.find(x)==a.end()){
            b.insert(x);
        }else{
            a.erase(a.find(x));
        }   
    }
    if(sa!=sb)cout<<"No"<<'\n';
    else{
        while(!a.empty()&&!b.empty()){
            if(b.size()>a.size()){
                break;
            }
            int x=*b.begin();
            b.erase(b.find(x));
            if(x%2){
                int r1=x/2;
                int r2=(x+1)/2;
                if(a.find(r1)!=a.end()){
                    a.erase(a.find(r1));
                }else{
                    b.insert(r1);
                }
                if(a.find(r2)!=a.end()){
                    a.erase(a.find(r2));
                }else{
                    b.insert(r2);
                }
            }
            else{
                int r1=x/2;
                int r2=x/2;
                if(a.find(r1)!=a.end()){
                    a.erase(a.find(r1));
                }else{
                    b.insert(r1);
                }
                if(a.find(r2)!=a.end()){
                    a.erase(a.find(r2));
                }else{
                    b.insert(r2);
                }
            }
        }
        if(a.empty()&&b.empty()){
            cout<<"Yes"<<'\n';
        }else{
            cout<<"No"<<'\n';
        }
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
