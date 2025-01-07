#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <windows.h>
#include <psapi.h>

using namespace std;
using namespace std::chrono;

int main() {
    // Start memory measurement
    PROCESS_MEMORY_COUNTERS memCounter;
    GetProcessMemoryInfo(GetCurrentProcess(), &memCounter, sizeof(memCounter));
    size_t start_memory = memCounter.WorkingSetSize;

    // Start time measurement
    auto start = high_resolution_clock::now();

    // Read and process a large file
    ifstream file("large_file.txt");
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " ms" << endl;

    // Get memory usage
    GetProcessMemoryInfo(GetCurrentProcess(), &memCounter, sizeof(memCounter));
    cout << "Current memory usage: " << (memCounter.WorkingSetSize - start_memory) / 1024 / 1024 << " MB" << endl;
    cout << "Peak memory usage: " << memCounter.PeakWorkingSetSize / 1024 / 1024 << " MB" << endl;

    return 0;
}
