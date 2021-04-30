#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define soham1192k ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod=1e9+7;
const double pi = 3.14159265358979323846;
const int mxN=2e5+2;
void solve(){
	int l;cin>>l;
    string s;cin>>s;
    int bad=0,good=0;
    for(int i=0;i<l;i++){
        if(s[i]=='0') bad++;
        else good++;
        if(good>=bad) {cout<<"YES\n";return;}
    }
    cout<<"NO\n";
}
int32_t main(){
    soham1192k;
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
