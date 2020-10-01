#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll>v[1003],s;
ll visited[1003]={0};
void dfs(ll u)
{
    ll i,j;
    visited[u]=1;
    s.push_back(u);
    for(i=0;i<v[u].size();i++)
    {
        if(visited[v[u][i]]==0)
        {
            dfs(v[u][i]);
        }
    }
}

int main()
{
    ll n,m,i,j,k,l,u,vx,x,y,c=0;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cin>>u>>vx;
    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            c++;
            dfs(i);
        }
    }
    cout<<c;
    return 0;
}