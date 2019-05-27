using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Prototype_Pattern
{
    public class Warrior : Prototype
    {
        public override Object cloneObject()
        {
            return (Object)this.MemberwiseClone();
        }
    }
}
