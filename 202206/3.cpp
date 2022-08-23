#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#define test
using namespace std;

struct user {
    string name;
    set<string> groups;
};

struct group {
    string name;
    set<string> users;
};

struct role {
    string name;
    set<string> ops;
    set<string> kinds;
    set<string> names;
    set<string> users;
    set<string> groups;
};

struct role_relation {
    string name;
    set<string> users;
    set<string> groups;
};

int main(){
#ifdef test
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n,m,q;cin>>n>>m>>q;
    vector<role> roles(n);
    map<string,int> role_index;
    for (int i = 0; i < n; ++i) {
        cin>>roles[i].name;
        role_index[roles[i].name] = i;
        int nv;cin>>nv;
        for (int j = 0; j < nv; ++j) {
            string op;cin>>op;
            roles[i].ops.insert(op);
        }
        int no;cin>>no;
        for (int j = 0; j < no; ++j) {
            string kind;cin>>kind;
            roles[i].kinds.insert(kind);
        }
        int nn;cin>>nn;
        for (int j = 0; j < nn; ++j) {
            string name;cin>>name;
            roles[i].names.insert(name);
        }
    }
//    vector<role_relation> role_relations(m);
    for (int i = 0; i < m; ++i) {
        string name;cin>>name;

        int ns;cin>>ns;
        for (int j = 0; j < ns; ++j) {
            char c;cin>>c;
            string uname;cin>>uname;
            if(c=='u')roles[role_index[name]].users.insert(uname);
            else roles[role_index[name]].groups.insert(uname);
        }
    }
    set<user> users;

    for (int i = 0; i < q; ++i) {
        user tmp;
        cin>>tmp.name;
        int ng;cin>>ng;
        for (int j = 0; j < ng; ++j) {
            string group;cin>>group;
            tmp.groups.insert(group);
        }
        string op,kind,name;
        cin>>op>>kind>>name;
        bool flag = false;
        for(auto item:roles){
            if(flag)break;
            if(item.ops.count(op) == 0 && item.ops.count("*") == 0){
//                assert(item.ops.count(op) != 0);
//                cout<<"0"<<endl;
//                break;
                continue;
            } else if(item.kinds.count(kind) == 0 && item.kinds.count("*") == 0){
//                cout<<op<<endl;
//                for(auto k:item.kinds)cout<<k<<endl;
//                assert(false);
//                cout<<"0"<<endl;
                continue;
            } else if(item.names.size()!=0 && item.names.count(name) == 0){
//                assert(item.names.size() == 0);

//                cout<<"0"<<endl;
                continue;
//                break;
            } else if(item.users.count(tmp.name) == 0){

                for(auto g:tmp.groups){

                    if(item.groups.count(g)){
                        flag = true;
                        break;
                    }
                }
//                if(!flag){cout<<"0"<<endl;
//                break;

            }else{
                flag = true;
//                cout<<"1"<<endl;
                break;
            }

        }
        if(flag)cout<<"1"<<endl;
        else cout<<"0"<<endl;
//        cout<<i<<":"<<endl;
    }
}