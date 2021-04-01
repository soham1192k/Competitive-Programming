#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e6+2;
void solve(){   
    string s;cin>>s;
    int n=s.length();vector<int>v(n);
    if(n==1||n==2) {cout<<"YES";return;}
    for(int i=0;i<n;i++){
        v[i]=s[i]-'A'+1;
    }
    // for(auto x:v) cout<<x<<" ";
    // cout<<'\n';
    int first=v[0];
    int second=v[1];
    for(int i=2;i<n;i++){
        int third=(first+second-1)%26;
        // third++;
        if(v[i]!=third){
            cout<<"NO";return;
        }
        first=second;
        second=third;
    }
    cout<<"YES";
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
