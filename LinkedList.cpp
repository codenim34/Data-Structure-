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

void printTail(Node *&head)
{

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    cout << temp->Data;
}

// inserting node at head
void insertAtHead(Node* &head, int d)
{
    Node *temp = new Node(d);

    temp->next = head;
    head = temp;
}

// insering node at tail
void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

// inserting node at any position
void insertAtAnyPosition(Node *&head, Node *&tail, int position, int d)
{

    if (position == 1)
    {
        insertAtHead(head, d);
    }
    else
    {

        Node *temp = head;
        int cnt = 1;

        while (cnt < position - 1)
        {
            temp = temp->next;
            cnt++;
        }

        if (temp->next == NULL)
        {
            insertAtTail(tail, d);
        }
        else
        {

            Node* nodeToInsert = new Node(d);

            nodeToInsert->next = temp->next;
            temp->next = nodeToInsert;
        }
    }
}

// deleting node

void deleteNode(Node *&head, int position)
{

    if (position == 1)
    {
        Node *temp = head;
        head = temp->next;
        delete temp;
        return;
    }

    Node *curr = head;

    Node *prev = NULL;

    for (int i = 1; i < position; i++)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr->next == NULL)
    {
        prev->next = NULL;
    }
    else
    {
        prev->next = curr->next;
        curr->next = NULL;
    }

    delete curr;
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

    insertAtAnyPosition(head, tail, 1, 34);
    // Print(head);

    deleteNode(head, 6);
    // Print(head);

    printTail(head);

    // cout<<"tail  :"<<tail->Data<<endl;

    return 0;
}