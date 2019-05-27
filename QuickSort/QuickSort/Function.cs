using System;

namespace QuickSort
{
    public class Function
    {
        //빠른정렬
        public void QuickSort(int[] S, bool[] Sc)
        {
            int first = 0;
            int last = S.Length-1;
            Partition(first,last,S,Sc);
        }

        //분할하기
        public void Partition(int f,int l,int[] S,bool[] Sc)
        {
            if (l > f)
            {
                int point = f;  //pivotpoint 지정
                int i = 0;
                int temp;       //교환관련변수

                Console.WriteLine("");
                Console.WriteLine("(" + S[f] + ")pivotpoint를 선택");
                Print(S, f, Sc);

                for (int j = 1; j < l + 1; j++)
                {
                    if (S[j] <= S[point])
                    {
                        i++;                //S[j]가 pivotpoint보다 작으면 S[i]와 교환
                        temp = S[j];
                        S[j] = S[i];
                        S[i] = temp;
                    }
                }

                temp = S[i];
                S[i] = S[point];
                S[point] = temp;
                point = i;  //pivotpoint 재지정
                Sc[i] = true;

                Console.WriteLine("");
                Console.WriteLine("(" + S[i] + ")를 정해진 위치로");
                Print(S, i, Sc);
                Partition(f, i - 1, S, Sc);
                Partition(i + 1, l, S, Sc);

            }
            else if (l == f)
            {
                Console.WriteLine("");
                Console.WriteLine("(" + S[l] + ")위치 선정");
                Print(S, l, Sc);
                Sc[l] = true;
            }
        }

        //배열산출
        public void Print(int[] S,  bool[] Sc)
        {
            for (int n = 0; n < S.Length; n++)
            {
                if (Sc[n] == true)
                {
                    Console.Write("[" + S[n] + "]");
                }
                else
                {
                    Console.Write(S[n]);
                }

                if (n != S.Length - 1)
                {
                    Console.Write(", ");
                }
                else
                {
                    Console.WriteLine("");
                }
            }
        }

        public void Print(int[] S,int i ,bool[] Sc)
        {
            for (int n = 0; n < S.Length; n++)
            {
                if (n == i)
                {
                    Console.Write("("+S[n]+")");
                }
                else
                {
                    if (Sc[n] == true)
                    {
                        Console.Write("["+S[n]+"]");
                    }
                    else
                    {
                        Console.Write(S[n]);
                    }
                }
                if (n != S.Length - 1)
                {
                    Console.Write(", ");
                }
                else
                {
                    Console.WriteLine("");
                }
            }
        }
    }
}
