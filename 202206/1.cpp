// 题目：http://118.190.20.162/view.page?gpid=T148
#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

const int maxn = 1010;
double a[maxn];
double mean(double *arr, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

double std_dev(double *arr, int n,double mean_) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (arr[i] - mean_) * (arr[i] - mean_);
    }
    return sqrt(sum / n);
}

void normolize(double *arr, int n) {
    double mean_ = mean(arr, n);
    double std_dev_ = std_dev(arr, n, mean_);
    for (int i = 0; i < n; i++)
        cout<<(arr[i] - mean_) / std_dev_<<endl;

}

int main(){

    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    normolize(a,n);

}