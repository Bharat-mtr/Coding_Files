#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iomanip> 
#include <iostream> 
#include <bits/stdc++.h> 
#define N 200002
#define M 1000000007
#define fitr(i,a,b) for(auto i=a;i<b;i++)
#define ritr(i,a,b) for(auto i=b;i>=a;i--)
#define print(a) cout<<a<<endl
#define pb(a) push_back(a)
#define rangeitr(a) a.begin(),a.end()
#define pii pair<int,int>
#define ll long long int 
#define ld long double 
using namespace __gnu_pbds;
#define ordered_set tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update>

using namespace std;

vector<vector<int>> graph;
vector<bool>vis;
  
vector<ll> factors(ll n){
 vector<ll> v;
 fitr(i,1,(int)sqrt(n)+1){
     if(n%i==0){
         v.push_back(i);
         if(n/i!=i){
         v.push_back(n/i);
        }
     }
}
return v;
}
  int root[N];
  int sz[N];
  void make(int node){
      root[node]=node;
      sz[node]=1;
  }
  int find(int node){
      if(node==root[node]) return node;
      //path compression
      return root[node]=find(root[node]);
  }
  void Union(int node1,int node2){
      node1=find(node1);
      node2=find(node2);
      if(sz[node1]>sz[node2]) swap(node1,node2);
      root[node1]=node2;
      sz[node2]+=sz[node1];
  }
  int dx[4]={1,1,-1,-1};
  int dy[4]={-1,1,1,-1};
int parsenum(string &s,int &i){
    int n=0;
    while(i<(int)s.length() && isdigit(s[i])){
        n=n*10 + (s[i++]-'0');
    }
    return n;
}
int parsestr(string &s,int &i ){
    vector<int>v;
    char op='+';
    for(;i<(int)s.length() && op!=')';i++){
        int n=(s[i]=='(')?parsestr(s,++i):parsenum(s,i);
        if(op=='+') v.pb(n);
        if(op=='-') v.pb(-n);
        if(op=='*') v.back()*=n;
        if(op=='/') v.back()/=n;
        if(i<(int)s.length()) op=s[i];
    }
    return accumulate(rangeitr(v),0);
}
void solve(){
   string s;
   cin>>s;
   int i=0;
   cout<<parsestr(s,i);
}
int main() { 
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
std::cout << std::fixed;
std::cout << std::setprecision(11);
int t;
t=1;
//int i=1;
while(t--){
   // cout<<"Case #"<<i<<": ";
    solve();
    //i++;
}
return 0;
} 


