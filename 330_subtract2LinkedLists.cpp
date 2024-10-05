#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x): data(x), next(nullptr){}
};

int getLength(Node *head){
    int len = 0;
    while(head){
        len++;
        head = head->next;
    }
    return len;
}

Node* addLeadingZeros(Node* head, int zeros){
    while(zeros--){
        Node *newNode = new Node(0);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

Node* subtractHelper(Node* l1, Node* l2, Node*& result){
    if(!l1 && !l2)
        return nullptr;
    result = new Node(0);
    int borrow = 0;
    result->next = subtractHelper(l1->next, l2->next, result->next);
    result->data = l1->data - l2->data;
    if(result->data < 0){
        result->data += 10;
        borrow = 1;
    }
    if(borrow){
        l1->data--;
    }
    return result;

}

Node* subtract(Node* l1, Node* l2){
    int len1 = getLength(l1);
    int len2 = getLength(l2);
    if(len1 < len2){
        l1 = addLeadingZeros(l1, len2 - len1);
    }else if(len2 < len1){
        l2 = addLeadingZeros(l2, len1 - len2);
    }
    Node *result = nullptr;
    subtractHelper(l1, l2, result);
    while(result->data == 0 && result->next){
        Node *temp = result;
        result = result->next;
        delete temp;
    }
    return result;
}


int main()
{
    Node *l1 = new Node(1);
    l1->next = new Node(0);
    l1->next->next = new Node(0);
    l1->next->next->next = new Node(0);
    l1->next->next->next->next = new Node(0);
    l1->next->next->next->next->next = new Node(0);
    l1->next->next->next->next->next->next = new Node(0);
    l1->next->next->next->next->next->next->next = new Node(0);
    l1->next->next->next->next->next->next->next->next = new Node(0);
    l1->next->next->next->next->next->next->next->next->next = new Node(0);

    Node *l2 = new Node(1);

    Node *result = subtract(l1, l2);
    while(result){
        cout << result->data << " ";
        result = result->next;
    }

return 0;
}