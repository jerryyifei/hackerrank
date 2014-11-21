#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long a[100001];
int n;
    int mmax=0;

bool check(long long x)
{
    int flag=1;
    for (int i=1;i<=n;i++)
    {
        x=x+x-a[i];
        if (x>mmax) break;
        if (x<0)
        {
            flag=0;
            break;
        }
    }
  //  cout<<x<<endl;
    if (flag==1) return true;
    else return false;

}

int main() {
    cin>>n;
    mmax=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (mmax<a[i]) mmax=a[i];
    }

    int head=1;
    int rear=mmax;
    while (head<=rear)
    {
        long long mid=(head+rear)/2;
        if (check(mid)) rear=mid-1;
        else head=mid+1;
    }

    if (check(head-1)) cout<<head-1<<endl;
    else if (check(head)) cout<<head<<endl;
    else cout<<head+1<<endl;
    return 0;
}
