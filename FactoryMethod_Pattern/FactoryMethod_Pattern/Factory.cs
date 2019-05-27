using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace FactoryMethod_Pattern
{
    public class Factory
    {
        public Robot CreateRobot(String name)
        {
            switch (name)
            {
                case "SuperRobot": return new SuperRobot();
                case "MiniRobot": return new MiniRobot();
            }
            return null;
        }
    }
}
