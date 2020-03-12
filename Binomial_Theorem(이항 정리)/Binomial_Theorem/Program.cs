using System;
using System.Diagnostics;

namespace Binomial_Theorem
{
    class Program
    {
        static void Main(string[] args)
        {  
            int n = 14;
            int k = 7;

            int[,] B = new int[n+1 , n+1];

            Stopwatch sw = new Stopwatch();
            Stopwatch sw2 = new Stopwatch();

            sw.Start();

            Console.WriteLine("분할정복");
            Console.WriteLine("결과 : bin(" + n + "," + k + ") = " + bin(n, k));

            sw.Stop();

            Console.WriteLine("시간 : " + (sw.ElapsedMilliseconds) + "ms");
            Console.WriteLine("");
            Console.WriteLine("");
            Console.WriteLine("");
            Console.WriteLine("동적계획");

            sw2.Start();

            Console.WriteLine("결과 : bin(" + n + "," + k + ") = " + bin2(n, k,B));

            sw2.Stop();

            Console.WriteLine("시간 : " + (sw2.ElapsedMilliseconds) + "ms");
        }

        //분할정복 이항계수
        static int bin(int n,int k)
        {
            if (n == k || k == 0)
            {
                Console.WriteLine("bin(" + n + "," + k + ") = 1");
                Console.WriteLine("");

                return 1;
            }

            int n1 = bin(n - 1, k - 1);
            int n2 = bin(n - 1, k);

            Console.Write("bin(" + (n - 1) + "," + (k - 1) + ")");
            Console.Write("[" + n1 + "] + ");
            Console.Write("bin(" + (n - 1) + "," + (k) + ")");
            Console.Write("[" + n2 + "] = ");
            Console.Write("bin(" + (n) + "," + (k) + ")");
            Console.WriteLine("[" + (n1 + n2) + "]");
            Console.WriteLine("");

            return n1 + n2;
        }

        //동적계획 이항계수
        static int bin2(int n,int k,int[,] S)
        {
            for (int i = 0; i < n+1; i++)
            {
                for (int j = 0; j<i+1; j++)
                {
                    if (i == j || j == 0)
                    {
                        S[i, j] = 1;

                        Console.Write(" bin(" + i + "," + j + ") = 1");
                    }
                    else
                    {
                        if (i > 0)
                        {
                            S[i, j] = S[i - 1, j - 1] + S[i - 1, j];

                            Console.Write(" bin(" + i + "," + j + ") = " + S[i, j]);
                        }
                    }
                }
                Console.WriteLine("");
            }
            Console.WriteLine("");

            return S[n, k];
        }
    }
}

