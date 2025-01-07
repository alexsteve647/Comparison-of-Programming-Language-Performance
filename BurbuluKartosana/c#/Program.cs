using System;
using System.Diagnostics;
using System.Runtime.InteropServices;

class BubbleSortTest
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
        int n = 10000;
        int[] arr = new int[n];
        Random rand = new Random();

        // Populate the array with random values
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand.Next(10000);
        }

        // Start time measurement
        Stopwatch stopwatch = Stopwatch.StartNew();

        bubbleSort(arr);

        // End time measurement
        stopwatch.Stop();
        Console.WriteLine("Execution time: {0} ms", stopwatch.ElapsedMilliseconds);

        // Get memory usage
        PROCESS_MEMORY_COUNTERS memCounter;
        GetProcessMemoryInfo(Process.GetCurrentProcess().Handle, out memCounter, (uint)Marshal.SizeOf(typeof(PROCESS_MEMORY_COUNTERS)));
        Console.WriteLine("Current memory usage: {0} MB", memCounter.WorkingSetSize / 1024 / 1024);
        Console.WriteLine("Peak memory usage: {0} MB", memCounter.PeakWorkingSetSize / 1024 / 1024);
    }

    static void bubbleSort(int[] arr)
    {
        int n = arr.Length;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
}
