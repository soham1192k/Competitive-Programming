#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e6+2;
void solve(){   
    int n;cin>>n;
    string s,t;cin>>s>>t;
    vector<int>f,ss,none;int both=0;
    for(int i=0;i<2*n;i++){
        if(s[i]=='1'&&t[i]=='0'){
            f.push_back(i);
        }
        else if(s[i]=='0'&&t[i]=='1'){
            ss.push_back(i);
        }
        else if(s[i]=='1'&&t[i]=='1') 
        both++;
        else none.push_back(i);
    }
    string fir="";
    string sec="";
    for(int i=1;i<=both/2;i++){
        fir+='1';
        sec+='1';
    }
    int chance=1;
    if(both%2==1) {fir+='1';chance=2;}
    int hold1=0,hold2=0;
    while(hold1<f.size()&&hold2<ss.size()){
        if(chance==1){
            fir+='1';
            hold1++;
            chance=2;
        }
        else{
            sec+='1';
            hold2++;
            chance=1;
        }
    }
    while(hold1<f.size()){
        if(chance==1){
            fir+='1';
            hold1++;
            chance=2;
        }
        else{
            sec+='0';
            hold1++;
            chance=1;
        }
    }
    while(hold2<ss.size()){
        if(chance==1){
            fir+='0';
            hold2++;
            chance=2;
        }
        else{
            sec+='1';
            hold2++;
            chance=1;
        }
    }
    hold1=0;
    while(hold1<none.size()){
        if(chance==1){
            fir+='0';
            hold1++;
            chance=2;
        }
        else{
            sec+='0';
            hold1++;
            chance=1;
        }
    }
    if(fir==sec) cout<<"Draw";
    else if(fir>sec) cout<<"First";
    else cout<<"Second";
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
