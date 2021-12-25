#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define soham1192k ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" ";_print(x);cerr<<'\n';
#else
#define debug(x)
#endif
const int mod=1e9+7;
const double pi = 3.14159265358979323846;
const int mxN=2e5+1;
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
//******************************************************************************************************************************************************************

void solve(){
    int n,k;cin>>n>>k;
    string s;cin>>s;
    if(n==1) {cout<<s<<'\n';return;}
    string ans=s.substr(k,n-k);
    string curr="";
    if(k%2==1){
        int now=k/2;
        curr+=s[now];
        int offset=1;
        while(now+offset<k){
            if(k/2+offset<k)
            curr+=s[k/2+offset];
            if(k/2-offset>=0)
            curr+=s[k/2-offset];
            offset++;
        }
        cout<<curr+ans<<'\n';
    }
    else{
        int now=k/2;
        int offset=1;
        curr+=s[now];
        if(now-1>=0) curr+=s[now-1];
        while(offset+k/2<k){
            if(k/2+offset<k)
            curr+=s[k/2+offset];
            if(k/2-1-offset>=0)
            curr+=s[k/2-1-offset];
            offset++;
        }
        cout<<curr+ans<<'\n';
    }
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
