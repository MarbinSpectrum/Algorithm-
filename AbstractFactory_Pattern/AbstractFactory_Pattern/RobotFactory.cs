using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AbstractFactory_Pattern
{
    public abstract class RobotFactory
    {
        public abstract Robot_A getRobotA();
        public abstract Robot_B getRobotB();
    }
}
