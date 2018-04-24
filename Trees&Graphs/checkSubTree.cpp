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
private:
    TNode* m_pTree1;
    TNode* m_pTree2;
public:
    CBinaryTree(){
        m_pTree1 = createNode(1);
        m_pTree1->left = createNode(2);
        m_pTree1->right = createNode(3);
        m_pTree1->left->left = createNode(4);
        m_pTree1->left->right = createNode(5);
        m_pTree1->right->left = createNode(6);
        m_pTree1->right->right = createNode(7);

        m_pTree2 = createNode(1);
        m_pTree2->left = createNode(2);
        m_pTree2->right = createNode(3);
        m_pTree2->left->left = createNode(4);
        m_pTree2->left->right = createNode(5);
        //m_pTree2->right->left = createNode(6);
        //m_pTree2->right->right = createNode(7);
    }
    ~CBinaryTree(){
        delete m_pTree1;
        delete m_pTree2;
    }
    void checkSameTree();
    bool checkSameTreeImpl(TNode*,TNode*);
    void checkSubTree();
    bool checkSubTreeImpl(TNode*, TNode*);
};

void CBinaryTree::checkSameTree()
{
    TNode* node1 = m_pTree1;
    TNode* node2 = m_pTree2;
    if(checkSameTreeImpl(node1,node2)){
        cout<<"Same Tree"<<endl;
    }
    else{
        cout<<"Not Same Tree"<<endl;
    }
}
bool CBinaryTree::checkSameTreeImpl(TNode* node1, TNode* node2)
{
    if(node1 == NULL && node2 == NULL){
        return true;
    }
    if(node1->left && node2->left){
       if(node1->iData == node2->iData && checkSameTreeImpl(node1->left,node2->left)){
        return true;
       }
    }
    if(node1->iData == node2->iData && checkSameTreeImpl(node1->left,node2->left) && checkSameTreeImpl(node1->right,node2->right)){
        return true;
    }
    return false;
}
void CBinaryTree::checkSubTree()
{
    TNode* node1 = m_pTree1;
    TNode* node2 = m_pTree2;
    if(checkSubTreeImpl(node1, node2)){
        cout<<"One Tree is SubTree to Another"<<endl;
    }
    else{
        cout<<"No SubTree Found"<<endl;
    }
}
bool CBinaryTree::checkSubTreeImpl(TNode* mainTree, TNode* subTree)
{
    if(subTree == NULL){
        return true;
    }
    if(mainTree == NULL){
        return false;
    }
    if(checkSameTreeImpl(mainTree,subTree)){
        return true;
    }
    return (
            checkSubTreeImpl(mainTree->left,subTree)
            || checkSubTreeImpl(mainTree->right, subTree) );
}

int main()
{
    CBinaryTree B1;
    B1.checkSameTree();
    //B1.checkSubTree();
    return 0;
}
