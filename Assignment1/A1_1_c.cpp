#include <bits/stdc++.h>
using namespace std;

long long fibo(int n, vector<long long>& fibonum){
    if (fibonum[n-1] != -1){
        return fibonum[n-1];
    }
    if ((n==1) || (n==2)){
        fibonum[n-1] = n-1;
        return fibonum[n-1];
    }
    fibonum[n-1] = fibo(n-1, fibonum) + fibo(n-2, fibonum);
    return fibonum[n-1];
}

int main(){
    int n = 50;
    vector<long long> fibonum(n, -1);
    for (int i=0; i<n; i++){
        printf("fibo(%d) = %lld \n", i+1, fibo(i+1, fibonum));
        printf("\n");
    }
    return 0;
}