using System;

namespace Composite_Pattern
{
    public class Leaf : Component
    {
        public Leaf(string name) : base(name)
        {
        }

        public override void Add(Component c)
        {
            Console.WriteLine("잎에서는 연결할수없음");
        }

        public override void Remove(Component c)
        {
            Console.WriteLine("잎에서는 제거할수없음");
        }

        public override void Display()
        {
            Console.WriteLine(name);
        }
    }
}
