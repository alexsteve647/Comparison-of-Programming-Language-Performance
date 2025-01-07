import java.util.ArrayList;
import java.util.Random;

public class NumberGenerationTest {
    public static void main(String[] args) {
        // Start time measurement
        long startTime = System.currentTimeMillis();

        // Generate a large set of random numbers
        int[] numbers = new int[1000000];
        Random rand = new Random();
        for (int i = 0; i < numbers.length; i++) {
            numbers[i] = rand.nextInt(1000000);
        }

        // Process the numbers (e.g., filter even numbers)
        ArrayList<Integer> evenNumbers = new ArrayList<>();
        for (int num : numbers) {
            if (num % 2 == 0) {
                evenNumbers.add(num);
            }
        }

        // End time measurement
        long endTime = System.currentTimeMillis();
        long duration = endTime - startTime;
        System.out.println("Execution time: " + duration + " ms");

        // Get memory usage
        Runtime runtime = Runtime.getRuntime();
        long currentMemoryUsage = runtime.totalMemory() - runtime.freeMemory();
        System.out.println("Current memorycd usage: " + currentMemoryUsage / (1024 * 1024) + " MB");
        System.out.println("Peak memory usage: " + runtime.totalMemory() / (1024 * 1024) + " MB");
    }
}
