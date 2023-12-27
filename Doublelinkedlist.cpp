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
    int data;
    Node *prev;
    Node *next;

    // constructor

    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};
// Printing all nodes data

void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

// getting length of nodelist
int getLength(Node *head)
{
    int len = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    return len;
}

// insert At head
void insertAtHead(Node *&tail, Node *&head, int d)
{
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

// insert  at tail

void insertAtTail(Node *&head, Node *&tail, int d)
{

    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}

// insert at any position
void insertAtAnyPosition(Node *&head, Node *&tail, int position, int d)
{

    if (position == 1)
    {
        insertAtHead(tail, head, d);
    }
    else
    {

        Node *temp = head;
        int count = 1;

        while (count < position - 1)
        {
            temp = temp->next;
            count++;
        }

        if (temp->next == NULL)
        {
            insertAtTail(head, tail, d);
        }
        else
        {

            Node *nodeToInsert = new Node(d);

            nodeToInsert->next = temp->next;

            temp->next->prev = nodeToInsert;

            temp->next = nodeToInsert;

            nodeToInsert->prev = temp;
        }
    }
}

void deleteNode(Node *&head, int position)
{
    Node *currentNode = head;

    if (position == 1)
    {
        head = currentNode->next;
        delete currentNode;
    }
    else
    {
        for (int i = 1; i < position; i++)
        {
            currentNode = currentNode->next;
        }

        if(currentNode->next==NULL){
            Node* temp= currentNode->prev;
            temp->next = NULL;
            currentNode->prev=NULL;
            delete currentNode;
        }else{
             Node* temp= currentNode->prev;
             temp->next= currentNode->next;
             currentNode->next->prev= temp;

             currentNode->next=NULL;
             currentNode->prev=NULL;

             delete currentNode;

        }
    }
}

int main()
{
    shoot;
    int n;
    

    Node *node1 = new Node(10);

    Node *head = node1;
    Node *tail = node1;

    insertAtHead(tail, head, 15);
    insertAtHead(tail, head, 25);
    insertAtHead(tail, head, 35);

    // print(head);
    // cout << getLength(head) << endl;

    insertAtTail(head, tail, 95);
    insertAtTail(head, tail, 85);
    insertAtTail(head, tail, 75);

    // print(head);
    // cout << getLength(head) << endl;

    insertAtAnyPosition(head, tail, 3, 100);
    insertAtAnyPosition(head, tail, 9, 100);
    deleteNode(head,8);
    print(head);

    return 0;
}