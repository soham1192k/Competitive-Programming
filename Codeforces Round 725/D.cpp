//Soham
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define soham1192k ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" ";_print(x);cerr<<'\n';
#else
#define debug(x)
#endif
const int mod=1000000007;
const double pi = 3.14159265358979323846;
const int mxN=2e5+2;
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
//*********************************************************************************************************************************************************************************************************
vector<int>primes;
void pre(int n){
    bool isprime[n+1];
    memset(isprime,true,sizeof(isprime));
    isprime[0]=isprime[1]=false;
    for(int i=2;i<=n;i++){
        if(isprime[i]){
            for(int j=i*i;j<=n;j+=i){
                isprime[j]=false;   
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(isprime[i]) primes.push_back(i);
    }
}
void solve(){
    int a,b,k;cin>>a>>b>>k;
    if(a>b) swap(a,b);
    if(k==1){
        if(b>a&&b%a==0) cout<<"YES\n";
        else cout<<"NO\n";
        return;
    }
    int cnt=0;
    for(int i=0;i<primes.size();i++){
        int curr=0;
        if(primes[i]*primes[i]>a) break;
        if(a%primes[i]==0){
            while(a%primes[i]==0){
                a/=primes[i];
                cnt++;
            }
        }
    }
    if(a!=1) cnt++;
    for(int i=0;i<primes.size();i++){
        int curr=0;
        if(primes[i]*primes[i]>b) break;
        if(b%primes[i]==0){
            while(b%primes[i]==0){
                b/=primes[i];
                cnt++;
            }
        }
    }
    if(b!=1) cnt++;
    if(k<=cnt) cout<<"YES\n";
    else cout<<"NO\n";
}
int32_t main(){
    soham1192k;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w",stderr);
#endif  
    int T=1;
    pre(32000);
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
