using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace FactoryMethod_Pattern
{
    class SuperRobot : Robot
    {
        public override String getName()
        {
            return "SuperRobot";
        }
    }
}
