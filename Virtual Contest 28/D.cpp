
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e5+2;
void solve(){  
    int n;cin>>n;
    vector<int>a(n);
    for(int& x:a) cin>>x;
    set<pair<int,int>>s;
    for(int i=0;i<n;i++){
        s.insert({a[i],i});
    }
    vector<pair<int,int>>hold;
    while(s.size()>=2){
        pair<int,int>curr=(*s.begin());
        s.erase(s.begin());
        pair<int,int>curr1=(*s.begin());
        if(curr1.first==curr.first){
            s.erase(s.begin());
            s.insert({curr1.first+curr.first,curr1.second});
        }   
        else{
            hold.push_back({curr.second,curr.first});
        }
    }
    pair<int,int>curr=(*s.begin());
    hold.push_back({curr.second,curr.first});
    sort(hold.begin(),hold.end());
    cout<<hold.size()<<'\n';
    for(auto x:hold){
        cout<<x.second<<" ";
    }
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
