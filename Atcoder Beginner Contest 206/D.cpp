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
int p[200005];
int sz[200005];
int get(int x){
    if(p[x]==x) return x;
    return p[x]=get(p[x]);
}
void union_sets(int a, int b) {
    a = get(a);
    b = get(b);
    if (a != b) {
        if (sz[a]<sz[b])
            swap(a, b);
        p[b]=a;
        sz[a]+=sz[b];
    }
}
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(int&x:a) cin>>x;
    for(int i=1;i<=n;i++){
        p[a[i-1]]=a[i-1];
        sz[a[i-1]]+=1;
    }
    int cnt=0;
    int i=0,j=n-1;
    for(i=0,j=n-1;i<j;i++,j--){
        int x=get(a[i]);
        int y=get(a[j]);
        if(x==y) ;
        else{
            cnt++;
            union_sets(a[i],a[j]);
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
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
