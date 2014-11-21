#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int w[100001];

int main() {
    int n;
    cin>>n;
    for (int i=0;i<n;i++) cin>>w[i];
    sort(w,w+n);
    int count=0;
    int i=0;
    while (i<n)
    {
        count++;
        int x=w[i]+4;
        while (i<n && w[i]<=x)
            i++;
    }
    cout<<count<<endl;
    return 0;
}
