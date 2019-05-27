using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Prim_s_Algorithm
{
    class Program
    {
        static void Main(string[] args)
        {
            int max = int.MaxValue;
            /*
            int[,] S = new int[,]
            {
                { max ,1   ,3  ,max ,max },
                { 1   ,max ,3  ,6   ,max },
                { 3   ,3   ,max ,4   ,2   },
                { max ,6   ,4  ,max ,5   },
                { max ,max ,2  ,5   ,max  }
             };
            */
            
            int[,] S = new int[,]
            {
                { max ,max   ,max  ,3 ,7 },
                { max   ,max ,max  ,2   ,5 },
                { max   ,max   ,max ,1   ,max   },
                { 3 ,2   ,1  ,max ,4   },
                { 7 ,5 ,max  ,4   ,max  }
             };
            

            bool[,] CheckS = new bool[,]
            {
                { false,false,false,false,false},
                { false,false,false,false,false},
                { false,false,false,false,false},
                { false,false,false,false,false},
                { false,false,false,false,false},
             };

            bool[] CheckPoint = new bool[] 
            { true, false, false, false, false };

            int temp = 0;
            int small = max;

            for (int i=0; i < 5; i++)
            {
                if (small > S[0,i])
                {
                    small = S[0, i];
                    temp = i;
                }
            }

            CheckS[0, temp] = true;
            CheckPoint[temp] = true;

            for (int i = 1; i < 5; i++)
            {
                int sm = S[i,0];
                int tm = 0;
                for (int j =0; j<5; j++)
                {
                    if (sm > S[i,j] && CheckPoint[j] == true)
                    {
                        sm = S[i, j];
                        tm = j;
                    }
                }
                if (CheckPoint[i] == false) {
                    CheckS[i, tm] = true;
                    CheckPoint[tm] = true;
                }
            }
            for (int a = 0; a <5; a++)
            {
                for (int b = 0; b < 5; b++)
                {
                    Console.Write(CheckS[b, a]+ " ");
                }
                Console.WriteLine("");
            }


        }
    }
}
