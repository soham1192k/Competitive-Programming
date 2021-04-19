#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e5+2;
bool checkprime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
void solve(){  
    int z;cin>>z;
    int g1=0,s1=0,s2=0;
    int sq=(int)sqrt(z);
    int curr=sq+1;
    while(true){
        if(checkprime(curr)) {g1=curr;break;}
        else curr++;
    }   
    curr=sq;
    while(true){
        if(checkprime(curr)) {s1=curr;break;}
        else curr--;
    }
    curr=s1-1;
    while(true){
        if(checkprime(curr)) {s2=curr;break;}
        else curr--;
    }
    // cout<<s1<<" "<<s2<<" "<g1<<'\n';
    int op1=s1*g1;
    int op2=s1*s2;
    if(op1<=z) cout<<op1<<'\n';
    else cout<<op2<<'\n';
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL); 
    int T=1;
    cin>>T;
    int tc=0;
    while(T--){
        tc++;
        cout<<"Case #"<<tc<<": ";
        solve();
    }
    return 0;
}
