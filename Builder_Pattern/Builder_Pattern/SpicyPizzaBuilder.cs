using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Builder_Pattern
{
    class SpicyPizzaBuilder : PizzaBuilder
    {
        public override void buildSource()
        {
            pizza.SetSource("hot");
        }

        public override void buildTopping()
        {
            pizza.SetTopping("pepparoni+salami");
        }
    }
}
