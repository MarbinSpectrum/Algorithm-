using System;


namespace Singleton_Pattern
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Singleton.getInstance().StudyNumber);
        }
    }
}
