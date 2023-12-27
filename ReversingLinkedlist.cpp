// In The Name Of ALlah, The most Gracious The Most Merciful
#include <bits/stdc++.h>
#define ll long long
#define shoot                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define tc \
    int t; \
    cin >> t;
#define vi vector<int>
#define pp pair<int, int>
#define cy cout << "YES" \
                << "\n"
#define cn cout << "NO" \
                << "\n"
using namespace std;

class Node
{
public:
    int Data;
    Node *next;

    Node(int data)
    {
        this->Data = data;
        this->next = NULL;
    }
};

// printing node at tail

// void printTail(Node *&head)
// {

//     Node *temp = head;

//     while (temp->next != NULL)
//     {
//         temp = temp->next;
//     }

//     cout << temp->Data;
// }

// inserting node at head
// void insertAtHead(Node* &head, int d)
// {
//     Node *temp = new Node(d);

//     temp->next = head;
//     head = temp;
// }

// insering node at tail
void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}




// output
void Print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->Data << endl;

        temp = temp->next;
    }
}

Node* reverseLinkedList(Node* head){
    Node* curr= head;
    Node* prev= NULL; 
    Node* forward;

    while(curr!= NULL){
        forward = curr->next;
        curr->next=prev;
        prev= curr;
        curr= forward;
    }

     prev;
   
}



int main()
{
    shoot;
    int n;

    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    Node *curr = head;
    Node *prev = NULL;

    insertAtTail(tail, 19);
    insertAtTail(tail, 29);
    insertAtTail(tail, 39);
    insertAtTail(tail, 49);

    // Print(head);
    head= reverseLinkedList(head);
    // cout<<head->Data<<endl;
    
    
    Print(head);
    
    

    

    //  cout<<"head :"<<head->Data<<endl;
    //  cout<<"tail  :"<<tail->Data<<endl;

    return 0;
}