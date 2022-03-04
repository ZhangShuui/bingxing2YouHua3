#include <iostream>
#include <windows.h>
using  namespace std;
int a[100000];
int sum=0;
void countAll(int n){
    sum=0;
    for (int i = n; i>1 ; i/=2) {
        for (int j = 0; j < i/2; ++j) {
            a[j] = a[2*j] +a[2*j+1];     //想象为二叉树的结构，每次将两个子节点求和到父节点
        }
    }
    sum =a[0];
}
void reBoot(){
    for (int i = 0; i < 100000; ++i) {
        a[i]=i%10;
    }
}
int main() {
    int n=2;
    long long freq,start,end;
    QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
    while(n<100000){
        reBoot();
        int counter=0;
        QueryPerformanceCounter((LARGE_INTEGER*)&start);
        QueryPerformanceCounter((LARGE_INTEGER*)&end);
        while(end-start<100000){
            countAll(n);
            counter++;
            QueryPerformanceCounter((LARGE_INTEGER*)&end);
        }
        float seconds=float (end-start)/float (freq);
        cout<<n<<","<<counter<<","<<seconds<<","<<seconds/double (counter)<<endl;
        n*=2;
    }
    return 0;
}

