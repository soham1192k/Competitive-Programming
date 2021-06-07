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
const int mod=998244353;
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
vector<string>hold;
void pre(){
    for(char ch='a';ch<='z';ch++){
        string curr="";
        curr+=ch;
        hold.push_back(curr);
    }
    for(char ch='a';ch<='z';ch++){
        for(char ch1='a';ch1<='z';ch1++){
            string curr="";
            curr+=ch;
            curr+=ch1;
            hold.push_back(curr);
        }
    }
    for(char ch='a';ch<='z';ch++){
        for(char ch1='a';ch1<='z';ch1++){
            for(char ch2='a';ch2<='z';ch2++){
                string curr="";
                curr+=ch;
                curr+=ch1;
                curr+=ch2;
                hold.push_back(curr);
            }
        }
    }
}
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    map<string,bool>mp;
    for(int i=0;i<n;i++){
        string curr="";
        for(int j=i;j<n;j++){
            curr+=s[j];
            mp[curr]=true;
        } 
    }
    for(auto x:hold){
        if(mp[x]==false) {cout<<x<<'\n';return;}
    }
}   
int32_t main(){
    soham1192k;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w",stderr);
#endif  
    int T=1;
    pre();
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
