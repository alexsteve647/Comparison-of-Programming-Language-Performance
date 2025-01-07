import time
import tracemalloc

# Start memory measurement
tracemalloc.start()
start = time.time()

# Fibonacci function
def fibonacci(n):
    if n <= 1:
        return n
    else:
        return fibonacci(n-1) + fibonacci(n-2)

n = 30
fibo_seq = [fibonacci(i) for i in range(n)]

end = time.time()

# Get memory usage
current, peak = tracemalloc.get_traced_memory()
print(f"Execution time: {(end - start) * 1000} ms")
print(f"Current memory usage: {current / 10**6} MB")
print(f"Peak memory usage: {peak / 10**6} MB")

tracemalloc.stop()
