using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
namespace Dictionary
{
    class Program
    {
        static void Main(string[] args)
        {
            Dictionary<int,String> Item = new Dictionary<int, String>();
            Item.Add(0, "리치베인");
            Item.Add(1, "라바돈의 죽음모자");
            Item.Add(2, "존야의 모래시계");
            Item.Add(3, "영겁의 지팡이");
            Item.Add(4, "무한의 대검");
            Item.Add(5, "고속연사포");
            Item.Remove(4);
            Item.Add(4, "공허의 지팡이");
            for (int n =0; n< Item.Count; n++)
            {
                Console.WriteLine(n+" : "+Item[n]);
            }
        }
    }
}
