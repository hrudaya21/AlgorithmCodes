using namespace std;
#include<iostream>
#include<stack>

struct TNode
{
    int iData;
    TNode* left;
    TNode* right;
    TNode* parent;
};

TNode* createNode(int iNewData)
{
    TNode* newNode = new TNode();
    newNode->iData = iNewData;
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}
class CBinaryTree
{
private:
    TNode* m_pBinaryTree;
public:
    CBinaryTree();
    ~CBinaryTree();
    void inOrderTraversal();
    void inOrderSuccesor(TNode*);
    TNode* leftMost(TNode*);
};
CBinaryTree::CBinaryTree()
{
    m_pBinaryTree = createNode(1);
    m_pBinaryTree->left = createNode(2);
    m_pBinaryTree->left->parent = m_pBinaryTree;
    m_pBinaryTree->right = createNode(3);
    m_pBinaryTree->right->parent = m_pBinaryTree;
    m_pBinaryTree->left->left = createNode(4);
    m_pBinaryTree->left->left->parent = m_pBinaryTree->left;
    m_pBinaryTree->left->right = createNode(5);
    m_pBinaryTree->left->right->parent = m_pBinaryTree->left;
    m_pBinaryTree->right->left = createNode(6);
    m_pBinaryTree->right->left->parent = m_pBinaryTree->right;
    m_pBinaryTree->right->right = createNode(7);
    m_pBinaryTree->right->right->parent = m_pBinaryTree->right;
}
CBinaryTree::~CBinaryTree()
{
    delete m_pBinaryTree;
}
void CBinaryTree::inOrderTraversal()
{
    TNode* currentNode = m_pBinaryTree;
    stack<TNode*> stackList;
    while(1){
        if(currentNode){
            stackList.push(currentNode);
            currentNode = currentNode->left;
        }
        else{
            if(!stackList.empty()){
                TNode* temp = stackList.top();
                stackList.pop();
                inOrderSuccesor(temp);
                //cout<<" "<<temp->iData<<" ";
                currentNode = temp->right;
            }
            else{
                break;
            }
        }
    }
    cout<<endl;
}
TNode* CBinaryTree::leftMost(TNode* currentNode)
{
    if(currentNode == NULL){
        return NULL;
    }
    while(currentNode->left){
        currentNode = currentNode->left;
    }
    return currentNode;
}

void CBinaryTree::inOrderSuccesor(TNode* head)
{
    TNode* currentNode = head;
    TNode* parentNode = currentNode->parent;
    if(currentNode->right){
        cout<<"InOrder Successor of: "<<currentNode->iData<<" is ===> "<<leftMost(currentNode->right)->iData<<endl;
    }
    else{
        while(parentNode != NULL && parentNode->left != currentNode){
            currentNode = parentNode;
            parentNode = parentNode->parent;
        }
        if(parentNode){
            cout<<"InOrder Successor of: "<<head->iData<<" is ===> "<<parentNode->iData<<endl;
        }
        else{
            cout<<"InOrder Successor of: "<<head->iData<<" is ===> NULL"<<endl;
        }
    }
}

int main()
{
    CBinaryTree B1;
    B1.inOrderTraversal();
    return 0;
}
