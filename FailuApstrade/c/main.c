#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <psapi.h>

int main() {
    // Start memory measurement
    PROCESS_MEMORY_COUNTERS memCounter;
    GetProcessMemoryInfo(GetCurrentProcess(), &memCounter, sizeof(memCounter));
    size_t start_memory = memCounter.WorkingSetSize;

    // Start time measurement
    clock_t start = clock();

    // Read and process a large file
    FILE* file = fopen("large_file.txt", "r");
    if (file == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // Process each line (for example, just read it)
    }
    fclose(file);

    // End time measurement
    clock_t end = clock();
    double duration = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Execution time: %.2f ms\n", duration);

    // Get memory usage
    GetProcessMemoryInfo(GetCurrentProcess(), &memCounter, sizeof(memCounter));
    printf("Current memory usage: %ld MB\n", (memCounter.WorkingSetSize - start_memory) / 1024 / 1024);
    printf("Peak memory usage: %ld MB\n", memCounter.PeakWorkingSetSize / 1024 / 1024);

    return 0;
}
