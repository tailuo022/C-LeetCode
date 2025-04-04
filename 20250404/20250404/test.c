

//1123.

/*
����һ���и��ڵ� root �Ķ������������� �����Ҷ�ڵ������������� ��
����һ�£�
Ҷ�ڵ� �Ƕ�������û���ӽڵ�Ľڵ�
���ĸ��ڵ�� ��� Ϊ 0�����ĳһ�ڵ�����Ϊ d���������ӽڵ����Ⱦ��� d+1
������Ǽٶ� A ��һ��ڵ� S �� ����������ȣ�S �е�ÿ���ڵ㶼���� A Ϊ���ڵ�������У�
	�� A ����ȴﵽ�������¿��ܵ����ֵ��
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
    if (left == right)//������൱��֮ǰģ���lson&&rson
    {
        return root;
    }
    else if (left < right)//����Ľڵ���������
    {
        return check(root->right);
    }
    else
    {
        return check(root->left);//��������
    }//����ֻ��һ������ڵ�����Ҳ���Խ����ֻ���ڱ���������ڵ�ʱ���Ż�����������������ȵ����������0.
}
struct TreeNode* lcaDeepestLeaves(struct TreeNode* root) {
    return check(root);
}
