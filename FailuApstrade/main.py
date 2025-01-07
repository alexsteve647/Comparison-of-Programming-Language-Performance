import time
import tracemalloc

# Start memory measurement
tracemalloc.start()
start = time.time()

# Read and process a large file
with open("large_file.txt", "r") as file:
    for line in file:
        # Process each line (for example, just read it)
        pass

end = time.time()

# Get memory usage
current, peak = tracemalloc.get_traced_memory()
print(f"Execution time: {(end - start) * 1000} ms")
print(f"Current memory usage: {current / 10**6} MB")
print(f"Peak memory usage: {peak / 10**6} MB")

tracemalloc.stop()
