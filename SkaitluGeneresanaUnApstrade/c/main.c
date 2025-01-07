#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <psapi.h>

int main() {
    // Start time measurement
    clock_t start = clock();

    // Generate a large set of random numbers
    int n = 1000000;
    int* numbers = (int*)malloc(n * sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    srand(time(0));
    for (int i = 0; i < n; i++) {
        numbers[i] = rand() % 1000000;
    }

    // Process the numbers (e.g., filter even numbers)
    int* even_numbers = (int*)malloc(n * sizeof(int));
    if (even_numbers == NULL) {
        printf("Memory allocation failed!\n");
        free(numbers);
        return 1;
    }

    int even_count = 0;
    for (int i = 0; i < n; i++) {
        if (numbers[i] % 2 == 0) {
            even_numbers[even_count++] = numbers[i];
        }
    }

    // End time measurement
    clock_t end = clock();
    double duration = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Execution time: %.2f ms\n", duration);

    // Get memory usage
    PROCESS_MEMORY_COUNTERS memCounter;
    GetProcessMemoryInfo(GetCurrentProcess(), &memCounter, sizeof(memCounter));
    printf("Current memory usage: %ld MB\n", (memCounter.WorkingSetSize - memCounter.PagefileUsage) / 1024 / 1024);
    printf("Peak memory usage: %ld MB\n", memCounter.PeakWorkingSetSize / 1024 / 1024);

    // Free allocated memory
    free(numbers);
    free(even_numbers);

    return 0;
}
