using namespace std;
#include<iostream>

struct TNode
{
    int iData;
    TNode* left;
    TNode* right;
    bool bLeftThread;
    bool bRightThread;
};

TNode* createNode(int iNewData)
{
    TNode* newNode = new TNode();
    newNode->iData = iNewData;
    newNode->left = newNode->right = NULL;
    newNode->bLeftThread = newNode->bRightThread = true;
    return newNode;
}

class CThreadedBinaryTree
{
private:
    TNode* m_pThreadedRoot;
public:
    CThreadedBinaryTree();
    ~CThreadedBinaryTree();
    void insert2ThreadedBTree(int);
    TNode* leftMost(TNode*);
    void inOrderTraversal();
};

CThreadedBinaryTree::CThreadedBinaryTree(){
    m_pThreadedRoot = NULL;
}
CThreadedBinaryTree::~CThreadedBinaryTree(){
    delete m_pThreadedRoot;
}

void CThreadedBinaryTree::insert2ThreadedBTree(int iNewData)
{
    TNode* newNode = createNode(iNewData);
    TNode* currentNode = m_pThreadedRoot;
    TNode* itrNode = m_pThreadedRoot;
    while(itrNode){
        if(newNode->iData == itrNode->iData){
            cout<<"Duplicate Record Not Allowed in Insertion of BST"<<endl;
            return;
        }
        currentNode = itrNode; //One Key Point Need to Track
        if(iNewData < itrNode->iData){
            if(itrNode->bLeftThread == false){
                itrNode = itrNode->left;
            }
            else{
                break;
            }
        }
        else{
            if(itrNode->bRightThread == false){
                itrNode = itrNode->right;
            }
            else{
                break;
            }
        }
    }
    if(currentNode == NULL){
        m_pThreadedRoot = newNode;
    }
    else if(iNewData < currentNode->iData){
        newNode->left = currentNode->left;
        newNode->right = currentNode;
        currentNode->left = newNode;
        currentNode->bLeftThread = false;
    }
    else{
        newNode->right = currentNode->right;
        newNode->left = currentNode;
        currentNode->right = newNode;
        currentNode->bRightThread = false;
    }
}
TNode* CThreadedBinaryTree::leftMost(TNode* currentNode)
{
    if(currentNode == NULL){
        return NULL;
    }
    while(currentNode->bLeftThread == false){
        currentNode = currentNode->left;
    }
    return currentNode;
}
void CThreadedBinaryTree::inOrderTraversal()
{
    TNode* currentNode = m_pThreadedRoot;
    currentNode = leftMost(currentNode);
    cout<<"InOrder Traversal:==> ";
    while(currentNode){
        cout<<" "<<currentNode->iData<<" ";
        if(currentNode->bRightThread){
            currentNode = currentNode->right;
        }
        else{
            currentNode = leftMost(currentNode->right);
        }
    }
    cout<<endl;
}
int main()
{
    CThreadedBinaryTree B1;
    B1.insert2ThreadedBTree(10);
    B1.insert2ThreadedBTree(15);
    B1.insert2ThreadedBTree(7);
    B1.insert2ThreadedBTree(24);
    B1.insert2ThreadedBTree(35);
    B1.insert2ThreadedBTree(79);
    B1.inOrderTraversal();
    return 0;
}
