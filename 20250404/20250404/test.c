

//1123.

/*
给你一个有根节点 root 的二叉树，返回它 最深的叶节点的最近公共祖先 。
回想一下：
叶节点 是二叉树中没有子节点的节点
树的根节点的 深度 为 0，如果某一节点的深度为 d，那它的子节点的深度就是 d+1
如果我们假定 A 是一组节点 S 的 最近公共祖先，S 中的每个节点都在以 A 为根节点的子树中，
	且 A 的深度达到此条件下可能的最大值。
*/


 struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };
 

int height(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    return fmax(height(root->left), height(root->right)) + 1;
}
struct TreeNode* check(struct TreeNode* root)
{
    int left = height(root->left);
    int right = height(root->right);
    if (left == right)//这就是相当于之前模板的lson&&rson
    {
        return root;
    }
    else if (left < right)//更深的节点在右子树
    {
        return check(root->right);
    }
    else
    {
        return check(root->left);//在左子树
    }//对于只有一个最深节点的情况也可以解决，只有在遍历到这个节点时，才会出现左右子树深度相等的情况，都是0.
}
struct TreeNode* lcaDeepestLeaves(struct TreeNode* root) {
    return check(root);
}
