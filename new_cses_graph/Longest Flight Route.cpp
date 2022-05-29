#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
 
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
const int N=1e5+5;
const int inf=1e18;
 
vector<set<pair<int,int>>>v,vrev[N];
vector<int>dis(N,0),diss(N,0);
int par[N];
int vis1[N];
 
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
 
int dx[]={-1,-1,1,1,2,2,-2,-2}; // Distance matrix when there are 8 Moves.
int dy[]={2,-2,2,-2,1,-1,1,-1};
 
void grid_floyd_warshall(int n,int m,int p,int z){
        vector<vector<int>>dis(9,vector<int>(9,inf));
        queue<pair<int,int>>q;
        q.push(mp(n,m));
        dis[n][m]=0;
            while(!q.empty()){
                int curr=q.front().ff;
                int coun=q.front().ss;
                q.pop();
            for(int i=0;i<8;i++){
                int x=curr+dx[i];
                int y=coun+dy[i];
 
                if(is_valid(x,y) && dis[x][y]>dis[curr][coun] + cc(curr,coun,x,y)){
                    dis[x][y]=dis[curr][coun]+cc(curr,coun,x,y);
                    q.push(mp(x,y));
                }
            }
            }
            if(dis[p][z]==inf){
                cout<<-1<<endl;
            }
            else{
                cout<<dis[p][z]<<endl;
            }
    }
 
*/
void dijkstra(int n){
    dis[n]=0;
    par[n]=-1;
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
                par[x.ss]=curr.ss;
            }
        }
    }
}
 
 
signed main(){
    
    speed_; 
    
    int t;
    t=1;
   // cin>>t;
    while(t--){  
    
   
#ifndef ONLINE_JUDGE
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
#endif  
        int n,m;
        cin>>n>>m;
        v.resize(n+1);
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            v[x].insert({-1,y});
        }
        dijkstra(1);
        if(dis[n]==0){
            cout<<"IMPOSSIBLE"<<endl;
        }
        else{
            cout<<-dis[n]+1<<endl;
            vector<int>ans;
            for(int i=n;i!=-1;i=par[i]){
                ans.pb(i);
            }
            reverse(sab(ans));
            for(auto x:ans){
                cout<<x<<" ";
            }
        }
    }
return 0;
}
