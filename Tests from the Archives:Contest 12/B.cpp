#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e5+2;
void solve(){   
    int n;cin>>n;
    vector<int>a(n);
    for(int& x:a) cin>>x;
    int i=0;int j=n-1;int maxx=0;
    while(i<j){
        if(a[i]<a[j]){
            maxx=max(maxx,(j-i-1)*a[i]);
            i++;
        }
        else if(a[j]<a[i]){
            maxx=max(maxx,(j-i-1)*a[j]);
            j--;
        }
        else{
            maxx=max(maxx,(j-i-1)*a[i]);
            i++;j--;
        }
    }
    cout<<maxx<<'\n';
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL); 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif  
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
