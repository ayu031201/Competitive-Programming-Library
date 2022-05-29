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
const int N=1e4;
const int inf=1e18;
 
vector<vector<int>>v;
vector<int>vrev[N];
vector<int>dis(2501,inf);
int vis1[N],vis2[N],in[N],out[N],lvl[N];
set<int>s;
 
vector<int>order;
/*
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
    int pp=n;
    dis[n]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push(mp(0,n));
    while(!pq.empty()){
        auto curr=pq.top();
        pq.pop();
        if(dis[curr.ss]!=curr.ff){
            continue;
        }
        for(auto x:vd[curr.ss]){
            if(dis[x.ss]>x.ff+dis[curr.ss]){
                dis[x.ss]=x.ff+dis[curr.ss];
                pq.push(mp(dis[x.ss],x.ss));
                par[x.ss]=curr.ss;
            }
        }
    }
}
*/
int curr=1;
 
bool is_cycle(int n){
    vis1[n]=1;
    for(int i=0;i<sz(vrev[n]);i++){
        if(vrev[n][i]==curr && sz(vrev[vrev[n][i]])==0){
            continue;
        }
        if(s.find(vrev[n][i])!=s.end()){
            return 1;
        }
        if(!vis1[vrev[n][i]]){
            return is_cycle(vrev[n][i]);
        }
    }
    return 0;
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
        curr=1;
        for(int i=1;i<=m;i++){
            int x,y,w;
            cin>>x>>y>>w;
            v.pb({x,y,-w});
            vrev[y].pb(x);
        }
        dis[1]=0;
        for(int k=1;k<=n;k++){
            bool flag=0;
            for(auto x:v){
                if(dis[x[0]]<inf){
                    if(dis[x[1]]>dis[x[0]]+x[2]){
                        dis[x[1]]=dis[x[0]]+x[2];
                        flag=1;
                    }
                }
            }
            if(!flag){
                break;
            }
        }
        for(auto x:v){
            if(dis[x[0]]<inf){
                    if(dis[x[1]]>dis[x[0]]+x[2]){
                        dis[x[1]]=dis[x[0]]+x[2];
                        s.insert(x[1]);
                    }
            }
        }
        if(is_cycle(n)){
            cout<<-1<<endl;
            return 0;
        }
        cout<<-dis[n]<<endl;        
        
    }
return 0;
}
