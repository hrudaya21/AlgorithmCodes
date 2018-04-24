using namespace std;
#include<iostream>

struct TNode
{
    int iData;
    TNode* left;
    TNode* right;
};
TNode* createNode(int iNewData)
{
    TNode* newNode = new TNode();
    newNode->iData = iNewData;
    newNode->left = newNode->right = NULL;
    return newNode;
}
class CBinaryTree
{
    TNode* m_pRoot;
public:
    CBinaryTree()
    {
        m_pRoot = createNode(1);
        m_pRoot->left = createNode(2);
        m_pRoot->right = createNode(3);
        m_pRoot->left->left = createNode(4);
        m_pRoot->left->right = createNode(5);
        m_pRoot->right->left = createNode(6);
        m_pRoot->right->right = createNode(7);
    }
    ~CBinaryTree(){
        delete m_pRoot;
    }
    void LCA(int,int);
    TNode* LCAImpl(TNode*,int,int);
};

void CBinaryTree::LCA(int iNode1, int iNode2)
{
    TNode* currentNode = m_pRoot;
    TNode* lca  = LCAImpl(currentNode,iNode1, iNode2);
    cout<<"LCA: "<<lca->iData<<endl;
}
TNode* CBinaryTree::LCAImpl(TNode* currentNode, int iNode1, int iNode2)
{
    if(currentNode == NULL){
        return NULL;
    }
    if(currentNode->iData == iNode1 || currentNode->iData == iNode2){
        return currentNode;
    }
    TNode* leftLCA = LCAImpl(currentNode->left,iNode1, iNode2);
    TNode* rightLCA = LCAImpl(currentNode->right, iNode1, iNode2);

    if(leftLCA && rightLCA){
        return currentNode;
    }
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}
int main()
{
    CBinaryTree B1;
    B1.LCA(7,6);
    return 0;
}
