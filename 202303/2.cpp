// http://118.190.20.162/view.page?gpid=T164
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 100010;
int n, m, k;
int c[N], t[N];
int l, r;
int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i] >> c[i];
        r = max(r, t[i]);
    }
    l = k;
    while (l < r) {
        int mid = (l + r) >> 1;
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (t[i] >= mid)
                cnt += (t[i] - mid) * c[i];
        }
        if (cnt >= m)
            l = mid + 1;
        else
            r = mid;
    }
    cout << l << endl;
}