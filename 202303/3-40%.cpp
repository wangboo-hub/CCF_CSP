#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>

using namespace std;
int n;
struct User {
    int dn, num;
    map<int, int> attr;
};
map<int, User> users;
int id, cnt, x, y;
int m;
set<int> check(int id, int num, char op) {
    set<int> res;
    if (op == ':') {
        for (auto it: users) {
            if (it.second.attr[id] == num) {
                res.insert(it.first);
            }
        }
    } else {
        for (auto it: users) {
            if (it.second.attr[id] != num && it.second.attr[id] != 0) {
                res.insert(it.first);
            }
        }
    }
    return res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> id >> cnt;
        users[id].dn = id;
        users[id].num = cnt;
        for (int j = 0; j < cnt; j++) {
            cin >> x >> y;
            users[id].attr[x] = y;
        }
    }
    cin >> m;
    string op;

    while (m--) {
        set<int> res;
        int id1 = 0, num1 = 0, id2 = 0, num2 = 0;
        cin >> op;
        char c = op[0];
        if (c == '|' || c == '&') {
            int i = 2;
            for (i = 2;; ++i) {
                if (op[i] >= '0' && op[i] <= '9') {
                    id1 = id1 * 10 + op[i] - '0';
                } else {
                    break;
                }
            }
            char op1 = op[i];
            for (i = i + 1;; ++i) {
                if (op[i] >= '0' && op[i] <= '9') {
                    num1 = num1 * 10 + op[i] - '0';
                } else {
                    break;
                }
            }

            i += 2;
            for (;; ++i) {
                if (op[i] >= '0' && op[i] <= '9') {
                    id2 = id2 * 10 + op[i] - '0';
                } else {
                    break;
                }
            }
            char op2 = op[i];
            for (i = i + 1;; ++i) {
                if (op[i] >= '0' && op[i] <= '9') {
                    num2 = num2 * 10 + op[i] - '0';
                } else {
                    break;
                }
            }
            set<int> u1 = check(id1, num1, op1);
            set<int> u2 = check(id2, num2, op2);
            if (c == '|') {

                set_union(u1.begin(), u1.end(), u2.begin(), u2.end(),
                          inserter(res, res.begin()));

            } else {

                set_intersection(u1.begin(), u1.end(), u2.begin(), u2.end(),
                                 inserter(res, res.begin()));
            }
        } else {
            int i = 0;
            for (i = 0;; ++i) {
                if (op[i] >= '0' && op[i] <= '9') {
                    id1 = id1 * 10 + op[i] - '0';
                } else {
                    break;
                }
            }
            char op1 = op[i];
            for (i = i + 1;; ++i) {
                if (op[i] >= '0' && op[i] <= '9') {
                    num1 = num1 * 10 + op[i] - '0';
                } else {
                    break;
                }
            }
            res = check(id1, num1, op1);
        }
        for (auto it: res) {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}
