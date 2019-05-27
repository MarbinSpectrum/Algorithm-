using System;

namespace Prototype_Pattern
{
    public abstract class Prototype
    {
        public String strName;
        public int nAge;

        public abstract Object cloneObject();

        public static void Main(string[] args)
        {
            Warrior w1 = new Warrior();
            w1.strName = "KKK";
            w1.nAge = 25;

            Warrior w2 = (Warrior)w1.cloneObject();

            Console.WriteLine(w2.strName);
            Console.WriteLine(w2.nAge);

        }
    }
}
