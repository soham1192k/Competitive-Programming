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
    int n;cin>>n;
    vector<int>a(n);
    int cost=0;
    for(int&x:a) cin>>x;
    vector<pair<int,int>>hold;
    for(int i=0;i<n;i++) hold.push_back({a[i],i});
    sort(hold.begin(),hold.end());
    vector<int>b(n);
    map<int,int>mp;
    for(int i=0;i<n;i++){
        b[hold[i].second]=i+1;
        mp[i+1]=hold[i].first;
    }
    a=b;
    int left=0,right=a[0]-1;
    int pos=1;int maxx=a[0];int minn=a[0];
    if(a[0]==1) {left++;if(1<n) maxx=a[1];if(1<n) minn=a[1];}
    while(pos<n){
        if(a[pos]==pos+1&&right<=pos) {left++;if(pos+1<n) {maxx=a[pos+1];minn=a[pos+1];}}
        else {right=max(right,a[pos]-1);minn=min(minn,a[pos]);maxx=max(maxx,a[pos]);}
        if(pos==right&&left!=right){
            cost+=mp[maxx]-mp[minn];
            if(pos+1<n){
                maxx=a[pos+1];
                minn=a[pos+1];
                left=pos+1;
                right=a[pos+1]-1;
            }
        } 
        pos++;
    }
    cout<<cost<<'\n';
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
