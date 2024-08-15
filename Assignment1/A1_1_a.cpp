#include <bits/stdc++.h>
using namespace std;

long long fibo(int n){
    if ((n==1) || (n==2)){
        return (n-1);
    }
    return fibo(n-1) + fibo(n-2);
}

int main(){
    int n = 50;
    for (int i=0; i<n; i++){
        printf("fibo(%d) = %lld \n", i+1, fibo(i+1));
    }
    return 0;
}