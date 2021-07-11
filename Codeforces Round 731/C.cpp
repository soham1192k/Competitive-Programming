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
	int k,n,m;cin>>k>>n>>m;
    vector<int>a(n),b(m);
    for(int&x:a) cin>>x;
    for(int&x:b) cin>>x;
    int posa=0,posb=0;
    vector<int>ans;
    while(posa<n&&posb<m){
        if(a[posa]==0){
            ans.push_back(0);posa++;k++;
        }
        else if(b[posb]==0){
            ans.push_back(0);posb++;k++;
        }
        else{
            if(a[posa]<=k) {ans.push_back(a[posa]);posa++;}
            else if(b[posb]<=k) {ans.push_back(b[posb]);posb++;}
            else {cout<<-1<<'\n';return;}
        }
    }
    while(posa<n){
        if(a[posa]==0){
            ans.push_back(0);
            k++;
            posa++;
        }
        else{
            if(a[posa]<=k){
                ans.push_back(a[posa]);
                posa++;
            }
            else{
                cout<<-1<<'\n';return;
            }
        }
    }
    while(posb<m){
        if(b[posb]==0){
            ans.push_back(0);
            k++;
            posb++;
        }
        else{
            if(b[posb]<=k){
                ans.push_back(b[posb]);
                posb++;
            }
            else{
                cout<<-1<<'\n';return;
            }
        }
    }
    for(auto x:ans) cout<<x<<" ";
    cout<<'\n';
}            
int32_t main(){
    soham1192k;
#ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    freopen("error.txt","w",stderr);
#endif  
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
