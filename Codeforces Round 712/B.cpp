#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e5+2;
void solve(){   
    int n;cin>>n;
    string s,t;cin>>s>>t;
    if(s==t){
        cout<<"YES\n";return;
    }
    vector<pair<int,int>>v(n);
    if(s[0]=='0') v[0]={1,0};
    else v[0]={0,1};
    for(int i=1;i<n;i++){
        if(s[i]=='0'){
            v[i]={v[i-1].first+1,v[i-1].second};
        }
        else{
            v[i]={v[i-1].first,v[i-1].second+1};
        }
    }
    vector<int>critical;
    bool diff=1;
    for(int i=n-1;i>=0;i--){
        if(diff==1&&((s[i]=='1'&&t[i]=='0')||(s[i]=='0'&&t[i]=='1'))){
            diff=0;
            critical.push_back(i);
        }
        else if(diff==0&&((t[i]=='1'&&s[i]=='1')||(s[i]=='0'&&t[i]=='0'))){
            diff=1;critical.push_back(i);
        }
    }
    for(auto x:critical){
        if(v[x].first!=v[x].second){
            cout<<"NO\n";return;
        }
    }
    cout<<"YES\n";
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
