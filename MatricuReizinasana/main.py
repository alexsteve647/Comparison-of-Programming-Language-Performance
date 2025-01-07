import time
import tracemalloc
import numpy as np

n = 500

# Generate two random matrices
A = np.random.randint(0, 100, size=(n, n))
B = np.random.randint(0, 100, size=(n, n))

# Start memory measurement
tracemalloc.start()
start = time.time()

# Perform matrix multiplication
C = np.dot(A, B)

end = time.time()

# Get memory usage
current, peak = tracemalloc.get_traced_memory()
print(f"Execution time: {(end - start) * 1000} ms")
print(f"Current memory usage: {current / 10**6} MB")
print(f"Peak memory usage: {peak / 10**6} MB")

tracemalloc.stop()
