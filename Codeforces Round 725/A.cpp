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
 
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(int&x:a) cin>>x;
    int minn=1e9;int posmin=-1;
    int maxx=-1e9;int posmax=-1;
    for(int i=0;i<n;i++){
        if(minn>a[i]){
            minn=a[i];
            posmin=i;
        }
        if(maxx<a[i]){
            maxx=a[i];
            posmax=i;
        }
    }
    int op1=max(posmin,posmax);
    int op2=n-min(posmin,posmax)-1;
    int op3=posmin+n-posmax;
    int op4=posmax+n-posmin;
    cout<<min({op1,op2,op3,op4})+1<<'\n';
}
int32_t main(){
    soham1192k;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w",stderr);
#endif  
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
