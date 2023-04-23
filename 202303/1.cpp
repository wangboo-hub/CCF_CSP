// http://118.190.20.162/view.page?gpid=T165
#include <cmath>
#include <iostream>
using namespace std;
int n, a, b;
int xa, xb, ya, yb;
int ans;
int main() {
    cin >> n >> a >> b;
    while (n--) {
        cin >> xa >> ya >> xb >> yb;
        xa = max(xa, 0);
        xb = min(xb, a);
        ya = max(ya, 0);
        yb = min(yb, b);
        if (xa > xb || ya > yb) continue;
        ans += (xb - xa) * (yb - ya);
    }
    cout << ans << endl;
    return 0;
}
