#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
const int N = 100010;
int n, m, k, ans;
int c[N], t[N];
int res = 0;
int l, r;
priority_queue<pair<int, int>> q;
int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i] >> c[i];
        q.emplace(t[i], i);
    }
    ans = q.top().first;
    while (!q.empty() && ans > k) {
        pair<int, int> p = q.top();
        q.pop();
        if (c[p.second] <= m) {
            ans = p.first - 1;
            q.emplace(p.first - 1, p.second);
            m -= c[p.second];
            continue;
        }
        if (c[p.second] > m) {
            ans = p.first;
            break;
        }
    }
    cout << ans << endl;
}
