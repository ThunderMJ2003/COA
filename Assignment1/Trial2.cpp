#include <bits/stdc++.h>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Matrix multiplication function
vector<vector<int>> foo(vector<vector<int>> M1, vector<vector<int>> M2, int n) {
    vector<vector<int>> ans(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                ans[i][j] += M1[i][k] * M2[k][j];
            }
        }
    }
    return ans;
}

int main() {
    srand(static_cast<unsigned>(time(0))); // Seed random number generator

    auto start_total = high_resolution_clock::now(); // Start total execution time measurement

    int N = 64; // You can change this value to test other matrix sizes
    vector<vector<int>> M1(N, vector<int>(N));
    vector<vector<int>> M2(N, vector<int>(N));
    int p = N;

    // Initializing the M1 and M2 matrices
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < p; j++) {
            M1[i][j] = (rand() % 10) + 1;  // Random value between 1 and 10
            M2[i][j] = (rand() % 10) + 1;  // Random value between 1 and 10
        }
    }

    auto start_meat = high_resolution_clock::now(); // Start meat portion time measurement

    // Performing matrix multiplication
    vector<vector<int>> y = foo(M1, M2, p);

    auto end_meat = high_resolution_clock::now(); // End meat portion time measurement
    auto meat_duration = duration_cast<microseconds>(end_meat - start_meat).count();

    auto end_total = high_resolution_clock::now(); // End total execution time measurement
    auto total_duration = duration_cast<microseconds>(end_total - start_total).count();

    // Output timing information
    cout << "Meat Portion Time: " << meat_duration << " microseconds" << endl;
    cout << "Total Execution Time: " << total_duration << " microseconds" << endl;

    return 0;
}