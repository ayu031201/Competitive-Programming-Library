#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
 
#define int              long long
#define ld               long double
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
 
const int M = 1000000000;
const int MM = 998244353;
const long double Pi= acos(-1);
const int N=40005;
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
*/
vector<vector<int>>num(N);


void simp(){
    
    int n;
    cin>>n;
    int curr=0;
    num.resize(n+1);
    for(int i=0;i<n;i++){
        int ans=1;
        num[i].clear();
        for(int j=0;j<4;j++){
        int x;
        cin>>x;
        num[i].pb(x);
            if(j!=0){
                ans*=x;
            }
        }
        curr+=ans;
    }
    int vol;
    cin>>vol;
    if(vol>curr){
        cout<<"OVERFLOW";
    }
    else{
        ld l=0.0;
        ld r=inf;
        for(int i=0;i<=100;i++){
            ld mid=(l+r)/2;
            ld curr=0;
            for(int j=0;j<n;j++){
                if(mid<=num[j][0]){
                    continue;
                }
                else if(mid>num[j][0]+num[j][1]){
                    curr+=(num[j][1]*num[j][2]*num[j][3]);
                }
                else if(mid<=num[j][0]+num[j][1] && mid>num[j][0]){
                    curr+=((mid-num[j][0])*num[j][2]*num[j][3]);
                }
            }
            if(curr>=vol){
                r=mid;
            }
            else{
                l=mid;
            }
        }
        cout<<fixed<<setprecision(2)<<r;
    }
    cout<<endl;
    
    
    
    
    
}
signed main(){

    
    speed_; 
    
    int t;
    t=1;
    cin>>t;
    int curr=1;
    while(t--){  
        
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif  
        curr++;
        simp();
        
    }
return 0;
}