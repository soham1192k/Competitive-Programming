#include<bits/stdc++.h>
using namespace std;
#define int long long 
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
    int n;cin>>n;
    vector<int>a(n),b(n);
    for(int&x:a) cin>>x;for(int&x:b) cin>>x;
    bool flag=true;
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]||b[i]>b[i+1]) flag=false;
    }
    if(flag) {cout<<0<<'\n';return;}
    vector<pair<int,int>>v;
    int cnt=0;
    while(cnt<10000){
        bool swapped=false;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(a[i]>a[j]&&b[j]<=b[i]){
                    swap(a[i],a[j]);
                    swap(b[i],b[j]);
                    v.push_back({i,j});
                    swapped=true;
                }
                else if(b[i]>b[j]&&a[j]<=a[i]){
                    swap(a[i],a[j]);
                    swap(b[i],b[j]);
                    v.push_back({i,j});
                    swapped=true;
                }
            }
        }
        if(!swapped) break;
        cnt++;
    }
    flag=true;
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]||b[i]>b[i+1]) flag=false;
    }
    if(flag){
        cout<<(int)v.size()<<'\n';
        for(auto x:v){
            cout<<x.first+1<<" "<<x.second+1<<'\n';
        }
    }
    else cout<<-1<<'\n';
}  
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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
