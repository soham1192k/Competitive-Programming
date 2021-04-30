#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e5+2;
void solve(){   
    int n;cin>>n;
    vector<int>u(n),s(n);
    for(int i=0;i<n;i++) {cin>>u[i];u[i]--;}
    map<int,int>mp;
    for(int& x:s) cin>>x;
    vector<int>v[n+1];
    for(int i=0;i<n;i++){
        v[u[i]].push_back(s[i]);
        mp[u[i]]++;
    }
    for(int i=0;i<n;i++) sort(v[i].rbegin(),v[i].rend());
    for(int i=0;i<n;i++){
        for(int j=0;j<mp[i];j++){
            if(j==0) ;
            else v[i][j]+=v[i][j-1];
        }
    }
    vector<int>fin(n);
    for(int i=0;i<n;i++){
        for(int ts=1;ts<=mp[i];ts++){
            int actualend=mp[i]-1;
            int endingpoint=actualend-(mp[i]%ts);
            fin[ts-1]+=v[i][endingpoint];
        }
    }
    for(int i=0;i<n;i++) cout<<fin[i]<<" ";
    cout<<'\n';
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
