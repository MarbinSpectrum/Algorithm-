using System;

namespace QuickSort
{
    public class Program
    {
        public static void Main(string[] args)
        {
            Function function = new Function();
            Random random = new Random();
            int[] S = new int[8];
            bool[] Scheck = new bool[8];

            for (int n = 0; n < S.Length; n++)        //배열에 랜덤한 값을 대입
            {
                S[n] = random.Next(0, 100);
                Scheck[n] = false;
            }

            function.Print(S, Scheck);         //배열산출
            Console.WriteLine("");
            Console.WriteLine("             ↓");
            function.QuickSort(S,Scheck);    //합병정렬

            Console.WriteLine("");
            Console.WriteLine("                      ↓");
            Console.WriteLine("");
            function.Print(S, Scheck);        //배열산출
        }
    }
}
