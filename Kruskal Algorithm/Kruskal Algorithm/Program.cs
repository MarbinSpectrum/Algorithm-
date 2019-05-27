using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Kruskal_Algorithm
{
    class Program
    {
        static void Main(string[] args)
        {
            int max = int.MaxValue;

            int[,] S = new int[,]
            {
                { max ,1   ,3  ,max ,max },
                { 1   ,max ,3  ,6   ,max },
                { 3   ,3   ,max ,4   ,2   },
                { max ,6   ,4  ,max ,5   },
                { max ,max ,2  ,5   ,max  }
             };

            bool[,] CheckS = new bool[,]
            {
                {false,false,false,false,false },
                {false,false,false,false,false },
                {false,false,false,false,false },
                {false,false,false,false,false },
                {false,false,false,false,false }
            };

            bool[] CheckPoint = new bool[]
            {false, false, false, false, false };

            bool Funtion(int v1, int v2,int n)
            {
                if (n > 0)
                {
                    if (CheckS[v1, v2] || CheckS[v2, v1])
                    {
                        return true;
                    }
                    else
                    {
                        for (int a = 0; a < 5; a++)
                        {
                            bool c = Funtion(v1, a, n - 1);
                            bool c2 = Funtion(a, v2, n - 1);
                            if (c && c2)
                            {
                                return true;
                            }
                        }
                    }
                }
                return false;

            }

            for (int k = 0; k <5; k++) {
                int small = max;
                int tempi = 0;
                int temph = 0;
                for (int i = 0; i < 5; i++)
                {
                    for (int h = 0; h < 5; h++)
                    {
                        if (small > S[i, h] && Funtion(i,h,5) == false)
                        {
                            small = S[i, h];
                            tempi = i;
                            temph = h;
                        }
                    }
                }

                if (small != max)
                {
                    CheckS[tempi, temph] = true;
                    CheckS[temph, tempi] = true;
                }

            }

            for (int a = 0; a < 5; a++)
            {
                for (int b =0; b <5; b++)
                {
                    Console.Write(CheckS[b,a]+" ");
                }
                Console.WriteLine("");
            }
        }
    }
}
