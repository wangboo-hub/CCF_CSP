// 题目：http://118.190.20.162/view.page?gpid=T147
#include <iostream>
#include <cstdio>
#include <set>

#define test
using namespace std;

int b[55][55];
set<pair<int, int>> s;

int main() {
#ifdef test
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int n, L, S;
    cin >> n >> L >> S;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        s.insert({x, y});
    }
    for (int i = S; i >= 0; --i)
        for (int j = 0; j <= S; ++j)
            cin >> b[i][j];


    int ans = 0;
    for (auto item: s) {
        int x = item.first;
        int y = item.second;
        bool flag = true;
        for (int i = 0; i <= S; ++i) {
            for (int j = 0; j <= S; ++j) {
                if (b[i][j] == 1) {
                    if ((x + i) > L || (y + j) > L ||
                        s.find({x + i, y + j}) == s.end()) {
                        flag = false;
                        break;
                    }
                } else {
                    if ((x + i) > L || (y + j) > L ||
                        s.find({x + i, y + j}) != s.end()) {
                        flag = false;
                        break;
                    }
                }
            }
        }
        if (flag) ++ans;
    }
    cout << ans << endl;
}