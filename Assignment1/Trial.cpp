#include <iostream>
#include <windows.h>

void someFunction() {
    // Example function that just sleeps for 2 seconds
    Sleep(2); // Sleep for 2000 milliseconds (2 seconds)
}

int main() {
    LARGE_INTEGER frequency;        // Stores the frequency of the performance counter
    LARGE_INTEGER start, end;       // Stores the starting and ending counts

    // Get the frequency of the performance counter
    QueryPerformanceFrequency(&frequency);

    // Get the starting count
    QueryPerformanceCounter(&start);

    // Call the function whose execution time you want to measure
    someFunction();

    // Get the ending count
    QueryPerformanceCounter(&end);

    // Calculate the time taken in seconds
    double time_taken = static_cast<double>(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    std::cout << "Time taken by someFunction: " << time_taken << " seconds" << std::endl;

    return 0;
}
