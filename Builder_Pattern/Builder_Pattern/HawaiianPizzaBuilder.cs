using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Builder_Pattern
{
    class HawaiianPizzaBuilder : PizzaBuilder
    {
        public override void buildSource()
        {
            pizza.SetSource("mild");
        }

        public override void buildTopping()
        {
            pizza.SetTopping("ham+pineapple");
        }
    }
}
