//差分数组
#include <iostream>

using namespace std;
using ll = long long;

const int N = 5e6 + 50;
int a[N];
int d[N];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, p;
    cin >> n >> p;
    for(ll i = 1; i <= n; i ++)
        cin >> a[i];
    for(ll i = 1; i <= n; i ++)
        d[i] = a[i] - a[i-1];
    for(ll i = 0; i < p; i ++){
        int x, y, z;
        cin >> x >> y >> z;
        d[x] += z;
        d[y+1] -= z;
    }
    int sum = 0;
    int min = 1e5;
    for(ll i = 1; i <= n; i ++)
    {
        a[i] = a[i-1] + d[i];
        if(min > a[i])   min = a[i];
    }
    cout << min << '\n';
    return 0;
}