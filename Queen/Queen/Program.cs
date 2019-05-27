using System;

namespace Queen
{
    class Program
    {
        static bool[,] Map;

        static int n;
        static int count = 0;

        static void Main(string[] args)
        {
            Console.WriteLine("칸의수 입력\n");
            n = Convert.ToInt32(Console.ReadLine());

            Map = new bool[n, n];

            for (int i = 0; i < n; i++)
            {
                Queen(i, 0);
                if (count < n)
                {
                    Map[i, 0] = false;
                    count--;
                }
            }

        }

        //여왕을 배치하는 함수
        static void Queen(int x, int y)
        {
            if (count < n)
            {
                if (Set(x, y))
                {

                    Map[x, y] = true;
                    count++;

                    Draw();

                    if (y + 1 < n)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            Queen(j, y + 1);
                            if (count < n && Map[j, y + 1] == true)
                            {
                                Map[j, y + 1] = false;
                                count--;
                            }
                        }
                    }
                }
                else
                {
                    Draw(x, y);
                }
            }
        }

        //현재 체스판을 그려주는 함수
        static void Draw()
        {
            for (int q = 0; q < n; q++)
            {
                for (int w = 0; w < n; w++)
                {
                    if (Map[w, q] == false)
                    {
                        Console.Write("□");
                    }
                    else
                    {
                        Console.Write("■");
                    }
                }
                Console.Write("\n");
            }
            Console.Write("\n");
        }

        static void Draw(int x,int y)
        {
            for (int q = 0; q < n; q++)
            {
                for (int w = 0; w < n; w++)
                {
                    if (q == y && w == x)
                    {
                            Console.Write("X ");
                     
                    }
                    else
                    {
                        if (Map[w, q] == false)
                        {
                            Console.Write("□");
                        }
                        else
                        {
                            Console.Write("■");
                        }
                    }
                }
                Console.Write("\n");
            }
            Console.Write("\n");
        }

        //여왕을 놓을수있는지를 확인하는 함수
        static bool Set(int x, int y)
        {
            for (int a = 0; a < n; a++)
            {
                if (x + a < n)
                {
                    if (Map[x + a, y])
                    {
                        return false;
                    }
                    if (y + a < n)
                    {
                        if (Map[x + a, y + a])
                        {
                            return false;
                        }
                    }
                }
                if (x - a >= 0)
                {
                    if (Map[x - a, y])
                    {
                        return false;
                    }
                    if (y - a >= 0)
                    {
                        if (Map[x - a, y - a])
                        {
                            return false;
                        }
                    }
                }
                if (y + a < n)
                {
                    if (Map[x, y + a])
                    {
                        return false;
                    }
                    if (x - a >= 0)
                    {
                        if (Map[x - a, y + a])
                        {
                            return false;
                        }
                    }
                }
                if (y - a >= 0)
                {
                    if (Map[x, y - a])
                    {
                        return false;
                    }
                    if (x + a < n)
                    {
                        if (Map[x + a, y - a])
                        {
                            return false;
                        }
                    }
                }
            }
            return true;
        }
    }
}
