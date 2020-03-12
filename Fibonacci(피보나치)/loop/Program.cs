using System;
using System.Diagnostics;

namespace loop
{
    class Program
    {
        public static void Main(string[] args)
        {
            Stopwatch sw = new Stopwatch();
            sw.Start();
            Console.WriteLine(Fibonacci(50));
            sw.Stop();
            Console.WriteLine("시간: " + (sw.ElapsedMilliseconds) + "ms");
        }

        static int Fibonacci(int n)
        {
            if (n >= 0)
            {
                int[] FibonacciNumber = new int[n+1];
                FibonacciNumber[0] = 1;
                if (n > 0)
                {
                    FibonacciNumber[1] = 1;
                    for (int i = 2; i < n+1; i++)
                    {
                        FibonacciNumber[i] = FibonacciNumber[i - 1] + FibonacciNumber[i - 2];
                    }
                    return FibonacciNumber[n - 1];
                }
                return 0;
            }
            return 0;
        }
    }
}
