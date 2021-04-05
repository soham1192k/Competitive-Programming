#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e5+2;
void solve(){  
    int n;cin>>n;
    vector<int>a(n);
    for(int& x:a) cin>>x;
    sort(a.begin(),a.end());
    int left=0,right=n-1;
    vector<int>hold;
    while(left<=right){
        hold.push_back(a[left]);
        if(left!=right)
        hold.push_back(a[right]);
        left++;
        right--;
    }
    for(auto x:hold) cout<<x<<" ";
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
