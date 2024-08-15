#include <bits/stdc++.h>
using namespace std;

long long fibo(int n){
    if ((n==1) || (n==2)){
        return (n-1);
    }
    long long a = 0, b = 1;
    long long c = a + b;
    for (int i=0; i<(n-2); i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main(){
    int n = 50;
    for (int i=0; i<n; i++){
        printf("fibo(%d) = %lld \n", i+1, fibo(i+1));
    }
    return 0;
}