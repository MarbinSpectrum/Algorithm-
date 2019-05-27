using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AbstractFactory_Pattern
{
    public class MiniRobotFactory : RobotFactory
    {
        public override Robot_A getRobotA()
        {
            return new MiniRobot_A();
        }

        public override Robot_B getRobotB()
        {
            return new MiniRobot_B();
        }
    }
}
