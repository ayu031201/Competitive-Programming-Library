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
const int N=1e3+5;
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
 
int vis[N][N];
int n,m;
char arr[N][N];
bool isvalid(int i,int j){
    if(i<0 || i>=n || j<0 ||j>=m){
        return false; 
    }
    if(vis[i][j]==1 || arr[i][j]=='#'){
        return false;
    }
 
        return true;
    
}
int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};
void dfs(int n,int m){
    vis[n][m]=1;
    for(int i=0;i<4;i++){
        if(isvalid(n+dx[i],m+dy[i])){
            dfs(n+dx[i],m+dy[i]);
        }
    }
 
 
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
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='.' && vis[i][j]==0){
                dfs(i,j);
                ans++;
            }
        }
    }
    cout<<ans<<endl;
 
 
    }
 
return 0;
}
