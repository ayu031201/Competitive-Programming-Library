#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define uni(x)           x.erase(unique(x.begin(),x.end()),x.end());
#define ld               long double
#define int              long long
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
 
const int N=10527449;
const int M = 1000000007;
const int MM = 998244353;
const long double Pi= acos(-1);
 
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1}; //8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1}; //Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction
 
vector<bool> is_prime(N+5, true);
vector<int>primes;
void precal(int n){
    
is_prime[0] = is_prime[1] = false;
for (int i = 2;i <=n ; i++) {
    if (is_prime[i]) {
        for (int j = i * i; j <= n; j += i){
            is_prime[j] = false;
        }
    }
}
for(int i=2;i<=n;i++){
    if(is_prime[i]){
        for(int j=i*i;j<=n;j+=i){
            if(is_prime[j/i] && is_prime[i] && j!=i*i){
                primes.pb(j);
            }
        }
    }
}
 
sort(sab(primes));
uni(primes);
} 
 
void simp(){
    
    int n;
    cin>>n;
    cout<<primes[n-1]<<endl;
    
}
 
signed main(){
 
    speed_; 
    //phi_1_to_n(N);
    
    int t;
    t=1;
    cin>>t;
    
    precal(N);
    while(t--){
        simp();
    }
    
return 0;
} 