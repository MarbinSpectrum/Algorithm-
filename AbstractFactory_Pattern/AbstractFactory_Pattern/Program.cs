using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AbstractFactory_Pattern
{
    class Program
    {
        static void Main(string[] args)
        {
            RobotFactory[] r = { new MiniRobotFactory(), new SuperRobotFactory() };
            foreach (RobotFactory Robot in r)
            {
                Robot.getRobotA().RobotName();
                Robot.getRobotB().RobotName();
            }

        }
    }
}
