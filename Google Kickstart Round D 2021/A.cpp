//soham
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

vector<vector<int>>v(3,vector<int>(3));
int cnt(int i){
    int how=0;
    if(i==-1e9-1){
        if(v[0][0]+v[0][2]==2*v[0][1]) how++;
        if(v[2][0]+v[2][2]==2*v[2][1]) how++;
        if(v[0][0]+v[2][0]==2*v[1][0]) how++;
        if(v[0][2]+v[2][2]==2*v[1][2]) how++;
    }
    else{
        if(v[0][0]+v[0][2]==2*v[0][1]) how++;
        if(v[1][0]+v[1][2]==2*i) how++;
        if(v[2][0]+v[2][2]==2*v[2][1]) how++;
        if(v[0][0]+v[2][0]==2*v[1][0]) how++;
        if(v[0][1]+v[2][1]==2*i) how++;
        if(v[0][2]+v[2][2]==2*v[1][2]) how++;
        if(v[0][0]+v[2][2]==2*i) how++;
        if(v[0][2]+v[2][0]==2*i) how++;
    }
    return how;
}
void solve(){
    cin>>v[0][0]>>v[0][1]>>v[0][2];
    cin>>v[1][0]>>v[1][2];
    cin>>v[2][0]>>v[2][1]>>v[2][2];
    vector<int>poss;
    if((v[1][0]+v[1][2])%2==0) poss.push_back((v[1][0]+v[1][2])/2);
    if((v[0][1]+v[2][1])%2==0) poss.push_back((v[0][1]+v[2][1])/2);
    if((v[0][0]+v[2][2])%2==0) poss.push_back((v[0][0]+v[2][2])/2);
    if((v[0][2]+v[2][0])%2==0) poss.push_back((v[0][2]+v[2][0])/2);
    int maxx=0;
    maxx=max(maxx,cnt(-1e9-1));
    for(int i:poss){
        maxx=max(maxx,cnt(i));
    }
    cout<<maxx<<'\n';
}            
int32_t main(){
    soham1192k;
    int T=1;
    int tc=1;
    cin>>T;
    while(T--){
        cout<<"Case #"<<tc<<": ";
        solve();
        tc++;
    }
    return 0;
}
