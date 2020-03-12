using System;
using System.Diagnostics;

namespace Recursive_Call
{
    class Program
    {
        public static void Main(string[] args)
        {
            Stopwatch sw = new Stopwatch();
            sw.Start();
            Console.WriteLine(Fibonacci(40));
            sw.Stop();
            Console.WriteLine("시간 : " + (sw.ElapsedMilliseconds)+"ms");
        }

        static int Fibonacci(int n) {
            if (n<= 0)
            {
                return 0;
            }
            else if (n <= 1)
            {
                return 1;
            }
            else
            {
                return Fibonacci(n-1) + Fibonacci(n-2);
            }
        }
    }
}
