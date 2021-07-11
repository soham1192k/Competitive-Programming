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
int dp[1001][5];
int st[2000001][4];
vector<int>a(500001);
int power(int a,int b){
    int ans=1;
    while(b){
        if(b&1){
            b--;
            ans=(ans*a);
        }
        else{
            b=b>>1;
            a=(a*a);
        }
    }
    return ans;
}
int v(int x,int p){
    if(x==0) return 0;
    int cnt=0;
    while(x%p==0){
        cnt++;
        x/=p;
    }
    return cnt;
}
void  build(int si,int ss,int se,int s){
    if(ss==se) {st[si][s]=dp[a[ss]][s];return;}
    int m=(ss+se)>>1;
    build(2*si,ss,m,s);
    build(2*si+1,m+1,se,s);
    st[si][s]=st[2*si][s]+st[2*si+1][s];
}
void update(int si,int ss,int se,int pos,int val,int s){
    if(ss==se){
        st[si][s]=dp[val][s];
        return;
    }
    int m=(ss+se)>>1;
    if(pos<=m) update(2*si,ss,m,pos,val,s);
    else update(2*si+1,m+1,se,pos,val,s);
    st[si][s]=st[2*si][s]+st[2*si+1][s];
}
int query(int si,int ss,int se,int qs,int qe,int s){
    if(qs>se||qe<ss) return 0;
    if(ss>=qs&&se<=qe) return st[si][s];
    int m=(ss+se)>>1;
    return query(2*si,ss,m,qs,qe,s)+query(2*si+1,m+1,se,qs,qe,s);
}
void solve(){
    memset(dp,-1,sizeof(dp));
    a.clear();
    memset(st,0,sizeof(st));
    int n,q,p;cin>>n>>q>>p;
    for(int i=1;i<=1000;i++){
        for(int s=1;s<=4;s++){
            dp[i][s]=v(power(i,s)-power(i%p,s),p);
        }
    }
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int s=1;s<=4;s++)
    build(1,1,n,s);
    for(int i=1;i<=q;i++){
        int type;cin>>type;
        if(type==1){
            int pos,val;cin>>pos>>val;
            for(int s=1;s<=4;s++)
            update(1,1,n,pos,val,s);
        }
        else{
            int s,l,r;cin>>s>>l>>r;
            cout<<query(1,1,n,l,r,s)<<" ";
        }
    }
    cout<<'\n';
}            
int32_t main(){
    soham1192k;
    int T=1;
    int tc=1;
    cin>>T;
    while(T--){
        cout<<"Case #"<<tc<<": ";
        solve();
        tc++;
    }
    return 0;
}
