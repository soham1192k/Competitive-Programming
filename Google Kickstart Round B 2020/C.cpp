#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int mxN=1e4+10;
int closing[mxN];
string expanded(string& s,int n,int left,int right){
    if(left>right) return "";
    string res="";
    for(int i=left;i<=right;i++){
        if(s[i]=='N'||s[i]=='S'||s[i]=='E'||s[i]=='W'){
            res+=s[i];
        }
        else if(s[i]>='0'&&s[i]<='9'){
            int val=s[i]-'0';
            string temp=expanded(s,n,i+2,closing[i+1]-1);
            for(int rep=1;rep<=val;rep++)
            res+=temp;
            i=closing[i+1];
        }
    }
    return res;
}
void solve(){
    string s;cin>>s;
    int n=s.length();
    stack<int>hold;
    for(int i=0;i<n;i++) closing[i]=-1;
    for(int i=0;i<n;i++){
        if(s[i]=='(') hold.push(i);
        else if(s[i]==')'){
            closing[hold.top()]=i;
            hold.pop();
        }
    }
    string res=expanded(s,n,0,n-1);
    int r=1;int c=1;
    for(int i=0;i<res.size();i++){
        if(res[i]=='N'){
            if(r==1){
                r=1e9;
            }
            else r--;
        }
        else if(res[i]=='S'){
            if(r==1e9) r=1;
            else r++;
        }
        else if(res[i]=='E'){
            if(c==1e9) c=1;
            else c++;
        }
        else{
            if(c==1) c=1e9;
            else c--;
        }
    }
    cout<<c<<" "<<r<<'\n';
}       
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int T=1;
    cin>>T;
    int tc=0;
    while(T--){
        ++tc;
        cout<<"Case #"<<tc<<": ";
        solve();
    }
    return 0;
}
