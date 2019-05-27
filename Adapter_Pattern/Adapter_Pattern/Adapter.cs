using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Adapter_Pattern
{
    class Adapter : Dog
    {
        Cat cat;
        public void CatAdapter(Cat cat)
        {
            this.cat = cat;
        }

        public void Move()
        {
            cat.Move();
        }
    }
}
