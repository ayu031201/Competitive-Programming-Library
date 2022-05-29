#include <bits/stdc++.h>
using namespace std;
 
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
 
int n,m;
int vis[N];
vector<int>v[N];
int col[N];
 
int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};
 
bool dfs(int n,int c){
    vis[n]=1;
    col[n]=c;
    for(auto x:v[n]){
        if(!vis[x]){
            bool ans=dfs(x,c^1);
            if(ans==false){
                return false;
            }
        }
        else if(col[x]==col[n]){
            return false;
        }
    }
    return true;
}
 
signed main(){
    
speed_;
 
int t;
t=1;
//cin>>t;
while(t--){
   /* 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    */
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    bool flag;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            flag=dfs(i,0);
        }
    }
    if(flag==false){
        cout<<"IMPOSSIBLE";
    }
    else{
        for(int i=1;i<=n;i++){
            if(col[i]==0){
                cout<<1<<" ";
            }
            else{
                cout<<2<<" ";
            }
        }
 
    }
 
 
    }
 
return 0;
}
