#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int mxN=10005;
void solve(){
    string s;cin>>s;
    char temp=s[0];
    for(int i=1;i<s.length();i++){
        s[i-1]=s[i];
    }
    s[s.length()-1]=temp;
    cout<<s;
}       
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL); 
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
