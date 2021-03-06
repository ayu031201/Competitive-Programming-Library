#include "bits/stdc++.h"
using namespace std;
 
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// template<class T> using oset = tree<T,null_type,less/*_equal// for indexed_multiset */<T> 
// ,rb_tree_tag,tree_order_statistics_node_update> ;    // order_of_key (k) -> # of elem strictly < k .
                                                        // *(s.find_by_order(k)) -> element at index K .
#define int              long long
#define ld               long double
#define endl             '\n'
#define dbg(x)           cout<<#x<<" is -> "<<x<<endl
#define speed_           ios_base::sync_with_stdio(false),cin.tie(0), cout.tie(0)
#define pb               push_back
#define po               pop_back
#define mp               make_pair
#define sab(x)           x.begin(),x.end()
#define ff               first
#define ss               second
#define sz(x)            (int)x.size()
#define sp(x)            fixed<<setprecision(x)
#define uni(edge)        edge.erase(unique(edge.begin(),edge.end()),edge.end());
#define to_up(x)         transform(sab(x),x.begin(),::toupper)
#define to_low(x)        transform(x.begin(),x.end(),x.begin(),::tolower)
 
const int M = 1000000007;
const int MM = 998244353;
const ld Pi= acos(-1);
const int N=1e5+6;
const int inf=1e18;
 
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction
 
/*
 
int string_to_int(string s){
    stringstream geek(s);
 
    // The object has the value 12345 and stream
    // it to the integer x
    int x = 0;
    geek >> x;
    return x;
}
 
////--------------------------------- GRAPHS -------------------------------------------------------------///
 
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
vector<int>comp(N);
void dfs2(int n,int c){
    vis2[n]=1;
    scc.pb(n);
    comp[n]=c;
    for(auto x: vrev[n]){
        if(!vis2[x]){
            dfs2(x,c);
        }
    }
}
 
void dijkstra(int n){
    dis[n]=0;
    par[n]=-1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push(mp(0,n));
    // path[n]=1;
    while(!pq.empty()){
        auto curr=pq.top();
        pq.pop();
        if(dis[curr.ss]!=curr.ff){
            continue;
        }
        for(auto x:v[curr.ss]){
            if(dis[x.ss]>x.ff+dis[curr.ss]){
                dis[x.ss]=x.ff+dis[curr.ss];
                pq.push(mp(dis[x.ss],x.ss));
                par[x.ss]=curr.ss;
                // path[x.ss]=path[x.ff];
            }
            // else if(dis[x.ss]==x.ff+dis[curr.ss]){
            //     path[x.ss]+=path[x.ff];  // addition when dis are equal to find number of possible paths.
            // }
        }
    }
}
 
void bfs_0_1(int n){
    dis[n]=0;
    deque<int>q;
    q.push(n);
    while(!q.empty()){
        int curr=q.front();
        q.pop_front();
        for(auto x:v[curr]){
            if(dis[x.ss]>dis[curr]+x.ff){
                dis[x.ss]=dis[curr]+x.ff;
                if(x.ff==1){
                    q.push_back(n);
                }
                else{
                    q.push_front(n);    
                }
            }
        }
    }
}
 
vector<int>rnk(N,1);
vector<int>par(N,-1);
 
int find(int a){
    if(par[a]<0){
        return a;
    }
    return par[a]=find(par[a]);
}
void un(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b){
        return ;
    }
    else if(rnk[a]>=rnk[b]){
        par[b]=a;
        rnk[a]+=rnk[b];
    }
    else{
        par[a]=b;
        rnk[b]+=rnk[a];
    }
}
 
vector<int>in(N,0);
void find_euler(int n){  // CIRCUIT -> (IN = OUT) OF ALL EDGES AND GRAPH MUST BE A SCC.
    stack<int>st;        // PATH -> ONLY ONE EDGE (IN-OUT)==1 AND ONE (OUT-IN)==1,REST (OUT==IN).
    st.push(n);
    while(!st.empty()){
        int y=st.top();
        vis[y]=1;
        if(sz(v[y])==0){
            st.pop();
            cout<<y<<" "; // the actual eulerian path
        }
        else{
            int curr=v[y].front();
            st.push(curr);
            v[y].erase(find(sab(v[y]),curr));
            // v[curr].erase(find(sab(v[curr]),y));  // erase the other way only if it's not-directed.
        }
    }
}
 
int up[N][31];
int depth[N];
bool vis[N];
 
int jump(int a, int d) {
    for(int i=0; i<30; i++) if(d & (1<<i))
        a = up[a][i];
    return a;
}
 
int get_lca(int x, int y){
    if(depth[x]<depth[y]){
            swap(x,y);
        }
        int k=depth[x]-depth[y];
        for(int j=29;j>=0;j--){ //maxx = ceil(log2(N));
            if(((1ll<<j)&k)){
                x=up[x][j]; // same in K'th ancestor.
            }
        }
        if(x==y){
            return x;
        }
        for(int j=29;j>=0;j--){
            if(up[y][j]!=up[x][j]){
                y=up[y][j];
                x=up[x][j];
            }
        }
        return up[x][0];     
}
 
////-------------------------------------------- GRAPHS --------------------------------------------------///
 
 
 
int ncr(int n, int r){
    if (r < 0 || n < r) return 0;
    
    return (((fac[n]%M)*(fac_inv[r]%M))%M*(fac_inv[n-r]%M))%M;
}
 
int inv[N],fac_inv[N],fac[N];
void initialize()
{
    int i;
    inv[1]=1;
    for(i=2;i<=N-2;i++)
        inv[i]=(M-M/i)*inv[M%i]%M; 
    fac[0]=fac[1]=1;
    for(i=2;i<=N-2;i++)
        fac[i]=i*fac[i-1]%M;
    fac_inv[0]=fac_inv[1]=1;
    for(i=2;i<=N-2;i++)
        fac_inv[i]=inv[i]*fac_inv[i-1]%M;
 
}
 
int msb(int n){ // change 63 to 31 if 32 bit integer is used and use __builtin_clz(n)
    return 63 - __builtin_clzll(n);
}
 
string a_z="abcdefghijklmnopqrstuvwxyz";
 
////--------------------------------------- BITSET IMPORTANT --------------------------------------------////
 
    bitset<N>ans(0);
    for(int k=ans._Find_first();k<sz(ans);k=ans._Find_next(k)){ // only iterates on the set bits of a bitset.
        // cout<<k+1<<" ";
    }
      # sets representation 
    // F(x,y) = (A U B) - (A intersec B) = (A ^ B); 
    // (A ^ B) = (A + B) - 2*(A & B);
    // (A + B) = (A | B) + (A & B);
    
////-----------------------------------------------------------------------------------------------------////
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    };
*/
 
void simp(){
    
    // dp?, graph?, bs on answer?, compress/sort queries/array?, stupid observation?
    
    int n;
    cin>>n;
    vector<int>dp(n+10,0);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6 && (i-j)>=0;j++){
            dp[i]=(dp[i]+dp[i-j])%M;
        }
    }
    for(int i=1;i<=n;i++){
     //   cout<<dp[i]<<" ";
    }
    cout<<dp[n]<<endl;
    
    
}
signed main(){
 
    
    
    speed_;
    
    int t;
    t=1;
    //cin>>t;
    
    //initialize();
    
    //gen_factorial(N+10);
    
    int curr=1;
    while(t--){  
        
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif  
        //cout<<"Case #"<<curr++<<": "; 
        simp();
        
    }
return 0;
}