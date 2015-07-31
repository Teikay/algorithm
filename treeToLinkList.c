/**
 * 把二元查找树转变成排序的双向链表
 */
#include<stdio.h>

typedef struct BTreeNode
{
    int m_nValue;
    struct BTreeNode* m_pLeft;
    struct BTreeNode* m_pRight;
}BTreeNode;

void doChange(BTreeNode* pHead, BTreeNode* pTail, BTreeNode* root)
{
    BTreeNode* pLtail = NULL;
    BTreeNode* pRhead = NULL;

    if(root == NULL)
    {
        pHead = pTail = NULL;
        return;
    }
    //转换左子树
    doChange(pHead, pLtail, root->m_pLeft);
    //转换左子树
    doChange(pRhead, pTail, root->m_pRight);

    if(pLtail == NULL)
    {
        pHead = root;
    }
    else
    {
        pLtail->m_pRight = root;
        root->m_pLeft = pLtail;
    }

    if(pRhead == NULL)
    {
        pTail = root;
    }
    else
    {
        root->m_pRight = pRhead;
        pRhead->m_pLeft = root;
    }
}

BTreeNode* treeToLinkList(BTreeNode* root)
{
    BTreeNode* pHead = NULL;
    BTreeNode* pTail = NULL;
    doChange(pHead, pTail, root);
    return pHead;
}

