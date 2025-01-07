using System;
using System.Diagnostics;
using System.Runtime.InteropServices;

class MatrixMultiplicationTest
{
    [DllImport("psapi.dll", SetLastError = true)]
    public static extern bool GetProcessMemoryInfo(IntPtr hProcess, out PROCESS_MEMORY_COUNTERS counters, uint size);

    [StructLayout(LayoutKind.Sequential, Size = 40)]
    public struct PROCESS_MEMORY_COUNTERS
    {
        public uint cb;
        public uint PageFaultCount;
        public ulong PeakWorkingSetSize;
        public ulong WorkingSetSize;
        public ulong QuotaPeakPagedPoolUsage;
        public ulong QuotaPagedPoolUsage;
        public ulong QuotaPeakNonPagedPoolUsage;
        public ulong QuotaNonPagedPoolUsage;
        public ulong PagefileUsage;
        public ulong PeakPagefileUsage;
    }

    static void Main()
    {
        int n = 500;
        int[,] A = new int[n, n];
        int[,] B = new int[n, n];
        int[,] C = new int[n, n];
        Random rand = new Random();

        // Initialize matrices A and B with random values
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                A[i, j] = rand.Next(100);
                B[i, j] = rand.Next(100);
            }
        }

        // Start time measurement
        Stopwatch stopwatch = Stopwatch.StartNew();

        // Perform matrix multiplication
        MatrixMultiplication(A, B, C, n);

        // End time measurement
        stopwatch.Stop();
        Console.WriteLine("Execution time: {0} ms", stopwatch.ElapsedMilliseconds);

        // Get memory usage
        PROCESS_MEMORY_COUNTERS memCounter;
        GetProcessMemoryInfo(Process.GetCurrentProcess().Handle, out memCounter, (uint)Marshal.SizeOf(typeof(PROCESS_MEMORY_COUNTERS)));
        Console.WriteLine("Current memory usage: {0} MB", memCounter.WorkingSetSize / 1024 / 1024);
        Console.WriteLine("Peak memory usage: {0} MB", memCounter.PeakWorkingSetSize / 1024 / 1024);
    }

    static void MatrixMultiplication(int[,] A, int[,] B, int[,] C, int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                C[i, j] = 0;
                for (int k = 0; k < n; k++)
                {
                    C[i, j] += A[i, k] * B[k, j];
                }
            }
        }
    }
}
