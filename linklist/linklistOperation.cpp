using namespace std;
#include<iostream>

struct TNode
{
    int iData;
    TNode* next;
};
TNode* createNode(int iNewData)
{
    TNode* newNode = new TNode();
    newNode->iData = iNewData;
    newNode->next = NULL;
    return newNode;
}

class CLinklist
{
    TNode* m_pRoot;
public:
    CLinklist();
    ~CLinklist();
    void addAtBegin(int iNewData);
    void addAtEnd(int iNewData);
    void printNode();
    void alternateReverse();
    void reverseLinklist();
    void findMiddleElement();
    void checkPalindrom();
    void removeDuplicate();
    void printkthFromLast(int);
    void add2Linklist();
};
CLinklist::CLinklist()
{
    m_pRoot = NULL;
}
CLinklist::~CLinklist()
{
    delete m_pRoot;
}
void CLinklist::addAtBegin(int iNewData)
{
    TNode* newNode = createNode(iNewData);
    if(m_pRoot){
        newNode->next = m_pRoot;
    }
    m_pRoot = newNode;
}
void CLinklist::addAtEnd(int iNewData){
    TNode* newNode = createNode(iNewData);
    if(m_pRoot == NULL){
        m_pRoot = newNode;
    }
    else{
        TNode* currentNode = m_pRoot;
        while(currentNode->next){
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}
void CLinklist::printNode()
{
    TNode* currentNode = m_pRoot;
    cout<<"Linklist Data:\t";
    while(currentNode){
        cout<<" "<<currentNode->iData<<" ";
        currentNode = currentNode->next;
    }
    cout<<endl;
}
void CLinklist::alternateReverse()
{
   TNode* currentNode = m_pRoot;
   TNode* newHead = currentNode->next;
   while(1){
    TNode* q = currentNode->next;
    TNode* temp = q->next;
    q->next = currentNode;
    if(temp == NULL || temp->next == NULL){
        currentNode->next = temp;
        break;
    }
    currentNode->next = temp->next;
    currentNode = temp;
   }
   m_pRoot = newHead;
}
void CLinklist::reverseLinklist()
{
    TNode* currentNode = m_pRoot;
    TNode* prev = NULL;
    TNode* next = NULL;
    while(currentNode){
        next = currentNode->next;
        currentNode->next = prev;
        prev = currentNode;
        currentNode = next;
    }
    m_pRoot = prev;
}
void CLinklist::findMiddleElement()
{
    TNode* currentNode = m_pRoot;
    TNode* middle = m_pRoot;
    while(currentNode->next){
        if(currentNode->next->next){
            currentNode = currentNode->next->next;
        }
        else{
            break;
        }
        middle = middle->next;
    }
    cout<<"Middle Element: "<<middle->iData<<endl;
}
void CLinklist::checkPalindrom()
{
    TNode* currentNode = m_pRoot;
    TNode* backup = m_pRoot;
    TNode* mid = m_pRoot;
    while(currentNode->next){
        if(currentNode->next->next){
            currentNode = currentNode->next->next;
        }
        else{
            break;
        }
        mid = mid->next;
    }
    TNode* prev = NULL;
    TNode* next = NULL;
    TNode* revCurr = mid;
    while(revCurr){
        next = revCurr->next;
        revCurr->next = prev;
        prev = revCurr;
        revCurr = next;
    }
    revCurr = prev;
    TNode* reverseNode = revCurr;
    currentNode = m_pRoot;
    int iFlag = 0;
    while(currentNode != mid && revCurr != NULL){
        if(currentNode->iData != revCurr->iData){
            iFlag = 1;
            break;
        }
        currentNode = currentNode->next;
        revCurr = revCurr->next;
    }
    if(iFlag){
        cout<<"Not Palindrom"<<endl;
    }
    else{
        cout<<"Palindrom"<<endl;
    }
    prev = NULL;
    next = NULL;
    revCurr = reverseNode;
    while(revCurr){
         next = revCurr->next;
        revCurr->next = prev;
        prev = revCurr;
        revCurr = next;
    }
    revCurr = prev;
}
void CLinklist::removeDuplicate()
{
    TNode* slowPtr = m_pRoot;
    while(slowPtr){
        int iData2Check = slowPtr->iData;
        TNode* fastPtr = slowPtr;
        while(fastPtr->next){
             if(fastPtr->next->iData == iData2Check){
                if(fastPtr->next->next){
                    fastPtr->next = fastPtr->next->next;
                }
                else{
                    fastPtr->next = NULL;
                }
             }
             else{
                fastPtr = fastPtr->next;
             }
        }
        slowPtr = slowPtr->next;
    }
}
void CLinklist::printkthFromLast(int k)
{
    TNode* currrentNode = m_pRoot;
    while(currrentNode){
        currrentNode = currrentNode->next;
        k--;
    }
    TNode* slowPtr = m_pRoot;
    while(currrentNode){
        slowPtr = slowPtr->next;
        currrentNode = currrentNode->next;
    }
    cout<<"Kth Node From Last: "<<slowPtr->iData<<endl;
}
void CLinklist::add2Linklist()
{
    TNode* list1 = createNode(7);
    list1->next = createNode(1);
    list1->next = createNode(6);

    TNode* list2 = createNode(5);
    list2->next = createNode(9);
    list2->next = createNode(2);

    TNode* newNode;
    while(list1 != NULL && list2 != NULL){
        int iData_l1 = list1->iData;
        int iData_l2 = list2->iData;
        if(iData_l1 + iData_l2 >= 10){
            int iRemid
        }
    }

}
int main()
{
    CLinklist L1;
    L1.addAtEnd(1);
    L1.addAtEnd(2);
    L1.addAtEnd(3);
    L1.addAtEnd(2);
    L1.addAtEnd(1);
    L1.addAtEnd(60);
    L1.printNode();
    L1.alternateReverse();
    L1.printNode();
    L1.alternateReverse();
    L1.printNode();
    L1.reverseLinklist();
    L1.printNode();
    L1.findMiddleElement();
    L1.checkPalindrom();
    L1.printNode();
    L1.removeDuplicate();
    L1.printNode();

    return 0;
}

