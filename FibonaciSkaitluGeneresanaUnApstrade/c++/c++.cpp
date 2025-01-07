#include <iostream>
#include <vector>
#include <chrono>
#include <windows.h>
#include <psapi.h>

using namespace std;
using namespace std::chrono;

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    // Start memory measurement
    PROCESS_MEMORY_COUNTERS memCounter;
    GetProcessMemoryInfo(GetCurrentProcess(), &memCounter, sizeof(memCounter));
    size_t start_memory = memCounter.WorkingSetSize;

    // Start time measurement
    auto start = high_resolution_clock::now();

    // Generate Fibonacci sequence
    vector<int> fibo_seq(30);
    for (int i = 0; i < 30; ++i) {
        fibo_seq[i] = fibonacci(i);
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " ms" << endl;

    // Get memory usage
    GetProcessMemoryInfo(GetCurrentProcess(), &memCounter, sizeof(memCounter));
    cout << "Current memory usage: " << (memCounter.WorkingSetSize - start_memory) / 1024 / 1024 << " MB" << endl;
    cout << "Peak memory usage: " << memCounter.PeakWorkingSetSize / 1024 / 1024 << " MB" << endl;

    return 0;
}
