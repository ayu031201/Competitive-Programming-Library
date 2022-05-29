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
 
//vector<vector<int>>v(N),vrev(N);
 
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
int dx[]={1,0,-1,0};int dy[]={0,1,0,-1};
char dc[]={'D','R','U','L'};
int vis[1005][1005];
int vis2[1005][1005];
char path[1005][1005];
vector<vector<int>>timer(1001,vector<int>(1001,inf));
vector<vector<int>>timer2(1001,vector<int>(1001,inf));
bool is_valid(int a,int b,int x,int y,int c){
    if(a<0 || a>=x || b<0 || b>=y || (timer[a][b]!=inf && timer[a][b]>=c) || vis[a][b]){
        return false;
    }
    return true;
}
bool valid(int a,int b,int x,int y){
    if(a<0 || b<0 || a>=x || b>=y || vis2[a][b]){
        return false;
    }
    return true;
}
bool found(int a,int b,int x,int y){
    if((a==0 || a==x-1) && (b==0 || b==y-1)){
        return true;
    }
    return false;
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
        queue<pair<int,int>>q1;
        queue<pair<int,int>>q2;
        char arr[n][m];
        int src,en;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
                if(arr[i][j]=='M'){
                    q1.push(mp(i,j));
                    timer[i][j]=0;
                    vis[i][j]=1;
                }
                if(arr[i][j]=='A'){
                    q2.push(mp(i,j));
                    src=i;
                    en=j;
                    vis2[i][j]=1;
                    timer2[i][j]=0;
                }
            }
        }
        if((src==0 || src==n-1) || (en==0 || en==m-1)){
            cout<<"YES"<<endl;
            cout<<0;
            return 0;
        }
        while(!q1.empty()){
            int curr=q1.front().ff;
            int coun=q1.front().ss;
            q1.pop();
            for(int i=0;i<4;i++){
                int x=curr+dx[i];
                int y=coun+dy[i];
                if(is_valid(x,y,n,m,timer[curr][coun]+1) && arr[x][y]=='.'){
                    q1.push(mp(x,y));
                    timer[x][y]=min(timer[curr][coun]+1,timer[x][y]);
                    vis[x][y]=1;
                }
            }
        }
        vector<char>ans;
        bool answer=0;
        while(!q2.empty()){
            int curr=q2.front().ff;
            int coun=q2.front().ss;
            q2.pop();
            for(int i=0;i<4;i++){
                int x=curr+dx[i];
                int y=coun+dy[i];
                bool flag=0;
                timer2[x][y]=min(timer2[curr][coun]+1,timer2[x][y]);
                if(valid(x,y,n,m) && arr[x][y]=='.' && timer2[x][y]<timer[x][y]){
                    q2.push(mp(x,y));
                    path[x][y]=dc[i];
                    vis2[x][y]=1;
                    flag=1;
                }
                if(flag && (x==0 || x==n-1 || y==0 || y==m-1) && arr[x][y]=='.'){
                    int rem1=x;
                    int rem2=y;
                    answer=1;
                    while(1){
                        if(rem1==src && rem2==en){
                            break;
                        }
                        if(path[rem1][rem2]=='D'){
                            rem1--;
                            ans.pb('D');
                        }
                        else if(path[rem1][rem2]=='L'){
                            ans.pb('L');
                            rem2++;
                        }
                        else if(path[rem1][rem2]=='U'){
                            rem1++;
                            ans.pb('U');
                        }
                        else{
                            rem2--;
                            ans.pb('R');
                        }
                    }
                }
            }
            if(answer){
                break;
            }
        }
        if(answer){
            cout<<"YES"<<endl;
            cout<<sz(ans)<<endl;
            while(sz(ans)){
                cout<<ans.back();
                ans.po();
            }
        }
        else{
            cout<<"NO"<<endl;
        }
    }
return 0;
}
