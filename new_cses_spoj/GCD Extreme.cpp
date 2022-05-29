#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define uni(x)           x.erase(unique(x.begin(),x.end()),x.end());
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
 
const int N=1e6+4;
const int M = 1000000007;
const int MM = 998244353;
const long double Pi= acos(-1);
 
const int inf=1e18;
 
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1}; //8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1}; //Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction
 
 
 
vector<int> phi(N + 10);
void phi_1_to_n(int n) {
    
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i;
 
    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
vector<int>pre;
void simp(int n){
    pre=phi;
    pre[1]=0;
    for(int i=2;i<=n;i++){
        for(int j=2*i;j<=n;j+=i){
            pre[j]+=i*phi[j/i];
        }
        pre[i]+=pre[i-1];
    }
    
    
}
 
signed main(){
 
    speed_; 
    phi_1_to_n(N);
    
    int t;
    t=1;
    //cin>>t;
    
    simp(N);
    
    while(1){
        int n;
        cin>>n;
        if(n==0){
            break;
        }
        int curr=pre[n];
        cout<<curr<<endl;
        
    }
    
return 0;
}