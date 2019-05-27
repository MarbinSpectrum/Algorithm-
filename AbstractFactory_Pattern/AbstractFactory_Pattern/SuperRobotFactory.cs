using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AbstractFactory_Pattern
{
    public class SuperRobotFactory : RobotFactory
    {
        public override Robot_A getRobotA() {
            return new SuperRobot_A();
        }

        public override Robot_B getRobotB()
        {
            return new SuperRobot_B();
        }
    }
}
