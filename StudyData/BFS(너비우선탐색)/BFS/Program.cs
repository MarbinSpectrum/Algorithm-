using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace BFS
{
    class Program
    {
        static void Main(string[] args)
        {

            //초기화
            Node[,] node = new Node[36, 36];

            for (int i = 1; i < 36; i++)
            {
                for (int j = 1; j < 36; j++)
                {
                    node[i, j] = new Node();
                }
            }

            for (int i = 1; i <= 6; i++)
            {
                for (int j = 1; j <= Math.Pow(2, i - 1); j++)
                {
                    node[i, j].NodeSet(i, j);

                    if (i > 1)
                    {
                        if (j % 2 == 0)
                        {
                            node[i - 1, j / 2].Rnode = node[i, j];
                        }
                        else
                        {
                            node[i - 1, (j + 1) / 2].Lnode = node[i, j];
                        }
                    }
                }
            }

            //출력
            node[1, 1].CheckNode();
            Console.WriteLine("(" + node[1, 1].i + " ," + node[1, 1].p + " ," + node[1, 1].www + ")" + "  maxprofit: " + Node.maxprofit + "  bound: " + node[1, 1].bound);
            for (int i = 1; i <= 6; i++)
            {
                for (int j = 1; j <= Math.Pow(2, i - 1); j++)
                {
                    if (node[i, j].Check)
                    {
                        if (node[i, j].p > Node.maxprofit)
                        {
                            Node.maxprofit = node[i, j].p;
                        }

                        if (node[i, j].Lnode != null)
                        {
                            node[i, j].Lnode.CheckNode();
                            if (node[i, j].Lnode.Check)
                            {
                                if (node[i, j].Lnode.p > Node.maxprofit)
                                {
                                    Node.maxprofit = node[i, j].Lnode.p;
                                }
                            }
                            Console.WriteLine("(" + node[i, j].Lnode.i + " ," + node[i, j].Lnode.p + " ," + node[i, j].Lnode.www + ")" + "  maxprofit: " + Node.maxprofit + "  bound: " + node[i, j].Lnode.bound);
                        }
                        if (node[i, j].Rnode != null)
                        {
                            if (node[i, j].Rnode.Check)
                            {
                                if (node[i, j].Rnode.p > Node.maxprofit)
                                {
                                    Node.maxprofit = node[i, j].Rnode.p;
                                }
                            }
                            node[i, j].Rnode.CheckNode();
                            Console.WriteLine("(" + node[i, j].Rnode.i + " ," + node[i, j].Rnode.p + " ," + node[i, j].Rnode.www + ")" + "  maxprofit: " + Node.maxprofit + "  bound: " + node[i, j].Rnode.bound);
                        }
                    }
                }
            }
            Console.WriteLine("");
            Console.WriteLine("답: " + Node.maxprofit);


        }
    }
}
