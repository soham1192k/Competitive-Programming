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

bool ok(int mid,vector<vector<int>>&a,int m,int n){
    bool done[n];
    bool flag=false;
    memset(done,false,sizeof(done));
    for(int i=0;i<m;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(a[i][j]>=mid) {done[j]=true;cnt++;} 
        }
        if(cnt>=2) flag=true;
    }
    for(int i=0;i<n;i++){
        if(done[i]==false) return false;
    }
    return flag;
}
void solve(){
    int m,n;cin>>m>>n;
    vector<vector<int>>a(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++) cin>>a[i][j];
    }
    int low=1,high=1e9;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(ok(mid,a,m,n)){
            ans=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    cout<<ans<<'\n';
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
