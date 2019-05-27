using System;
using System.Collections.Generic;

namespace ListArray
{
    class Program
    {
        static void Main(string[] args)
        {
            List<string> A = new List<string>(); //리스트선언
            for (int n = 0; n < 10; n++)   //for문으로 0부터 10까지 돌림
            {
                A.Add("" + n);   //리스트에 n값을 추가함
            }
            string line = string.Join(", ",A.ToArray());
            Console.WriteLine(line);
        }
    }
}
