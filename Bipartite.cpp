#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll>v[100005],rv[100005];
stack<int>s ;
queue<ll>q;
ll visited[100005]={0};
ll visited1[100005]={0};
ll recstack[1003]{0};
ll dist[100005];
void transpose(ll n)
{
    ll i,j;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<v[i].size();j++)
        {
            rv[v[i][j]].push_back(i);
        }
    }
}

void dfs1(ll u)
{
    ll i;
    visited1[u]=1;
    //cout<<u<<" ";
    for(i=0;i<rv[u].size();i++)
    {
        if(visited1[rv[u][i]]==0)
            dfs1(rv[u][i]);
    }
}


void dfs(ll u)
{
    ll i;
    visited[u]=1;
    for(i=0;i<v[u].size();i++)
    {
        if(visited[v[u][i]]==0)
            dfs(v[u][i]);
    }
    s.push(u);
}

ll solvedist(ll u)
{
    ll i;
    for(i=0;i<100005;i++)
        dist[i]=-1;
    visited[u]=1;
    dist[u]=1;
    q.push(u);
    while(!q.empty())
    {
        ll d=q.front();
        q.pop();
        for(i=0;i<v[d].size();i++)
        {
            if(visited[v[d][i]]==0&&dist[v[d][i]]==-1)
            {
                dist[v[d][i]]=1-dist[d];
                q.push(v[d][i]);
                visited[v[d][i]]=1;
            }
            else
            {
                if(visited[v[d][i]]==0&&dist[v[d][i]]==dist[d])
                    return 0;
                if(visited[v[d][i]]==1&&dist[v[d][i]]==dist[d])
                    return 0;
            }
        }
    }
    return 1;
}

int main()
{
    ll n,m,i,j,k,l,u,vx,x,y,c=0,flag=0;
    cin>>n>>m;

    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        if(x==y)
            flag=1;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    cin>>u>>vx;
    k=solvedist(1);

    if(flag==1)
    {
        cout<<0;
        return 0;
    }
    //cout<<endl;
    cout<<k;
    return 0;
}
