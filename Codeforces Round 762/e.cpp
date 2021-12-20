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
 
map<int,int>mp;
bool ok(int mid,vector<int>&a,int n){
    int now=0;
    for(int i=0;i<mid;i++){
        now+=mp[i];
        if(now<i+1) return false; 
    }
    return true;
}
void solve(){
    int n;cin>>n;
    mp.clear();
    vector<int>a(n);
    for(int&x:a) cin>>x;
    for(int i=0;i<n;i++) mp[a[i]]++;
    int low=0,high=n;
    int id=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(ok(mid,a,n)){
            id=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    vector<int>ans(n+1);
    for(int i=id+1;i<=n;i++){
        ans[i]=-1;
    }
    //0-->mp[0]
    //1-->mp[1]
    //2-->
    vector<int>empty;
    if(id>=0) ans[0]=mp[0];
    if(id>=1) ans[1]=mp[1];
    priority_queue<int>nearestextra;
    if(mp[0]>=2){
        for(int i=1;i<=mp[0]-1;i++) nearestextra.push(0);
    }
    if(mp[1]>=2){
       for(int i=1;i<=mp[1]-1;i++) nearestextra.push(1);
    }
    for(int i=2;i<=id;i++){
        ans[i]=mp[i]+ans[i-1]-mp[i-1];
        if(mp[i-1]==0) {ans[i]+=(i-1-nearestextra.top());nearestextra.pop();}
        if(mp[i]>=2){
            for(int j=1;j<=mp[i]-1;j++) nearestextra.push(i);        
        }
    }
    for(auto x:ans) cout<<x<<" ";
    cout<<'\n';
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
