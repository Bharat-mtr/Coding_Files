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

vector<int>seg;
void update(int node,int n_l,int n_h, int q_l, int q_h,int val){
   if(q_l<=n_l && n_h<=q_h){
       seg[node]^=val;
       return;
   }
   if(q_h<n_l || n_h<q_l){
     return;
   }
   int mid=(n_l+n_h)/2;
   update(2*node,n_l,mid,q_l,q_h,val);
   update(2*node+1,mid+1,n_h,q_l,q_h,val);
}
void solve(){
    int q;
    cin>>q;
    int m=q;
    if(__builtin_popcount(q)!=1){
        m=pow(2,(int)log2(q)+1);
    }
    seg=vector<int>(2*m);
    fitr(i,0,2*m){
       seg[i]=0;
    }    
    int t,val;
    int len=1;
    while(q--){
        cin>>t>>val;
        if(t==1){
           len++;
           update(1,1,m,len,len,val);
        }
        else{
           update(1,1,m,1,len,val);
        }
    }
    fitr(i,1,m){
        seg[2*i]^=seg[i];
        seg[2*i+1]^=seg[i];
    }
    vector<int>v;
    fitr(i,0,len){
       v.pb(seg[m+i]);
    }
    sort(rangeitr(v));
    fitr(i,0,len){
       cout<<v[i]<<" ";
    }
    print("");
}
int main() { 
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
std::cout << std::fixed;
std::cout << std::setprecision(11);
int t;
t=1;
//cin>>t;
//int i=1;
while(t--){
   // cout<<"Case #"<<i<<": ";
    solve();
    //i++;
}
return 0;
} 