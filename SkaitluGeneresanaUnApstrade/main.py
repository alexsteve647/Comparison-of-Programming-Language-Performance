import time
import tracemalloc
import random

n = 1000000

# Start memory measurement
tracemalloc.start()
start = time.time()

# Generate a large set of random numbers
numbers = [random.randint(0, 1000000) for _ in range(n)]

# Process the numbers (e.g., filter even numbers)
even_numbers = [num for num in numbers if num % 2 == 0]

end = time.time()

# Get memory usage
current, peak = tracemalloc.get_traced_memory()
print(f"Execution time: {(end - start) * 1000} ms")
print(f"Current memory usage: {current / 10**6} MB")
print(f"Peak memory usage: {peak / 10**6} MB")

tracemalloc.stop()
