//soham
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define soham1192k ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" ";_print(x);cerr<<'\n';
#else
#define debug(x)
#endif
const int mod=1e9+7;
const double pi = 3.14159265358979323846;
const int mxN=2e5+1;
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
//******************************************************************************************************************************************************************

void solve(){
    int n,m;cin>>n>>m;
    set<pair<int,int>>s;
    for(int i=0;i<n;i++){
        int l,r;cin>>l>>r;
        s.insert({l,r});
    }
    for(int i=0;i<m;i++){
        int skill;cin>>skill;
        auto itr=s.upper_bound({skill,skill});
        vector<pair<int,int>>hold;
        if(itr==s.end()) itr--;
        hold.push_back((*itr));
        itr++;
        if(itr==s.end()) ;
        else hold.push_back((*itr));
        itr--;
        if(itr==s.begin()) ;
        else{
            itr--;
            hold.push_back((*itr));
        }
        pair<int,int>curr=(*itr);
        int currdiff=2e18+2;
        for(int j=0;j<hold.size();j++){
            pair<int,int>temp=hold[j];
            int starting=temp.first;
            int ending=temp.second;
            if(skill<=starting){
                if(currdiff>starting-skill){
                    curr=temp;
                    currdiff=starting-skill;
                }
            }
            else if(skill>=ending){
                if(currdiff>=skill-ending){
                    curr=temp;
                    currdiff=skill-ending;
                }
            }
            else{
                if(currdiff>0){
                    curr=temp;
                    currdiff=0;
                }
            }
        }
        pair<int,int>fin=curr;
        int starting=fin.first;
        int ending=fin.second;
        if(skill<=starting){
            s.erase(s.find(fin));
            cout<<starting<<" ";
            if(starting+1<=ending) s.insert({starting+1,ending});
        }
        else if(skill>=ending){
            s.erase(s.find(fin));
            cout<<ending<<" ";
            if(starting<=ending-1) s.insert({starting,ending-1});
        }
        else{
            s.erase(s.find(fin));
            cout<<skill<<" ";
            if(skill-1>=starting)
            s.insert({starting,skill-1});
            if(skill+1<=ending)
            s.insert({skill+1,ending});
        }
    }
    cout<<'\n';
}            
int32_t main(){
    soham1192k;
    int T=1;
    int tc=1;
    cin>>T;
    while(T--){
        cout<<"Case #"<<tc<<": ";
        solve();
        tc++;
    }
    return 0;
}
