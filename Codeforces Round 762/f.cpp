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
    int n,m,k;cin>>n>>m>>k;
    int mult=n/m;
    if(n%m!=0) mult++;
    int ceil=mult;
    int floor=n/m;
    int total=k*(n%m)*mult;
    if(total==0){
        for(int i=1;i<=k;i++){
            for(int j=1;j<=m;j++){
                cout<<(n/m)<<" ";
                for(int p=(j-1)*(n/m)+1;p<=j*(n/m);p++) cout<<p<<" ";
                cout<<'\n';
            }
        }
    }
    else{
        priority_queue<pair<int,int>>q;
        vector<int>b(n,total/n);
        for(int i=0;i<total%n;i++) b[i]++;
        for(int i=0;i<n;i++) q.push({b[i],i+1});
        for(int i=1;i<=k;i++){
            bool marked[n+1];
            memset(marked,false,sizeof(marked));
            for(int table=1;table<=n%m;table++){
                cout<<ceil<<" ";
                for(int person=1;person<=ceil;person++){
                    cout<<q.top().second<<" ";
                    marked[q.top().second]=true;
                    pair<int,int>now=q.top();
                    q.pop();
                    q.push({now.first-1,now.second});
                }
                cout<<'\n';
            }
            int ptr=1;
            for(int table=n%m+1;table<=m;table++){
                cout<<floor<<" ";
                for(int person=1;person<=floor;person++){
                    while(ptr<=n&&marked[ptr]) ptr++;
                    if(ptr<=n) {marked[ptr]=true;cout<<ptr<<" ";}
                }
                cout<<'\n';
            }
        }
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
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
