using System;
using System.Collections.Generic;

namespace Composite_Pattern
{
    public class Composite : Component
    {

        private List<Component> children = new List<Component>();

        public Composite(string name) : base(name)
        {
        }

        public override void Add(Component c)
        {
            children.Add(c);
        }

        public override void Remove(Component c)
        {
            children.Remove(c);
        }

        public override void Display()
        {
            Console.WriteLine(name);
            foreach (Component a in children)
            {
                a.Display();
            }
        }
    }
}
