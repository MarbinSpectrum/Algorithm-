using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Tree
{
    public class Program
    {

        public static void Main(string[] args)
        {
            TreeNode<int> Root = new TreeNode<int>(1);
            TreeNode<int> Node1 = new TreeNode<int>(2);
            TreeNode<int> Node2 = new TreeNode<int>(3);
            TreeNode<int> Node3 = new TreeNode<int>(4);

            Root.SetLeftNode(Node1);
            Root.SetRightNode(Node2);
            Node2.SetRightNode(Node3);
            FindNode(Root,4);
        }

        private static void FindNode(TreeNode<int> start ,int v)
        {
            if (start == null)
            {
                Console.WriteLine("노드에 아무것도 없다.");
                return;
            }
            Console.WriteLine("이 노드를 탐색");
            if (start.getData() == v)
            {
                Console.WriteLine("탐색완료");
                return;
            }
            Console.WriteLine("왼쪽탐색");
            FindNode(start.getLeftNode(),v);
            Console.WriteLine("오른쪽탐색");
            FindNode(start.getRightNode(), v);
        }
    }

}
