#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e5+2;
void solve(){
    int n,m;cin>>n>>m;
    int temp=min(n,m);
    n=max(n,m);
    m=temp;
    double hold=(double)m;
    int times=hold/(sqrt(3)/2);
    int one=n;
    one+=n-1;
    temp=max(n,m);
    n=min(n,m);
    m=temp;
    hold=(double)m;
    int timesone=hold/(sqrt(3)/2);
    int oneone=n;
    oneone+=n-1;
    cout<<max(one*times,oneone*timesone);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL); 
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif  
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
