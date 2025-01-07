#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <psapi.h>

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n = 10000;
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    srand(time(0));

    // Populating the array with random values
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }

    // Start time measurement
    clock_t start = clock();

    bubble_sort(arr, n);

    // End time measurement
    clock_t end = clock();
    double duration = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Execution time: %.2f ms\n", duration);

    // Get memory usage
    PROCESS_MEMORY_COUNTERS memCounter;
    GetProcessMemoryInfo(GetCurrentProcess(), &memCounter, sizeof(memCounter));
    printf("Current memory usage: %ld MB\n", memCounter.WorkingSetSize / 1024 / 1024);
    printf("Peak memory usage: %ld MB\n", memCounter.PeakWorkingSetSize / 1024 / 1024);

    // Free allocated memory
    free(arr);

    return 0;
}
