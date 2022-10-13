
#include <bits/stdc++.h>
using namespace std;

vector<int> seg;
vector<int> arr;
int n;

void build(int node, int st, int end)
{
    if(st>end)
    {
        return ;
    }
    if(st==end)
    {
        seg[node] = arr[st];
        return;
    }

    int mid = (st+end)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,end);
    seg[node] = max(seg[2*node],seg[2*node+1]);
}

int query(int node, int st, int end, int l, int r)
{
    if(end<l || st > r)
    {
        return INT_MIN;
    }
    if(st>=l && end<= r)
    {
        return seg[node];
    }
    int mid = (st+end)/2;
    int left = query(2*node,st,mid,l,r);
    int right = query(2*node+1,mid+1,end,l,r);
    return max(left,right);
}

int solve(int l, int r, int x)
{
    if(l>r) return -1;
    while(l<= r)
    {
        int mid = (l+r)/2;
        if(l==r)
        {
            if(arr[l]>x) return arr[l];
            return -1;
        }

        if(query(1,0,n-1,l,mid)>x) r=mid;
        else l= mid+1;
    }
    return -1;
}

int main()
{
    cin>>n;
    arr.resize(n);
    seg.resize(4*n);

    for(int i=0; i<n ; i++)
    {
        cin>>arr[i];
    }

    stack<int> st;
    vector<int> temp(n);
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && arr[i]>= arr[st.top()])
        {
            st.pop();
        }
        if(st.empty())
        {
            temp[i] = -1;
        }
        else
        {
            temp[i] = st.top();
        }
        st.push(i);
    }

    build(1,0,n-1);
    vector<int> ans(n);
    for(int i=0;i<n;i++)
    {
        if(temp[i]==-1)
        {
            ans[i]=-1;
            continue;
        }

        int res = solve(temp[i]+1,n-1,arr[i]);
        ans[i] = res;
    }
    for(auto i: ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}