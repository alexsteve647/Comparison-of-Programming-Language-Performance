using System;
using System.Diagnostics;
using System.Runtime.InteropServices;

class FibonacciTest
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
        // Start time measurement
        Stopwatch stopwatch = Stopwatch.StartNew();

        // Generate Fibonacci sequence
        int n = 30;
        int[] fiboSeq = new int[n];
        for (int i = 0; i < n; i++)
        {
            fiboSeq[i] = Fibonacci(i);
        }

        // End time measurement
        stopwatch.Stop();
        Console.WriteLine("Execution time: {0} ms", stopwatch.ElapsedMilliseconds);

        // Get memory usage
        PROCESS_MEMORY_COUNTERS memCounter;
        GetProcessMemoryInfo(Process.GetCurrentProcess().Handle, out memCounter, (uint)Marshal.SizeOf(typeof(PROCESS_MEMORY_COUNTERS)));
        Console.WriteLine("Current memory usage: {0} MB", memCounter.WorkingSetSize / 1024 / 1024);
        Console.WriteLine("Peak memory usage: {0} MB", memCounter.PeakWorkingSetSize / 1024 / 1024);
    }

    static int Fibonacci(int n)
    {
        if (n <= 1)
        {
            return n;
        }
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}
