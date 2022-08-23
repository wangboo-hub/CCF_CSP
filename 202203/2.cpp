// 题目：http://118.190.20.162/view.page?gpid=T142
#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>
#define test
using namespace std;

const int maxn = 200000 + 10;
int ans[maxn];

int main(){
#ifdef test
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,m,k;cin>>n>>m>>k;
    for(int i=0;i<n;++i){
        int t,c;cin>>t>>c;
        if((t-k)<=0)continue;
        ++ans[max(t-k-c+1,1)];
        --ans[t-k+1];
    }

    for(int i=1;i<maxn;++i)ans[i]+=ans[i-1];
    for(int i=0;i<m;++i){
        int q;cin>>q;
        cout<<ans[q]<<endl;
    }
}