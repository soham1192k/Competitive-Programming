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
#define ll long long
void solve(){
    int n,l,r;cin>>n>>l>>r;
    vector<int>a(n);
    for(int&x:a) cin>>x;
    sort(a.begin(),a.end());
    int ans=0;
    for(int i=0;i<n;i++){
        int now=a[i];
        int low=i+1;
        int high=n-1;
        int op1=-1e9,op2=-1e9;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(a[mid]+now>=l){
                high=mid-1;op1=mid;
            }
            else{
                low=mid+1;
            }
        }
        low=i+1;
        high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(a[mid]+now<=r){
                op2=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        if(op1==-1e9||op2==-1e9) ;
        else{
            int range=op2-op1;
            ans+=1+range;
        }
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
