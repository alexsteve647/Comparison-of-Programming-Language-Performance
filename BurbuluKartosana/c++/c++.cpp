#include <iostream>
#include <vector>
#include <chrono>
#include <windows.h>
#include <psapi.h>

using namespace std;
using namespace std::chrono;

void bubble_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    // Create a large dataset
    vector<int> arr(10000);
    for (int i = 0; i < 10000; i++) {
        arr[i] = 10000 - i;
    }

    // Start time measurement
    auto start = high_resolution_clock::now();
    bubble_sort(arr);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " ms" << endl;

    // Get memory usage
    PROCESS_MEMORY_COUNTERS memCounter;
    GetProcessMemoryInfo(GetCurrentProcess(), &memCounter, sizeof(memCounter));
    cout << "Current memory usage: " << memCounter.WorkingSetSize / 1024 / 1024 << " MB" << endl;
    cout << "Peak memory usage: " << memCounter.PeakWorkingSetSize / 1024 / 1024 << " MB" << endl;

    return 0;
}
