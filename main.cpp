#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;
int n;
unordered_map<int, unordered_map<int, set<int>>> users;
unordered_map<int, set<int>> attrName;
int id, cnt, x, y;
int m;
set<int> atom(string s) {
    set<int> res;
    int t = 0;
    while (s[t] != ':' && s[t] != '~') {
        t++;
    }
    int idx = stoi(s.substr(0, t));
    char op = s[t];
    int num = stoi(s.substr(t + 1, s.size() - t - 1));
    if (op == ':') {
        res.insert(users[idx][num].begin(), users[idx][num].end());
    } else {
        set<int> temp;
        res.insert(attrName[idx].begin(), attrName[idx].end());
        for (auto it: users[idx][num]) {

            if (res.count(it)) {
                temp.insert(it);
            }
        }
        for (auto it: temp) {
            res.erase(it);
        }
    }
    return res;
}
set<int> exper(string s) {
    set<int> ret;
    if (s[0] >= '0' && s[0] <= '9') {
        ret = atom(s);
    } else {
        stack<char> st;
        int p = 1;
        st.push('(');
        while (!st.empty()) {
            ++p;
            if (s[p] == '(') {
                st.push(s[p]);
            } else if (s[p] == ')') {
                st.pop();
            }
        }
        string s1 = s.substr(2, p - 2);
        string s2 = s.substr(p + 2, s.size() - p - 3);
        set<int> res1 = exper(s1);
        set<int> res2 = exper(s2);
        if (s[0] == '|') {
            ret.insert(res1.begin(), res1.end());
            ret.insert(res2.begin(), res2.end());
        } else {
            //  求交集
            for (auto it: res1) {
                if (res2.find(it) != res2.end()) {
                    ret.insert(it);
                }
            }
        }
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> id >> cnt;
        for (int j = 0; j < cnt; j++) {
            cin >> x >> y;
            users[x][y].insert(id);
            attrName[x].insert(id);
        }
    }
    cin >> m;
    string op;
    while (m--) {
        cin >> op;
        set<int> res = exper(op);
        for (auto it: res) {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}
