//#include <iostream>
//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <set>
//#include <cassert>
//#define test
//using namespace std;
//
//struct node {
//    int id, area;
//    bool run;
//    int appid;
//};
//
//struct area {
//    int id, sum;
//    int running;
//    set<int> inodes;
//    set<int> unused;
//
//};
//
//struct app {
//    int id;
//    set<int> inodes;
//};
//
//int main() {
//#ifdef test
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif
//    int n, m;
//    cin >> n >> m;
//    vector<node> nodes(n);
//    set<int> unused;
////    for(int i=0;i<n;i++){
////        cin>>nodes[i].id;
////        nodes[i].run=false;
////    }
//    vector<area> areas(m);
//    for (int i = 0; i < n; i++) {
//        unused.insert(i);
//        int t;
//        cin >> t;
//        nodes[i].id = i;
//        nodes[i].area = t;
//        areas[t].id = t;
//        areas[t].sum++;
//        areas[t].inodes.insert(nodes[i].id);
//        areas[t].unused.insert(nodes[i].id);
//
//    }
//    int g;
//    cin >> g;
//    vector<app> apps(g);
//    for (int i = 0; i < g; i++) {
////        assert(i==2);
//        int f;
//        cin >> f;
//        int a;
//        cin >> a;
//        apps[i].id = a;
//        int p1, p2, p3, p4;
//        cin >> p1 >> p2 >> p3>>p4;
//        if (p1 > 0) {
//            assert(false);
//            for (int j = 0; j < n; j++) {
//                const int idx = p1;
//                if (!areas[idx].unused.empty()) {
//                    int k = 1;
//                    for (k = 1; k <= f; ++k) {
//
//                        cout << id + 1 << " ";
//                    }
//                    while (k++ > f)cout << "0 ";
//                    cout << endl;
//                }else{
//                    while(f-- > 0)cout << "0 ";
//                    cout << endl;
//                }
//
//            }
//            }else{
//                int j=0;
//                for(j=0;j<f;j++){
//                    if(unused.empty())break;
//                    int id = *unused.begin();
//                    nodes[id].appid = a;
//                    unused.erase(id);
//                    areas[nodes[id].area].unused.erase(id);
//                    nodes[id].run = true;
//                    apps[i].inodes.insert(id);
//                    cout << id + 1 << " ";
//                }
//
//                while(j++ < f){
////                    cout<<j<<endl;
//                    cout << "0 ";
//                }
//                cout << endl;
//        }
//
//    }
//}