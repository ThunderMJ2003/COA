#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

vector<vector<int>> matmult(vector<vector<int>> A, vector<vector<int>> B){
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            int curr_el = 0;
            for (int k=0; k<n; k++){
                curr_el += A[i][k] * B[k][j];
            }
            C[i][j] = curr_el;
        }
    }
    return C;
}

int main(){
    LARGE_INTEGER meat_freq, exec_freq;
    LARGE_INTEGER meat_start, meat_end, exec_start, exec_end;
    QueryPerformanceFrequency(&exec_freq);
    QueryPerformanceCounter(&exec_start);
    srand(static_cast<unsigned>(time(0)));
    int n = 128;
    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            A[i][j] = (rand()%10); //Initializing matrix with random single digit number
            B[i][j] = (rand()%10);
        }
    }
    QueryPerformanceFrequency(&meat_freq);
    QueryPerformanceCounter(&meat_start);
    vector<vector<int>> C = matmult(A, B);
    QueryPerformanceCounter(&meat_end);
    double meat_time = static_cast<double>(meat_end.QuadPart - meat_start.QuadPart) / meat_freq.QuadPart;
    QueryPerformanceCounter(&exec_end);
    double exec_time = static_cast<double>(exec_end.QuadPart - exec_start.QuadPart) / exec_freq.QuadPart;
    cout << "Meat Time " << meat_time*1000000 << " us" << endl;
    cout << "Execution Time: " << exec_time*1000000 << " us" << endl;
    return 0;
}