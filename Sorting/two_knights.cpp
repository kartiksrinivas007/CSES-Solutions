
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


int main()
{

    int n;
    cin >> n;

    for (int k = 1; k <= n; k++)
    {
        cout << (1ll * k*k * 1ll * (k*k - 1) / 2) - (4* 1ll * (k-1) * (k-2)) << endl;
    }     
}
