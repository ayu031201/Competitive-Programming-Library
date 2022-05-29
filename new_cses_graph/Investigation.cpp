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
 
const int M = 1e9+7;
const int MM = 998244353;
const long double Pi= acos(-1);
const int N=2e5+5;
const int inf=1e18;
 
vector<vector<pair<int,int>>>v(N),vrev(N);
 
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction
 
/*
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
 
vector<int>rnk;
vector<int>par;
int find(int a){
    if(par[a]<0){
        return a;
    }
    return par[a]=find(par[a]);
}
void un(int a,int b){
    a=find(a);
    b=find(b);
    if(rnk[a]>=rnk[b]){
        par[b]=a;
        rnk[a]+=rnk[b];
    }
    else if(rnk[b]>rnk[a]){
        par[a]=b;
        rnk[b]+=rnk[a];
    }
}
 
stack<int>st;
vector<int>in(N,0),out(N,0);
void find_euler_path(int n){
    st.push(n);
    while(!st.empty()){
        int y=st.top();
        vis[y]=1;
        if(sz(v[y])==0){
            st.pop();
            ans.pb(y);
        }
        else{
            int curr=v[y].front();
            st.push(curr);
            v[y].erase(find(sab(v[y]),curr));
            v[curr].erase(find(sab(v[curr]),y));             // in undirected graph;
        }
    }
}
 
*/
vector<int>dis(N,inf);
vector<int>path(N,0);
vector<int>zz(N,0);
vector<int>low(N,inf);
void dijkstra_1(int n,int f){
    dis[n]=0;
    path[n]=1;
    zz[n]=1;
    low[n]=1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push(mp(0,n));
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
                path[x.ss]=path[curr.ss];
                path[x.ss]%=M;
                zz[x.ss]=zz[curr.ss]+1;
                low[x.ss]=low[curr.ss]+1;
            }
            else if(dis[x.ss]==x.ff+dis[curr.ss]){
                path[x.ss]+=(path[curr.ss]%M);
                path[x.ss]%=M;
                zz[x.ss]=max(zz[curr.ss]+1,zz[x.ss]);
                low[x.ss]=min(low[x.ss],low[curr.ss]+1);
            }
        }
    }
}
 
 
signed main(){
 
    
    speed_; 
    
    int t;
    t=1;
    //cin>>t;
    for(int z=1;z<=t;z++){
       // cout<<"Case #"<<z<<": ";
        
#ifndef ONLINE_JUDGE
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
#endif  
        int n,m;
        cin>>n>>m;
        map<pair<int,int>,int>mmap;
        for(int i=0;i<m;i++){
            int x,y,w;
            cin>>x>>y>>w;
            v[x].pb(mp(w,y));
        }
        dijkstra_1(1,n);
        for(int i=1;i<=n;i++){
          //  cout<<low[i]<<" "<<zz[i]<<endl;
        }
        cout<<dis[n]<<" "<<path[n]<<" "<<low[n]-1<<" "<<zz[n]-1<<endl;
        
 
    }
return 0;
}
