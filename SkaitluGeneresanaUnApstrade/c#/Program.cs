using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Runtime.InteropServices;

class NumberGenerationTest
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

        // Generate a large set of random numbers
        int n = 1000000;
        int[] numbers = new int[n];
        Random rand = new Random();
        for (int i = 0; i < n; i++)
        {
            numbers[i] = rand.Next(1000000);
        }

        // Process the numbers (e.g., filter even numbers)
        List<int> evenNumbers = new List<int>();
        for (int i = 0; i < n; i++)
        {
            if (numbers[i] % 2 == 0)
            {
                evenNumbers.Add(numbers[i]);
            }
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
}
