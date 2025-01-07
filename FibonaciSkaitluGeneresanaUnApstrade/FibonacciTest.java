public class FibonacciTest {
    public static void main(String[] args) {
        // Start time measurement
        long startTime = System.currentTimeMillis();

        // Generate Fibonacci sequence
        int n = 30;
        int[] fiboSeq = new int[n];
        for (int i = 0; i < n; i++) {
            fiboSeq[i] = fibonacci(i);
        }

        // End time measurement
        long endTime = System.currentTimeMillis();
        long duration = endTime - startTime;
        System.out.println("Execution time: " + duration + " ms");

        // Get memory usage
        Runtime runtime = Runtime.getRuntime();
        long currentMemoryUsage = runtime.totalMemory() - runtime.freeMemory();
        System.out.println("Current memory usage: " + currentMemoryUsage / (1024 * 1024) + " MB");
        System.out.println("Peak memory usage: " + runtime.totalMemory() / (1024 * 1024) + " MB");
    }

    public static int fibonacci(int n) {
        if (n <= 1) {
            return n;
        }
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
