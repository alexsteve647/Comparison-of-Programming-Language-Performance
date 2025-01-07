import java.util.Random;

public class BubbleSortTest {
    public static void main(String[] args) {
        int[] arr = new int[10000];
        Random rand = new Random();

        // Populate the array with random values
        for (int i = 0; i < arr.length; i++) {
            arr[i] = rand.nextInt(10000);
        }

        // Start time measurement
        long startTime = System.currentTimeMillis();

        bubbleSort(arr);

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

    public static void bubbleSort(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
}
