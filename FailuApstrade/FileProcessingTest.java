import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class FileProcessingTest {
    public static void main(String[] args) {
        // Start time measurement
        long startTime = System.currentTimeMillis();

        // Read and process a large file
        try (BufferedReader reader = new BufferedReader(new FileReader("large_file.txt"))) {
            String line;
            while ((line = reader.readLine()) != null) {
                // Process the line (for example, just read it)
            }
        } catch (IOException e) {
            e.printStackTrace();
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
}
