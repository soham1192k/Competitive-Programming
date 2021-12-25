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
    int n;cin>>n;
    if(n%2==1){
        if(n==1){
            cout<<1<<'\n';
            cout<<1<<" "<<1<<'\n';
        }
        else{
            set<int>hold;
            map<int,int>mp;
            hold.insert(2);
            hold.insert(1);
            mp[2]++;mp[1]=n-2;
            hold.insert((n+1)/2);
            mp[(n+1)/2]++;
            cout<<hold.size()<<'\n';
            for(auto x:mp) cout<<x.first<<" "<<x.second<<'\n';
        }
    }
    else{
        if(n==2){
            cout<<2<<'\n';
            cout<<3<<" "<<1<<'\n';
            cout<<4<<" "<<1<<'\n';
        }
        else{
            set<int>hold;
            hold.insert(1);
            hold.insert((n-2)/2);
            cout<<hold.size()<<'\n';
            if(hold.size()==1) cout<<1<<" "<<n<<'\n';
            else {cout<<1<<" "<<n-1<<'\n';cout<<((n-2)/2)<<" "<<1<<'\n';}
        }
    }
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
