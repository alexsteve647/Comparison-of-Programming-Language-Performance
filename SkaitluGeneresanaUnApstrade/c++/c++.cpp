#include <iostream>
#include <vector>
#include <chrono>
#include <windows.h>
#include <psapi.h>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

int main() {
    // Start memory measurement
    PROCESS_MEMORY_COUNTERS memCounter;
    GetProcessMemoryInfo(GetCurrentProcess(), &memCounter, sizeof(memCounter));
    size_t start_memory = memCounter.WorkingSetSize;

    // Start time measurement
    auto start = high_resolution_clock::now();

    // Generate and process a large set of numbers
    vector<int> numbers(1000000);
    for (int i = 0; i < 1000000; ++i) {
        numbers[i] = rand() % 1000000;
    }

    vector<int> even_numbers;
    for (int num : numbers) {
        if (num % 2 == 0) {
            even_numbers.push_back(num);
        }
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
