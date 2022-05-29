#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define uni(x)           x.erase(unique(x.begin(),x.end()),x.end());
#define int              long long
#define ld               long double
#define endl             "\n"
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
 
const int N=1e6;
const int M = 1000000007;
const int MM = 998244353;
const long double Pi= acos(-1);
 
const int inf=1e18;
 
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
*/
 
void simp()
{
    int a,b;
    cin>>a>>b;
    int n=__gcd(a,b);
    if(n==1){
        cout<<1<<endl;
        return ;
    }
    int ans=2;
    for(int i=2;i*i<=n;i++){
        if(n%i==0 ){
            if(i*i==n){
                ans++;
            }
            else{
                ans+=2;
            }
        }
    }
    cout<<ans<<endl;
}
signed main(){
 
    speed_; 
    
    int t;
    t=1;
    cin>>t;
    
    while(t--)
        simp();
    
return 0;
}