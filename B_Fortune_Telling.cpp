#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iomanip> 
#include <iostream> 
#include <bits/stdc++.h> 
#define N 200002
#define M 1000000007
#define fitr(i,a,b) for(auto i=a;i<b;i++)
#define ritr(i,a,b) for(auto i=b;i>=a;i--)
#define print(a) cout<<a<<endl;
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


void solve(){
    int n;
       cin>>n;
       if(n==1){
        print(0);
        return;
       }
       int arr[n];
       int mx=INT_MIN;
       ll sum=0;
       fitr(i,0,n){
          cin>>arr[i];
          mx=max(mx,arr[i]);
          sum+=arr[i];
       }
       ll val=sum/(n-1);
       if(sum%(n-1)) val++;
       val=max(val,(ll)mx);
       ll ans=val*(n-1)-sum;
       print(ans);
}
int main() { 
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
std::cout << std::fixed;
std::cout << std::setprecision(11);
int t;
t=1;
cin>>t;
//int i=1;
while(t--){
   // cout<<"Case #"<<i<<": ";
    solve();
    //i++;
}
return 0;
} 


