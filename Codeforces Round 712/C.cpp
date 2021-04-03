#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e5+2;
void solve(){   
    int n;cin>>n;
    string s;cin>>s;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0') cnt++;
    }
    string a=s;
    string b=s;
    if(s[0]=='1'&&s[n-1]=='1'&&cnt%2==0){
        cout<<"YES\n";
        int counter=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                counter++;
                if(counter<=(n-cnt)/2){
                    a[i]='(';b[i]='(';
                }
                else{
                    a[i]=')';b[i]=')';
                }   
            }
        }
        int chance=1;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                if(chance==1){
                    a[i]='(';
                    b[i]=')';
                    chance=2;
                }
                else{
                    a[i]=')';
                    b[i]='(';
                    chance=1;
                }
            }
        }
        cout<<a<<'\n'<<b<<'\n';
    }
    else{
        cout<<"NO\n";return;
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
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
