#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e6+2;
void solve(){   
    int n;cin>>n;
    vector<int>a(n);
    for(int& x:a) cin>>x;
    int pos=-1;int cpy=-1;
    for(int i=0;i<n-1;i++){
        if(a[i]-a[i+1]==1){
            pos=i;cpy=i;break;
        }
    }
    if(pos==-1){
        cout<<"0 0";return;
    }
    while(pos+1<n&&a[pos]-a[pos+1]==1){
        pos++;
    }
    // cout<<cpy<<" "<<pos<<'\n';
    reverse(a.begin()+cpy,a.begin()+pos+1);
    for(int i=1;i<=n;i++){
        if(a[i-1]!=i){
            cout<<"0 0";return;
        }
    }
    cout<<cpy+1<<" "<<pos+1<<'\n';
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
