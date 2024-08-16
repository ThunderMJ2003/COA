#include <bits/stdc++.h>
#include <windows.h>
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
    LARGE_INTEGER freq;
    LARGE_INTEGER start, end;
    QueryPerformanceFrequency(&freq);
    vector<double> times;
    double total_time = 0;
    for (int x=0; x<10; x++){
        QueryPerformanceCounter(&start);
        int n = 50;
        for (int i=0; i<n; i++){
            printf("fibo(%d) = %lld \n", i+1, fibo(i+1));
        }
        QueryPerformanceCounter(&end);
        double time_taken = static_cast<double>(end.QuadPart - start.QuadPart) / freq.QuadPart;
        times.push_back(time_taken);
        total_time += time_taken;
    }
    printf("All times: \n");
    for (int x=0; x<10; x++){
        printf("%f ", times[x]);
    }
    printf("\n");
    printf("Average time = %f \n", total_time/10.0);
    return 0;
}