using namespace std;
#include<iostream>
#include<stdlib.h>

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
int getHeight(TNode* currentNode)
{
    if(currentNode == NULL){
        return 0;
    }
    else{
        return 1 + max(getHeight(currentNode->left),getHeight(currentNode->right));
    }
}

bool checkIfBalance(TNode* root)
{
    if(root == NULL){
        return true;
    }
    else{
        int iLeftHeight = getHeight(root->left);
        int iRightHeight = getHeight(root->right);
        if(abs(iLeftHeight-iRightHeight) <= 1 && checkIfBalance(root->left) && checkIfBalance(root->right)){
            return true;
        }
        return false;
    }
}
int main()
{
    TNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    if(checkIfBalance(root)){
        cout<<"Tree is Balanced!!!"<<endl;
    }
    else{
        cout<<"Tree is Not Balanced!!!"<<endl;
    }
    return 0;
}
