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

class CircularQueue
{
public:
    int size;
    int front;
    int rear;
    int *arr;
    int queueSize; // no of elements

    CircularQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
        queueSize = 0;
    }

    void Enqueue(int x)
    {
        if (isFull())
            cout << "Queue is full" << endl;
        else if (rear < size)
        {
            arr[rear] = x;
            rear++;
            queueSize++;
        }
        else
        {
            rear = 0;
            arr[rear] = x;
            rear++;
            queueSize++;
        }
    }

    int Dequeue()
    {
        if (front == rear)
        {
            return -1;
        }
        else
        {
            int ans = arr[front];
            arr[front] = -1;
            queueSize--;
            front++;

            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
            else if (front == size)
            {
                front = 0;
            }
            return ans;
        }
    }

    int frontElement()
    {
        if (front == rear)
            return -1;
        else
            return arr[front];
    }

    int getSize()
    {
        return queueSize;
    }

    bool isFull()
    {
        return queueSize == size;
    }
    bool isEmpty()
    {
        return front == rear;
    }

    void displayQueue()
    {
        int f = front, r = rear - 1;
        if (front == rear)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements are :\n";

        if (f <= r)
        {
            while (f <= r)
            {
                cout << arr[f] << " ";
                f++;
            }
        }
        else
        {
            while (f <= size - 1)
            {
                cout << arr[f] << " ";
                f++;
            }
            f = 0;
            while (f <= r)
            {
                cout << arr[f] << " ";
                f++;
            }
        }
        cout << endl;
    }
};
int main()
{

    CircularQueue q(6);

    q.Enqueue(5);
    q.Enqueue(4);
    q.Enqueue(3);
    q.Enqueue(3);
    q.Enqueue(3);
    q.Enqueue(10);
    q.displayQueue();

    cout << q.Dequeue() << endl;
    cout << q.Dequeue() << endl;
    cout << q.Dequeue() << endl;

    q.displayQueue();
    q.Enqueue(21);
    q.Enqueue(22);
    q.displayQueue();
    cout << q.Dequeue() << endl;
    cout << q.Dequeue() << endl;
    cout << q.Dequeue() << endl;
    // q.Dequeue();
    // q.Dequeue();
    // q.Dequeue();
    // q.Dequeue();
    // q.displayQueue();

    return 0;
}