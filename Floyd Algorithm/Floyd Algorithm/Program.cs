using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Floyd_Algorithm
{

    class Program
    {
        static int max = int.MaxValue;

        static void Main(string[] args)
        {
            int[,] S = new int[,]
            {
                { max ,1   ,max ,1   ,5   },
                { 9   ,max ,3   ,2   ,max },
                { max ,max ,max ,4   ,max },
                { max ,max ,2   ,max ,3   },
                { 3   ,max ,max ,max ,max }
             };

            int Funtion(int n, int[,] Array, int v1, int v2)
            {
                if (v1== v2)
                {
                    return 0;
                }
                if (Array[v1, v2] != max)
                {
                    return Array[v1, v2];
                }
                if (n > 0)
                {
                    int small = max;
                    for (int j = 0; j < 5; j++)
                    {
                        int n1 = Funtion(n - 1, Array, v1, j);
                        int n2 = Funtion(n - 1, Array, j, v2);
                        int temp = (n1 == max || n2 == max) ? max : n1 + n2;  
                        if (small > temp)
                        {

                            small = temp;
                        }
                    }
                    return small;
                }
                return max;
            }

            Console.WriteLine(" !! " + Funtion(5,S,4,2));



        }
    }
}
