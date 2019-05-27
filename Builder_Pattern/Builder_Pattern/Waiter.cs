using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Builder_Pattern
{
    class Waiter
    {
        private PizzaBuilder pizzabuilder;

        public void SetPizzaBuilder(PizzaBuilder pb) { pizzabuilder = pb; }
        public Pizza GetPizza() { return pizzabuilder.GetPizza(); }

        public void CostructPizza() {
            pizzabuilder.CreateNewPizza();
            pizzabuilder.buildSource();
            pizzabuilder.buildTopping();
        }
    }
}
