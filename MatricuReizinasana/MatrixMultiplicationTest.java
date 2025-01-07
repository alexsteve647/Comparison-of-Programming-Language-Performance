import java.util.Random;

public class MatrixMultiplicationTest {
    public static void main(String[] args) {
        int n = 500; // Size of the matrices
        int[][] A = new int[n][n];
        int[][] B = new int[n][n];
        int[][] C = new int[n][n];
        Random rand = new Random();

        // Initialize matrices A and B with random values
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = rand.nextInt(100);
                B[i][j] = rand.nextInt(100);
            }
        }

        // Start time measurement
        long startTime = System.currentTimeMillis();

        // Perform matrix multiplication
        matrixMultiplication(A, B, C, n);

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

    public static void matrixMultiplication(int[][] A, int[][] B, int[][] C, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                C[i][j] = 0;
                for (int k = 0; k < n; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    }
}
