using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Builder_Pattern
{
    public class Pizza
    {
        public String Source;
        public String Topping;
        public Pizza() { }
        public void SetSource(String s) {
            Source = s;
        }
        public void SetTopping(String t)
        {
            Topping = t;
        }
    }

    public abstract class PizzaBuilder
        {
        protected Pizza pizza;
        public PizzaBuilder() { }
        public Pizza GetPizza() {
            return pizza;
        }
        public void CreateNewPizza()
        {
            pizza = new Pizza();
        }
        public abstract void buildSource();
        public abstract void buildTopping();
    }
}
