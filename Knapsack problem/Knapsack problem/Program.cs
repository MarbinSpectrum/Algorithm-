using System;

namespace Knapsack_problem
{
    class Program
    {
        static float bound = 0;

        static int maxprofit = 0;
        static int n = 5;
        static int W = 13;

        static int[] P = new int[] { 20, 30, 35, 12, 3 };
        static int[] w = new int[] { 2, 5, 7, 3, 1 };

        static bool[] include = new bool[] { false, false, false, false, false };

        static void Main(string[] args)
        {

            knap(0, 0, 0);
            Console.WriteLine("");
            Console.WriteLine("답: " + maxprofit);
        }

        static void knap(int i, int p, int ww)
        {
            Console.WriteLine("knap(" + i + ", " + p + ", " + ww + ")");
            if (ww <= W && p > maxprofit)
            {
                maxprofit = p;
            }
            if (prom(i, ww, p))
            {
                if (i + 1 <= n)
                {
                    include[i] = true;
                    Console.WriteLine("");
                   // Console.WriteLine("include[" + i + "] = " + include[i]);
                    knap(i + 1, p + P[i], ww + w[i]);
                    include[i] = false;
                    Console.WriteLine("");
                    //Console.WriteLine("include[" + i + "] = " + include[i]);
                    knap(i + 1, p, ww);
                }
            }
        }

        private static bool prom(int i, int ww, int p)
        {
            int k, l;
            int toweight;

            if (ww > W)
            {
                return false;
            }
            else
            {
                k = i;
                bound = p;
                toweight = ww;


                while (k<n && toweight < W)
                {
                    if (W - (toweight + w[k]) >= 0)
                    {
                        bound += P[k];
                        toweight += w[k];
                    }
                    else
                    {
                            bound += (W - toweight) * (P[k] / w[k]);
                            toweight += (W - toweight);
                    }
                    k++;
                }

                Console.WriteLine("bound = " + bound);
                Console.WriteLine("maxprofit = " + maxprofit);
                return bound > maxprofit;
            }
        }
    }
}

