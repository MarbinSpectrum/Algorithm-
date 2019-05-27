using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Adapter_Pattern
{
    class Dog
    {
        public virtual void Move()
        {
            Console.WriteLine("뛴당");
        }
    }
}
