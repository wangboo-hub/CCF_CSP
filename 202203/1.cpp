// 题目：http://118.190.20.162/view.page?gpid=T143
#include <iostream>
#include <cstdio>
#include <set>
#define test
using namespace std;

int main(){
#ifdef test
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int n,k;cin>>n>>k;
    set<int> s;
    s.insert(0);
    int ans=0;
    for(int i=0;i<k;++i){
        int x,y;cin>>x>>y;
        if(s.find(y) == s.end())++ans;
        s.insert(x);
    }
    cout<<ans<<endl;
}