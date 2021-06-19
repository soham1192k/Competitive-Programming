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
 
int lpf[1000001],mobius[1000001];
void least_prime_factor()
{
    for (int i=2;i<=1000000;i++)
        if (!lpf[i])
            for (int j=i;j<=1000000;j+=i)
                if (!lpf[j]) lpf[j] = i;
}
void Mobius()
{
    for (int i=1;i<=1000000;i++) {
        if (i == 1)
            mobius[i] = 1;
        else {
            if (lpf[i / lpf[i]] == lpf[i])
                mobius[i] = 0;
            else
                mobius[i] = -1 * mobius[i / lpf[i]];
        }
    }
}
int gcd_pairs(int a[], int n)
{
    int maxi = 0;
    int fre[1000001] = { 0 };
    for (int i=0;i<n;i++) {
        fre[a[i]]++;
        maxi = max(a[i], maxi);
    }
    least_prime_factor();
    Mobius();
    int ans = 0;
    for (int i = 1; i <= maxi; i++) {
        if (!mobius[i])
            continue;
        int temp = 0;
        for (int j = i; j <= maxi; j += i)
            temp += fre[j];
        ans += temp * (temp - 1) / 2 * mobius[i];
    }
    return ans;
}
void solve(){
    int l,r;cin>>l>>r;
    int a[r-l+1];
    for(int i=l;i<=r;i++) a[i-l]=i;
    int val=gcd_pairs(a,r-l+1);
    val*=2;
    // cout<<val<<'\n';
    int n=r-l+1;
    int total=n*n-n;
    total-=val;
    for(int i=l;i<=r;i++){
        if(i==1) continue;
        int what=r/i;
        total-=(what-1)*2;
    }
    cout<<total<<'\n';
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
