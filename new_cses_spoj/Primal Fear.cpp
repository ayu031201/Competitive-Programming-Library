#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define uni(x)           x.erase(unique(x.begin(),x.end()),x.end());
#define ld               long double
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
 
const int N=1e6+4;
const int M = 1000000007;
const int MM = 998244353;
const long double Pi= acos(-1);
 
 
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1}; //8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1}; //Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction
 
bool mark[N];
vector<long long> primes(N,0);
 
void precal(int n){
    
    long long lim = n;
    for (long long i = 2; i <= lim; ++i) {
        primes[i]+=primes[i-1];
        if (!mark[i]) {
            int k=ceil(log10(i));
            int z=i;
            bool flag=0;
            while(z){
                int curr=z%10;
                if(curr==0 ){
                    flag=1;
                    break;
                }
                z/=10;
            }
            int j=10;
            
            while(k && flag==0){
                int x=i%j;
                if(x==1 || x==0){
                    flag=1;
                    break;
                }
                else{
                    if(mark[x]){
                        flag=1;
                        break;
                    }
                }
                j*=10;
                k--;
            }
            if(flag==0){
              //  cout<<i<<" ";
                primes[i]++;
            }
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }
    
} 
 
void simp(){
    int n;
    cin>>n;
    cout<<primes[n]<<endl;
    
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