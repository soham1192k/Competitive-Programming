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

map<pair<int,int>,int>id;//maps (x,y) to id
map<int,int>minn;//maps id to min explosion time in that component
map<int,int>par;
int find(int x){
    if(par[x]==x) return x;
    return par[x]=find(par[x]);
}
void merge(int x,int y){
    int fx=find(x);
    int fy=find(y);
    if(fx==fy) return ;
    par[fx]=fy;
    minn[fy]=min(minn[fy],minn[fx]);
}
bool cmp(pair<int,int>&a,pair<int,int>&b){
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}
bool cmp1(pair<int,int>&a,pair<int,int>&b){
    if(a.second==b.second) return a.first<b.first;
    return a.second<b.second;
}
void solve(){
    id.clear();
    minn.clear();
    int n,k;cin>>n>>k;
    vector<pair<int,int>>hold;
    for(int i=1;i<=n;i++){
        int x,y,t;cin>>x>>y>>t;
        id[{x,y}]=i;
        minn[i]=t;
        par[i]=i;
        hold.push_back({x,y});
    }
    sort(hold.begin(),hold.end(),cmp);//sorts x coordinates
    for(int i=1;i<n;i++){
        if(hold[i].first==hold[i-1].first&&hold[i].second-hold[i-1].second<=k)
        merge(id[hold[i]],id[hold[i-1]]);
    }
    sort(hold.begin(),hold.end(),cmp1);//sorts y coordinates
    for(int i=1;i<n;i++){
        if(hold[i].second==hold[i-1].second&&hold[i].first-hold[i-1].first<=k)
        merge(id[hold[i]],id[hold[i-1]]);
    }
    set<int>finalid;
    for(int i=1;i<=n;i++){
        if(par[i]==i) finalid.insert(i);
    }
    vector<pair<int,int>>fin;//{min time,id number}
    for(auto x:finalid) fin.push_back({minn[x],x});
    sort(fin.begin(),fin.end());
    debug(fin);
    int f=0,e=fin.size()-1;
    int time=-1;
    while(f<=e){
        time++;
        e--;
        while(f<fin.size()&&fin[f].first<=time) f++; 
    }
    cout<<time<<'\n';
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
