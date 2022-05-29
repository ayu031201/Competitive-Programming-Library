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
 
const int N=1e6;
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
        primes.pb(i);
        for (int j = 2 * i; j <= n; j += i){
            is_prime[j] = false;
        }
    }
}

} 

int fac(int n){
    int ans=0;
    if(n==1){
        return 0;
    }
    for(int i=0;primes[i]*primes[i]<=n;i++){
        int k=primes[i];
        if(n%k==0){
            ans++;
            while(n%k==0){
                n/=k;
            }
        }
    }
    if(n>1){
        ans++;
    }
    return ans;
}
int ans[N+5][11];
void prefix_sum(){
    for(int i=1;i<=N;i++){
        int k=fac(i);
        for(int j=0;j<=10;j++){
            if(k==j || (i==1 && j==0)){
                ans[i][j]+=1;
              //  cout<<k<<" "<<j;
            }
            ans[i][j]+=ans[i-1][j];
        }
    }
}
 
void simp(){
    
    int n,m,k;
    cin>>n>>m>>k;
    int ans=__gcd(n,m);
    if(k%ans==0){
        cout<<": Yes";
    }
    else{
        cout<<": No";
    }
    cout<<endl;
}
 
signed main(){
 
    speed_; 
    //phi_1_to_n(N);
    
    int t;
    t=1;
    cin>>t;
    
   // precal(N);
   // prefix_sum();
    int i=1;
    while(t--){
        cout<<"Case "<<i;
        i++;
        simp();
    }
    
return 0;
}  