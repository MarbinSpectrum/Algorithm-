using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Radixsort
{
    class Program
    {
        static void Main(string[] args)
        {
            int[,] S = new int[,] 
            { 
                {239, 234, 879, 878, 123, 358, 416, 317, 137, 225 },
                {  0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
                {  0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
                {  0,   0,   0,   0,   0,   0,   0,   0,   0,   0 }
            };

            bool[,] SC = new bool[,]
            {
                { false,false,false,false,false,false,false,false,false,false },
                { false,false,false,false,false,false,false,false,false,false },
                { false,false,false,false,false,false,false,false,false,false }
            };

            for (int n = 0; n < 10; n++)
            {
                Console.Write(S[0, n] + " ");
            }
            Console.WriteLine("");
            
            int j = 0;

            for (int a=0; a<3; a++) {
                j = 0;
                while (j < 10)
                {
                    for (int i = 0; i < 10; i++)
                    {
                        for (int k = 0; k < 10; k++)
                        {
                            if ((S[a, k] % Math.Pow(10,a+1)) - (S[a, k] % Math.Pow(10, a)) == i*Math.Pow(10, a) && SC[a, k] == false)
                            {
                                S[a+1, j] = S[a, k];
                                SC[a, k] = true;
                                j++;
                            }
                        }
                    }
                }
            }


            for (int n = 0; n < 10; n++)
            {
                Console.Write(S[3, n] + " ");
            }
            Console.WriteLine("");
        }
    }
}
