using System;

namespace MergeSort
{
    public class Program
    {       
        public static void Main(string[] args)
        {
            Function function = new Function();
            Random random = new Random();
            int[] S = new int[12];

            for (int n = 0; n<S.Length; n++)        //배열에 랜덤한 값을 대입
                S[n] = random.Next(0, 100);

            function.Print(S);        //배열산출
            function.MergeSort(S);    //합병정렬
            Console.WriteLine("                     ↓              ");
            function.Print(S);        //배열산출

        }
    }
}
