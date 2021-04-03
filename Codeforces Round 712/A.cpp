#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e5+2;
void solve(){   
    string s;cin>>s;
    bool flag=true;
    for(int i=0;i<s.length();i++){
        if(s[i]!='a'){
            flag=false;break;
        }
    }
    if(flag){
        cout<<"NO\n";
        return;
    }
    int pos=-1;
    cout<<"YES\n";
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]!='a'){
            pos=i;break;
        }
    }
    int inser=s.length()-pos-1;
    string ans="";
    for(int i=0;i<inser;i++) ans+=s[i];
    ans+='a';
    for(int i=inser+1;i<=s.length();i++){
        ans+=s[i-1];
    }
    cout<<ans<<'\n';
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
