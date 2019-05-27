using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AbstractFactory_Pattern
{
    public class MiniRobot_A : Robot_A
    {
        public override void RobotName()
        {
            Console.WriteLine("MiniRobot_A");
        }
    }
}
