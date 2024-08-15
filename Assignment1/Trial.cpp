#include <bits/stdc++.h>
using namespace std;

void foo(int n, vector<int>& v){
    v[n] = 0;
}

int main(){
    vector<int> t(10, -1);
    foo(4, t);
    for (int i=0; i<10; i++){
        printf("%d ", t[i]);
    }
    return 0;
}