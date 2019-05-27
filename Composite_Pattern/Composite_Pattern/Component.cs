using System;

namespace Composite_Pattern
{
    public abstract class Component
    {
        protected string name;

        public Component(String n)
        {
            name = n;
        }
        public abstract void Add(Component c);
        public abstract void Remove(Component c);
        public abstract void Display();
    }
}
