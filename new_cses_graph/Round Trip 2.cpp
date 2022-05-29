#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
 
#define int              long long
#define endl             '\n'
#define dbg(x)           cout<<#x<<" is -> "<<x<<endl
#define speed_           ios_base::sync_with_stdio(false),cin.tie(0), cout.tie(0)
#define pb               push_back
#define pf               push_front
#define po               pop_back
#define mp               make_pair
#define sab(x)           x.begin(),x.end()
#define ff               first
#define ss               second
#define sz(x)            (int)x.size()
 
const int M = 1000000007;
const int MM = 998244353;
const long double Pi= acos(-1);
const int N=1e6+5;
 
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {   // finding a power b mod m.
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
 
vector<int>v[N];
int vis[N];
int par[N];
int dis[N];
vector<int>ans;
int start;
int en;
bool is_cycle=0;
 
void dfs(int n,int p){
    vis[n]=1;
    par[n]=p;
 
    for(auto x:v[n]){
        if(!vis[x]){
            dfs(x,n);
        }
        else if(vis[x]==1){
            start=x;
            en=n;
            is_cycle=1;
        }
    }
    vis[n]=2;
}
 
 
signed main(){
    
speed_;
 
    int t;
    t=1;
    //cin>>t;
    while(t--){
   
#ifndef ONLINE_JUDGE
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
#endif
 
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,-1);
        }
    }
    if(!is_cycle){
        cout<<"IMPOSSIBLE";
    }
    else{
        vector<int>ans;
        for(int i=en;i!=start;i=par[i]){
            ans.pb(i);
        }
        cout<<sz(ans)+2<<endl;
        ans.pb(start);
        ans.pb(en);
        while(sz(ans)){
            cout<<ans.back()<<" ";
            ans.po();
        }
    }
 
 
    }
return 0;
}
