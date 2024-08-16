#include <bits/stdc++.h>
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
    srand(static_cast<unsigned>(time(0)));
    int n = 1024;
    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            A[i][j] = (rand()%10); //Initializing matrix with random single digit number
            B[i][j] = (rand()%10);
        }
    }
    vector<vector<int>> C = matmult(A, B);
    printf("A = \n");
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("B = \n");
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    printf("A = \n");
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}