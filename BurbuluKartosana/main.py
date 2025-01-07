import time
import tracemalloc

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

# Create a large dataset
arr = [i for i in range(10000, 0, -1)]

# Start memory measurement
tracemalloc.start()
start = time.time()

bubble_sort(arr)

end = time.time()

# Get memory usage
current, peak = tracemalloc.get_traced_memory()
print(f"Execution time: {(end - start) * 1000} ms")
print(f"Current memory usage: {current / 10**6} MB")
print(f"Peak memory usage: {peak / 10**6} MB")

tracemalloc.stop()
