#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int mxN=10005;
void solve(){
    string a,b;cin>>a>>b;
    vector<string>hold1,hold2;
    for(int i=0;i<a.length();i++){
        string curr="";
        for(int j=i;j<a.length();j++){
            curr+=a[j];
            hold1.push_back(curr);
        }
    }
    for(int i=0;i<b.length();i++){
        string curr="";
        for(int j=i;j<b.length();j++){
            curr+=b[j];
            hold2.push_back(curr);
        }
    }
    int maxlen=0;
    string ans="";
    for(auto x:hold1){
        // cout<<x<<" ";
        for(int i=0;i<hold2.size();i++){
            if(x==hold2[i]){
                if(maxlen<x.length()){
                    maxlen=x.length();
                    ans=x;
                }
            }
        }
    }
    int cnt=0;
    int len=ans.length();
    for(int i=0;i<a.length();i++){
        if(a.substr(i,len)==ans){
            cnt+=(i+(a.length()-(i+len)));break;
        }
    }
    for(int i=0;i<b.length();i++){
        if(b.substr(i,len)==ans){
            cnt+=(i+(b.length()-(i+len)));break;
        }
    }
    cout<<cnt<<'\n';
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
