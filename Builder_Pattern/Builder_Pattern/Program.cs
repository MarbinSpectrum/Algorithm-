using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Builder_Pattern
{
    class Program
    {
        static void Main(string[] args)
        {
            Waiter w1 = new Waiter();
            PizzaBuilder[] Hawa = { new HawaiianPizzaBuilder(), new SpicyPizzaBuilder() };
            foreach (PizzaBuilder pb in Hawa)
            {
                w1.SetPizzaBuilder(pb);
                w1.CostructPizza();

                Console.WriteLine(w1.GetPizza().Source);
                Console.WriteLine(w1.GetPizza().Topping);
            }
        }
    }
}
