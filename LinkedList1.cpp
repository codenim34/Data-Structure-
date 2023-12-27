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

class LinkedList
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int length = 0;

    void insertAtHead(int d)
    {
        Node *temp = new Node(d);
        if (head == NULL && tail == NULL)
        {
            head = temp;
            tail = temp;
            length++;
        }
        else
        {
            temp->next = head;
            head = temp;
            length++;
        }
    }

    // insering node at tail
    void insertAtTail(int d)
    {
        Node *temp = new Node(d);
        if (head == NULL && tail == NULL)
        {
            head = temp;
            tail = temp;
            length++;
        }
        else
        {
            tail->next = temp;
            tail = temp;
            length++;
        }
    }

    // deleting node from any position
    void deleteNode(int position)
    {

        if (position == 1)
        {
            Node *temp = head;
            head = temp->next;
            delete temp;

            length--;
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
        length--;
    }

    // deleting head

    void deleteHead()
    {
        Node *temp = head;
        head = temp->next;
        delete temp;
        length--;
    }

    void deleteTail()
    {

        Node *temp = head;
        for (int i = 1; i < length - 1; i++)
        {
            temp = temp->next;
        }

        Node *prev = temp->next;
        tail = temp;
        temp->next = NULL;
        delete prev;
        length--;
    }

    int size()
    {
        return length;
    }
    void Print()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->Data << endl;

            temp = temp->next;
        }
    }

    void Reverse()
    {
        Node *curr = head;
        Node *prev = NULL;
        Node *forward;

        while (curr != NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        head= prev;
    }
};

int main()
{
    shoot;
    int n;

    LinkedList l;
    l.insertAtHead(10);
    l.insertAtHead(20);
    l.insertAtTail(40);
    l.insertAtTail(50);
    // cout << l.size() << endl;
    // l.Print();
    // l.deleteHead();
    // cout << "wait" << endl;
    // l.Print();
    // l.deleteTail();
    // cout << "wait" << endl;
    l.Print();
    l.Reverse();
    l.Print();


    return 0;
}