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
class Deque
{
public:
    // Initialize your data structure.
    int size;
    int *arr;
    int front;
    int rear;
    int dequeSize;
    Deque(int n)
    {
        // Write your code here.
        this->size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
        dequeSize = 0;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    { 
         if (dequeSize == size)
        {
            cout << "Queue is full" << endl;
            return false;
        }
        // Write your code here.
        else if ( front == -1)
        {
            front = 0;
            rear = 0;
          
        }
        
        else if (front == 0 && rear!=(size))
        {
            front = size - 1;
            
            
        }
        else
        {
            front--;
           
        }

         arr[front] = x;
         dequeSize++;
         return true;
    }

    bool pushRear(int x)
    {
        // Write your code here.
         if (dequeSize == size)
        {
            cout << "Queue is full" << endl;
            return false;
        }
        // Write your code here.
        else if ( front == -1)
        {
            front = 0;
            rear = 0;
          
        }
        
        else if (front != 0 && rear==(size-1))
        {
           rear = 0;
        }
        else
        {
            rear++;
           
        }

         arr[rear] = x;
         dequeSize++;
         return true;
    }

     int popFront()
    {
         if (front == rear && front == -1)
        {
           cout<<"Queue is emty"<<endl;
            return false;
        }
        int ans= arr[front];
        if (front==rear)
        {
           front=rear=-1;

        }
        else if (front==size-1)
        {
            // front= size-1;
            front=0;
        }
        else
        {
            front++;
        }
        dequeSize--;
        return ans; 


    }

     int popRear()
    {
        // Write your code here.
        if (front == rear && front == -1)
        {
           cout<<"Queue is emty"<<endl;
            return false;
        }
        int ans= arr[rear];
        if (front==rear)
        {
           front=rear=-1;

        }
        else if (rear==0)
        {
           
            rear= size-1;
            
        }
        else
        {
            rear--;
        }
        dequeSize--;
        return ans; 
    }

      int getFront()
    {
        // Write your code here.
        if(isEmpty()) return -1;
        return arr[front];
    }

      int getRear()
    {
        // Write your code here.
        return arr[rear];
    }

    bool isEmpty()
    {
        // Write your code here.
        return front==rear && front==-1;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        return dequeSize==size;// Write your code here.
    }

    void displayQueue()
    {
        int f = front, r = rear ;
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
   Deque d(8);
  cout<< d.pushFront(15)<<endl;
  cout<<d.pushRear(25)<<endl;
   cout<< d.pushFront(20)<<endl;
    cout<<d.isFull()<<endl;
    cout<<d.getRear()<<endl;
    
    // cout<< d.pushFront(7)<<endl;

   

//      cout<< d.pushFront(8)<<endl;
    //   cout<< d.pushFront(9)<<endl;
    //    cout<< d.pushFront(10)<<endl;
  
         d.displayQueue();
//   cout<<d.dequeSize<<endl;
  

}


