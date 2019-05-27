using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace FactoryMethod_Pattern
{
    class MiniRobot : Robot
    {
        public override String getName()
        {
            return "MiniRobot";
        }
    }
}
