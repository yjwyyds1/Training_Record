//https://codeforces.com/contest/1181/problem/D
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
using PIII=pair<int,pair<int,int>>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
const int N=5e5+10;
const int M=2e6+10;
// const int mod = 1000000007;
const int mod = 998244353;
//随机化
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> Tp(1, 100);
// cout<<fixed<<setprecision(10);


// 主席树+二分+前缀和  给我写吐了wc
// 这个没有修改就是区间第k大 思路很好想代码不好写感觉 还是太菜了
struct Tree{
    int l,r;
    int sum;
}tr[N*80];
int root[N];
int t=0;
int build(int l,int r){
    int p=t++;
    tr[p].sum=0;
    if(l==r)return p;
    int mid=(l+r)>>1;
    tr[p].l=build(l,mid);
    tr[p].r=build(mid+1,r);
    return p;
}
int add(int pre,int l,int r,int v){
    int p=t++;
    tr[p]=tr[pre];
    tr[p].sum++;
    if(l==r) return p;
    int mid=(l+r)>>1;
    if(v<=mid){
        tr[p].l=add(tr[pre].l,l,mid,v);
    }else{
        tr[p].r=add(tr[pre].r,mid+1,r,v);
    }
    return p;
} 

int query(int x,int y,int l,int r,int k){
    if(l==r) return l;
    int mid=(l+r)>>1;
    int c=tr[tr[y].l].sum-tr[tr[x].l].sum;
    if(k<=c){
        return query(tr[x].l,tr[y].l,l,mid,k);
    }else{
        return query(tr[x].r,tr[y].r,mid+1,r,k-c);
    }
}
ll n,m;


ll g(int h,vector<pair<ll,int>> &s){
    int L=1,R=m;
    ll res=0;
    while(L<=R){
        int mid=(L+R)>>1;
        if(s[mid].first<=h){
            res=mid;
            L=mid+1;
        }else{
            R=mid-1;
        }
    }
    return res;
}

int cnt[N];
void solve(){
    int q;
    cin>>n>>m>>q;
    int f[n+1];
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        f[i]=x;
        cnt[x]++;
    }
    vector<pair<ll,int>> s;
    s.push_back({0,0});
    for(int i=1;i<=m;i++){
        s.push_back({cnt[i],i});
    }
    sort(s.begin()+1,s.end());
    root[0]=build(1,m);

    for(int i=1;i<s.size();i++){
        root[i]=add(root[i-1],1,m,s[i].second);
    }

    ll V=s[s.size()-1].first*m;
    ll H=s[s.size()-1].first;
    vector<ll> p(H+1,0),c(H+1,0);
    for(int i=0;i<=H;i++){
        c[i]=+g(i,s);
        if(i)p[i]=p[i-1]+c[i];
        else p[i]=c[i];
    }

    // for(int i=1;i<=m;i++){
    //     for(int j=1;j<=i;j++){
    //         for(int k=1;k<=i-j+1;k++){
    //             cout<<i<<" "<<j<<" "<<k<<" "<<query(root[j-1],root[i],1,m,k)<<'\n';
    //         }
    //     }
    // }


    // for(int i=0;i<s.size();i++){
    //     cout<<s[i].first<<" ";
    // }
    // cout<<'\n';
    // for(int i=0;i<s.size();i++){
    //     cout<<s[i].second<<" ";
    // }
    
    // for(int i=0;i<=H;i++){
    //     cout<<c[i]<<' ';
    // }
    // cout<<'\n';
    // for(int i=0;i<=H;i++){
    //     cout<<p[i]<<' ';
    // }
    // cout<<'\n';
    // cout<<V-n<<'\n';
    
    for(int i=1;i<=q;i++){
        ll x;cin>>x;
        if(x<=n)cout<<f[x]<<'\n';    
        else{
            x-=n;
            if(x>p[H]){
                if((x-p[H])%m==0){
                    cout<<m<<'\n';
                }else{
                    cout<<(x-p[H])%m<<'\n';
                }
                // cout<<(((x-(V-n))%m==0)?m:(x-(V-n))%m)<<'\n';
            }else{
                ll L=0,R=H,res=0;
                while(L<=R){
                    ll mid=(L+R)>>1;
                    if(x<=p[mid]){
                        res=mid;
                        R=mid-1;
                    }else{
                        L=mid+1;
                    }
                }
                // cout<<"X:"<<" "<<x<<'\n';
                // cout<<res<<" "<<p[res]<<" "<<p[res]-x<<'\n';
                if(res){
                    cout<<query(root[0],root[c[res]],1,m,x-p[res-1])<<'\n';
                }else{
                    cout<<query(root[0],root[c[res]],1,m,x)<<'\n';
                }
                





                // ll L=0,R=H,res=-1,d=-1;
                // while(L<=R){
                //     int mid=L+R>>1;
                //     auto [OK,c]=ck(x,mid,s,p);
                //     if(OK){
                //         res=mid;
                //         d=c;
                //         L=mid+1;
                //     }else{
                //         R=mid-1;
                //     }
                // }
                // int K=((x-((res*d)-p[d]))%d==0)?d:(x-((res*d)-p[d]))%d;
                // // cout<<x<<" "<<res<<" "<<d<<" "<<K<<'\n';
                // cout<<query(root[0],root[d],1,m,K)<<'\n';//[1,d]
                // // cout<<"___________"<<'\n';
            }
        }

        
        // if(x<=n)cout<<f[x]<<'\n';
        // else{
        //     if(x>V-n){
        //         cout<<(((x-(V-n))%m)==0?m:(x-(V-n))%m==0)<<'\n';
        //     }else{

        //         ll a,b;
        //         ll L=0,R=H,res=0;
        //         while(L<=R){
        //             ll mid=L+R>>1;
        //             ll l=0,r=m-1;
        //             ll res=0;
        //             while(l<=r){
        //                 ll Mid=l+r>>1;
        //                 if(s[Mid].first<=mid){
        //                     l=Mid+1;
        //                     res=Mid;
        //                 }else{
        //                     r=Mid-1;
        //                 }
        //             }
        //             if(mid*(res+1)-p[res]<=x){
        //                 a=mid;
        //                 b=res;
        //                 l=mid+1;
        //             }else{
        //                 r=mid-1;
        //             }
        //         }
        //         cout<<s[(x-(a*(b+1)-p[b])+b)%(b+1)].second<<'\n';
        //     }
        // }
        
    }
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
// 0 0 0 0 0 0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0 1 1  1  1  1 2 
// 1 2 5 6 7 8 10 11 12 13 15 16 17 18 19 21 22 23 24 25 27 28 29 30 3 9 14 20 26 4


/*
1 0
2 0
5 0
6 0
7 0
8 0
10 0
11 0
12 0
13 0
15 0
16 0
17 0
18 0
19 0
21 0
22 0
23 0
24 0
25 0
27 0
28 0
29 0
30 0
3 1
9 1
14 1
20 1
26 1
4 2

*/









