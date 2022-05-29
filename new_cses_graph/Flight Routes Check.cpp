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
 
vector<int>v[N],vrev[N];
int vis1[N];
int vis2[N];
int in[N];
int lvl[N];
 
vector<int>order;
 
void dfs1(int n){
    vis1[n]=1;
    for(auto x:v[n]){
        if(!vis1[x]){
            dfs1(x);
        }
    }
    order.pb(n);
}
 
vector<int>scc;
 
void dfs2(int n){
    vis2[n]=1;
    for(auto x: vrev[n]){
        if(!vis2[x]){
            dfs2(x);
        }
    }
    scc.pb(n);
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
            vrev[y].pb(x);
        }
 
        for(int i=1;i<=n;i++){
            if(!vis1[i]){
                dfs1(i);
            }
        }
        reverse(sab(order));
        vector<int>ans;
        int cc=0;
        for(auto x: order){
            if(!vis2[x]){
                scc.clear();
                dfs2(x);
                cc++;
                ans.pb(scc.back());
            }
        }
        if(cc==1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
            cout<<ans[1]<<" "<<ans[0]<<endl;
        }
 
    }
 
return 0;
}
