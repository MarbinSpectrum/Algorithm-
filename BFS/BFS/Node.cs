using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace BFS
{
    class Node
    {
        public float bound = 0;

        public static int maxprofit = 0;
        static int n = 5;
        static int W = 13;

        static int[] P = new int[] { 20, 30, 35, 12, 3 };
        static int[] w = new int[] { 2, 5, 7, 3, 1 };

        public Node Lnode;
        public Node Rnode;
        public bool Check;
        public int i;
        public int p;
        public int www;

        public Node()
        {
            Lnode = null;
            Rnode = null;
            Check = false;
            i = 0;
            p = 0;
            www = 0;
        }

        public bool CheckNode()
        {
            int k, l;
            int toweight;

            if (www > W)
            {
                bound = 0;
                Check = false;
                return false;
            }
            else
            {
                k = i;
                bound = p;
                toweight = www;

                while (k < n && toweight + w[k] <= W)
                {
                    toweight = toweight + w[k];
                    bound = bound + P[k];
                    k++;
                }

                l = k;

                if (l < n)
                {
                    bound = bound + (W - toweight) * (P[l] / w[l]);
                }

                if (bound >= maxprofit)
                {
                    Check = true;
                }
                else
                {
                    Check = false;
                }
                return bound > maxprofit;
            }
        }

        public void NodeSet(int a,int b)
        {
            int ii = a - 1;
            int pp = 0;
            int ww = 0;
            int aa = a - 2;
            int bb = b;

            while (aa >= 0)
            {
                if (bb % 2 == 1)
                {
                    
                    bb++;
                    bb = bb / 2;
                    ww += w[aa];
                    pp += P[aa];
                    aa--;

                }
                else
                {
                    bb = bb / 2;
                    aa--;
                }
            }

            i = ii;
            www = ww;
            p = pp;
        }    
    }
}
