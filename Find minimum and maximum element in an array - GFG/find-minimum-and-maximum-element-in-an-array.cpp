// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<long long, long long> getMinMax(long long a[], int n) ;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        pair<ll, ll> pp = getMinMax(a, n);

        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}// } Driver Code Ends


pair<long long, long long> getMinMax(long long a[], int n) {
    long long m1=a[0],m2=a[0];
    
    for(int i=1;i<n;i++)
    {
        if(a[i]>m1)
        {
            m1=a[i];
        }
        if(a[i]<m2)
        {
            m2=a[i];
        }
    }
    pair<long long,long long> p;
    p.first = m2;
    p.second = m1;
    return p;
    
}