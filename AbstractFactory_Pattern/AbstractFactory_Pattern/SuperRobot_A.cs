using System;

namespace AbstractFactory_Pattern
{
    public class SuperRobot_A : Robot_A
    {
        public override void RobotName() {
            Console.WriteLine("SuperRobot_A");
        }
    }
}
