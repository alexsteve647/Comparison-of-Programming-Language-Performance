#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <psapi.h>

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
    clock_t start = clock();

    // Generate Fibonacci sequence
    int n = 30;
    int* fibo_seq = (int*)malloc(n * sizeof(int));
    if (fibo_seq == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        fibo_seq[i] = fibonacci(i);
    }

    // End time measurement
    clock_t end = clock();
    double duration = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Execution time: %.2f ms\n", duration);

    // Get memory usage
    GetProcessMemoryInfo(GetCurrentProcess(), &memCounter, sizeof(memCounter));
    printf("Current memory usage: %ld MB\n", (memCounter.WorkingSetSize - start_memory) / 1024 / 1024);
    printf("Peak memory usage: %ld MB\n", memCounter.PeakWorkingSetSize / 1024 / 1024);

    // Free allocated memory
    free(fibo_seq);

    return 0;
}
