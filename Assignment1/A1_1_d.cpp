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
    fibonum[n-1] = fibonum[n-2] + fibonum[n-3];
    return fibonum[n-1];
}

int main(){
    int n = 50;
    vector<long long> fibonum(n, -1);
    for (int i=0; i<n; i++){ //this loop works to calculate the new values too
        printf("fibo(%d) = %lld \n", i+1, fibo(i+1, fibonum));
    }
    return 0;
}