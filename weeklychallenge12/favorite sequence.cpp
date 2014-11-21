#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>
#include <string>
#include <string.h>
#include <queue>
using namespace std;


set <int> a[1000001];
int v[1000001];
int ind[1000001];
int node[1000001];
int main() {
    int n,k,x,y;
    int m=0;
    cin>>n;

    memset(v,0,sizeof(v));
    memset(ind,0,sizeof(ind));
    memset(node,0,sizeof(node));
    priority_queue<int,vector<int>,greater<int> > q;
    for (int i=1;i<=n;i++)
    {
        cin>>k;
        cin>>x;
        if (v[x]==0)
            {
                v[x]=1;
                m++;
                node[m]=x;
            }

        for (int j=2;j<=k;j++)
        {
            cin>>y;
            if (v[y]==0)
            {
                v[y]=1;
                m++;
                node[m]=y;
            }
            if  (a[x].find(y)==a[x].end())
            {
                a[x].insert(y);
            }
            x=y;
        }
    }
    for (int i=1;i<=m;i++)
    {
        set<int>::iterator pos;
        for (pos=a[node[i]].begin();pos!=a[node[i]].end();pos++)
        {
            ind[*pos]++;
        }
    }
  //  for (int i=1;i<=m;i++)
   // cout<<node[i]<<" "<<ind[i]<<endl;

    for (int i=1;i<=m;i++)
    {
        if (ind[node[i]]==0)
        {
        //    cout<<"push "<<node[i]<<endl;
            q.push(node[i]);
        }
    }

    int first=0;
    while (!q.empty())
    {
        int p=q.top();
        q.pop();
        if (first>0) cout<<" ";
        cout<<p;
        first++;
        set<int>::iterator pos;
        for (pos=a[p].begin();pos!=a[p].end();pos++)
        {
            ind[*pos]--;
            if (ind[*pos]==0)
            {
        //        cout<<"push "<<*pos<<endl;
                q.push(*pos);

            }
        }
    }
    return 0;
}
