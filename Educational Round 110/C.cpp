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
const int mod=998244353;
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
    string s;cin>>s;
    int n=s.length();
    int dp[n][2];
    if(s[0]=='0') {dp[0][0]=1;dp[0][1]=0;}
    else if(s[0]=='1') {dp[0][1]=1;dp[0][0]=0;}
    else{
        dp[0][0]=dp[0][1]=1;
    }
    for(int i=1;i<n;i++){
        if(s[i]=='0'){
            dp[i][0]=1+dp[i-1][1];
            dp[i][1]=0;
        }
        else if(s[i]=='1'){
            dp[i][1]=1+dp[i-1][0];
            dp[i][0]=0;
        }
        else{
            dp[i][0]=1+dp[i-1][1];
            dp[i][1]=1+dp[i-1][0];
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1') cnt+=dp[i][1];
        else if(s[i]=='0') cnt+=dp[i][0];
        else{
            cnt+=max(dp[i][0],dp[i][1]);
        }
    }
    cout<<cnt<<'\n';
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
 
