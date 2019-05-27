public class TreeNode<U>
{
    //변수선언
    TreeNode<U> left;
    TreeNode<U> right;
    U data;


    //왼쪽쪽 노드 설정
    public void SetLeftNode(TreeNode<U> node)
    {
        if (left != null)
        {
            left = default(TreeNode<U>);
        }
        left = node;
    }
    //오른쪽 노드 설정
    public void SetRightNode(TreeNode<U> node)
    {
        if (right != null)
        {
            right = default(TreeNode<U>);
        }
        right = node;
    }


    //노드의 데이터값 반환
    public U getData()
    {
        return data;
    }
    //왼쪽노드 반환
    public TreeNode<U> getLeftNode()
    {
        return left;
    }
    //오른쪽노드 반환
    public TreeNode<U> getRightNode()
    {
        return right;
    }


    //노드 생성자
    public TreeNode(U item)
    {
        left = default(TreeNode<U>);
        right = default(TreeNode<U>);
        data = item;
    }
}
