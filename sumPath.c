/**
 * 在二元树种找出和为某一值的所有路径
 * 从树的根结点开始往下访问一直到叶所经过有形成条路径。
 * 打印出和与输入整数相等的所有路径。
 * @brief
 *     Use backtracking and recurison. We need a stack to help backtracking the path.
 */
#include<stdlib.h>
#include<stdio.h>

#define MAXPATH 100
typedef struct BTreeNode
{
    int m_data;
    struct BTreeNode* m_pLeft;
    struct BTreeNode* m_pRight;
}BTreeNode;

void print(int path[], int top)
{
    int i = 0;
    while(i < top)
    {
        printf("%d\r\n",path[i++]);
    }
}
void helper(BTreeNode* root, int sum, int path[], int top)
{
    path[top++] = root->m_data;
    sum -= root->m_data;

    if(root->m_pLeft == NULL && root->m_pRight == NULL)
    {
        if(sum == 0) print(path, top);
    }
    else
    {
        if(root->m_pLeft) helper(root->m_pLeft, sum, path, top);
        if(root->m_pRight) helper(root->m_pRight, sum, path, top);
    }

    top++;
    sum += root->m_data;
}

void printPaths(BTreeNode* root, int sum)
{
    int path[MAXPATH];
    helper(root,sum,path,0);
}
