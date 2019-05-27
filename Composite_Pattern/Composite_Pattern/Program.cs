using System.Linq;
using System.Text;

namespace Composite_Pattern
{
    public class Program
    {
        static void Main(string[] args)
        {
            Component root = new Composite("root");
            root.Add(new Leaf("Leaf1"));
            root.Add(new Leaf("Leaf2"));

            Component root2 = new Composite("rootx");
            root2.Add(new Leaf("Leafx1"));
            root2.Add(new Leaf("Leafx2"));

            root.Add(root2);

            root.Add(new Leaf("Leaf3"));

            Leaf l = new Leaf("Leaf4");

            root.Add(l);
            root.Remove(l);

            root.Display();
        }
    }
}
