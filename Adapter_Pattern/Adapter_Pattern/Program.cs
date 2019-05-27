using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Adapter_Pattern
{
    class Program
    {
        static void Main(string[] args)
        {
            Dog dog = new Dog();
            dog.Move();
            Cat cat = new Cat();
            cat.Move();
            Adapter ad = new Adapter();
            Test(ad);
            
        }
        static void Test(Dog dg)
        {
            dg.Move();
        }
        
    }
}
