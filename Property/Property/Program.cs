using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Property
{
    public class Program
    {

        public static void Main(string[] args)
        {
            TestChild tc = new TestChild();
            tc.temp();
            tc.temp2();
        }
    }

    public class Test
    {
        int YoungmukN = 5;
        public string Youngmuk
        {
            set;
            get;
        }

        public int Youngmuk2
        {
            set
            {
                Console.WriteLine("나는 빡빡이다!!");
                  YoungmukN = value;
            }
            get
            {
                Console.WriteLine("ㅎㅇ");

                if (YoungmukN == 5)
                {
                     return 0;
                }
                return YoungmukN;
            }
        }


    }

    public class TestChild : Test
    {
        public void temp()
        {
            Youngmuk = "영묵";
            Console.WriteLine(Youngmuk);
        }

        public void temp2()
        {
           // Youngmuk2 = 5;
            Console.WriteLine(Youngmuk2);
        }
    }
}
