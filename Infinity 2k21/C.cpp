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
//******************************************************************************************************************************************

void solve(){
    int n,m;cin>>n>>m;
    vector<int>a(n),b(m);
    for(int&x:a) cin>>x;
    for(int&x:b) cin>>x;
    sort(b.rbegin(),b.rend());
    int i=0,j=0;
    bool win=false;
    while(i<n&&j<m){
        win=false;
        if(a[i]>b[j]) j++;
        else if(a[i]<b[j]) {i++;win=true;}
        else {i++;j++;win=true;}
    }
    if(j>=m) {cout<<"NO\n";return;}
    if(win) j++;
    vector<int>ans;
    for(int k=m-1;k>=j;k--){
        ans.push_back(b[k]);
    }
    for(int k=0;k<j;k++){
        ans.push_back(b[k]);
    }
    cout<<"YES\n";
    for(auto x:ans) cout<<x<<" ";
    cout<<'\n';
}  
int32_t main(){
    soham1192k;
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
