#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e6+2;
void solve(){   
    int n;cin>>n;
    vector<int>cnt(n);
    bool one=false;
    for(int& x:cnt) {cin>>x;if(x==1) one=true;}
    int maxx=-1e9;
    if(!one){
        cout<<2*n<<'\n';return;
    }
    int curr;
    for(int i=n-1;i>=0;i--){
        curr=0;
        if(cnt[i]==1){
            int lsubtree=n-1-i;
            int rsubtree=0;
            for(int j=i+1;j<n;j++){
                if(cnt[j]>1) rsubtree++;
                else break;
            }
            curr=lsubtree+rsubtree;
        }
        maxx=max(maxx,curr);
    }
    curr=n;
    for(int i=0;i<n;i++){
        if(cnt[i]>1) curr++;
        else break;
    }
    maxx=max(maxx,curr);
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
