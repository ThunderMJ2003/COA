#include <bits/stdc++.h>
using namespace std;

vector<vector<double>> matmult(vector<vector<double>> A, vector<vector<double>> B){
    int n = A.size();
    vector<vector<double>> C(n, vector<double>(n));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            double curr_el = 0.0;
            for (int k=0; k<n; k++){
                curr_el += A[i][k] * B[k][j];
            }
            C[i][j] = curr_el;
        }
    }
    return C;
}

int main(){
    srand(static_cast<unsigned>(time(0)));
    int n = 256;
    vector<vector<double>> A(n, vector<double>(n));
    vector<vector<double>> B(n, vector<double>(n));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            A[i][j] = (rand()/(double)RAND_MAX)*10.0; //Initializing matrix with random number in [0, 10)
            B[i][j] = (rand()/(double)RAND_MAX)*10.0;
        }
    }
    vector<vector<double>> C = matmult(A, B);
    printf("A = \n");
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            printf("%f ", A[i][j]);
        }
        printf("\n");
    }
    printf("B = \n");
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            printf("%f ", B[i][j]);
        }
        printf("\n");
    }
    printf("A = \n");
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            printf("%f ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}