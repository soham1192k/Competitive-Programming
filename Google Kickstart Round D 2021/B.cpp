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

void solve(){
    int n,c;cin>>n>>c;
    map<int,int>mp;vector<pair<int,int>>v;map<int,int>dp;
    priority_queue<pair<int,int>>q;
    for(int i=0;i<n;i++){
        int l,r;cin>>l>>r;
        //enclosed points
        mp[l+1]++;
        mp[r]--;
    }
    for(auto x:mp) v.push_back(x);
    int currdiff=0;
    for(int i=0;i<(int)v.size()-1;i++){
        currdiff+=v[i].second;
        dp[currdiff]+=v[i+1].first-v[i].first;
    }
    for(auto x:dp) q.push(x);
    int total=n;
    while(q.size()!=0&&c>0){
        pair<int,int>curr=q.top();
        q.pop();
        total+=min(c,curr.second)*curr.first;
        c-=min(c,curr.second);
    }
    cout<<total<<'\n';
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
