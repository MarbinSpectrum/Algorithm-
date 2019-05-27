using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace FactoryMethod_Pattern
{
    class Program
    {
        static void Main(string[] args)
        {
            Factory factory = new Factory();
            Robot r1 = factory.CreateRobot("SuperRobot");
            Robot r2 = factory.CreateRobot("MiniRobot");
            Console.WriteLine(r1.getName());
            Console.WriteLine(r2.getName());
        }
    }
}
