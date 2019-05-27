using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace traveling
{
    class Program
    {
        static void Main(string[] args)
        {
            int[,] S = new int[,]
                {
                    {  0 ,14 , 4 ,10 , 20 },
                    { 14 , 0 , 7 , 8 ,  7 },
                    {  4 , 5 , 0 , 7 , 16 },
                    { 11 , 7 , 9 , 0 ,  2 },
                    { 18 , 7 ,17 , 4 ,  0 }
                };

            void bound(int i)
            {
                int sum = 0;
                for (int a=0; a<5; a++)
                {
                    int min = 1000;
                    for (int b = 0; b < 5; b++)
                    {
                        if (min > S[a, b]  && a!=b)
                        {
                            min = S[a, b];
                        }
                    }
                    sum += min;
                }
                Console.WriteLine("["+i+"] bound : "+sum);
            }

            void bound2(int i, int i2)
            {
                int sum = S[i-1,i2-1];
                for (int a = 0; a < 5; a++)
                {
                    if (a != i-1)
                    {
                        int min = 1000;
                        for (int b = 0; b < 5; b++)
                        {
                            if (min > S[a, b] && a != b && b != i2 - 1)
                            {
                                if (!(a==i2-1 && b==i-1))
                                {
                                    min = S[a, b];
                                }
                            }
                        }
                        sum += min;
                    }
                }
                Console.WriteLine("[" + i + "," + i2 + "] bound : " + sum);
            }

            void bound3(int i, int i2 , int i3)
            {
                int sum = S[i - 1, i2 - 1] + S[i2 - 1, i3 - 1];
                for (int a = 0; a < 5; a++)
                {
                    if (a != i - 1 && a != i2 - 1)
                    {
                        int min = 1000;
                        for (int b = 0; b < 5; b++)
                        {
                            if (min > S[a, b] && a != b && b != i2 - 1 && b != i3 - 1)
                            {
                                if (!(a == i3 - 1 && b == i2 - 1) && !(a == i2 - 1 && b == i - 1))
                                {
                                    min = S[a, b];
                                }
                            }
                        }
                        sum += min;
                    }
                }
                Console.WriteLine("[" + i + "," + i2 + "," + i3 + "] bound : " + sum);
            }

            void bound4(int i, int i2, int i3, int i4)
            {
                int sum = S[i - 1, i2 - 1] + S[i2 - 1, i3 - 1] + S[i3 - 1, i4 - 1];
                Console.WriteLine(S[i - 1, i2 - 1]);
                Console.WriteLine(S[i2 - 1, i3 - 1]);
                Console.WriteLine(S[i3 - 1, i4 - 1]);
                for (int a = 0; a < 5; a++)
                {
                    if (a != i - 1 && a != i2 - 1 && a != i3 - 1)
                    {
                        int min = 1000;
                        for (int b = 0; b < 5; b++)
                        {
                            if (min > S[a, b] && a != b && b != i2 - 1 && b != i3 - 1 && b != i4 - 1)
                            {
                                if (!(a == i4 - 1 && b == i - 1) && !(a == i4 - 1 && b == i3 - 1) && !(a == i3 - 1 && b == i2 - 1) && !(a == i2 - 1 && b == i - 1))
                                {
                                    min = S[a, b];
                                }
                            }
                        }
                        Console.WriteLine(min);
                        sum += min;
                    }
                }
                Console.WriteLine("[" + i + "," + i2 + "," + i3 + "," + i4  + "] bound : " + sum);
            }

            bound(1);
            bound2(1, 2);
            bound2(1, 3);
            bound2(1, 4);
            bound2(1, 5);
            bound3(1, 3 , 2);
            bound3(1, 3 , 4);
            bound3(1, 3 , 5);
            bound3(1, 4 , 2);
            bound3(1, 4 , 3);
            bound3(1, 4 , 5);
            bound4(1, 3 , 2, 4);
            bound4(1, 3 , 2, 5);
            bound4(1, 3 , 4, 2);
            bound4(1, 3 , 4, 5);
            bound4(1, 4 , 5, 2);
            bound4(1, 4 , 5, 3);
        }
    }
}
