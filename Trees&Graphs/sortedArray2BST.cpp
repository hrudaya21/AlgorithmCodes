using namespace std;
#include<iostream>
#include<stack>

struct TNode
{
    int iData;
    TNode* left;
    TNode* right;
};
TNode* createNode(int iNewNode)
{
    TNode* newNode = new TNode();
    newNode->iData = iNewNode;
    newNode->left = newNode->right = NULL;
    return newNode;
}
TNode* sortedArray2BST(int* inputArr, int iStart, int iEnd)
{
    if(iStart > iEnd){
        return NULL;
    }
    int iMid = (iStart + iEnd)/2;
    TNode* root = createNode(inputArr[iMid]);
    root->left = sortedArray2BST(inputArr,iStart,iMid-1);
    root->right = sortedArray2BST(inputArr,iMid+1, iEnd);
    return root;
}
void inOrderTraversal(TNode* root)
{
    TNode* currentNode = root;
    stack<TNode*> stackList;
    cout<<"INORDER TRAVERSAL:==>\t ";
    while(1){
        if(currentNode){
            stackList.push(currentNode);
            currentNode = currentNode->left;
        }
        else{
            if(!stackList.empty()){
                TNode* temp = stackList.top();
                stackList.pop();
                cout<<" "<<temp->iData<<" ";
                currentNode = temp->right;
            }
            else{
                break;
            }
        }
    }
    cout<<endl;
}

int main()
{
    int inputArr[] = {10,20,30,40,50,60,70};
    int iSizeOfArr = sizeof(inputArr)/sizeof(inputArr[0]);
    TNode* bstNode = NULL;
    TNode* root = sortedArray2BST(inputArr,0,iSizeOfArr-1);
    inOrderTraversal(root);
    return 0;
}
