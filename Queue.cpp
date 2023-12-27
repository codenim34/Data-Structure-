//In The Name Of ALlah, The most Gracious The Most Merciful
#include<bits/stdc++.h>
#define ll long long
#define shoot           ios_base::sync_with_stdio(false); cin.tie(0);
#define tc             int t; cin>>t;
#define vi vector<int> 
#define pp pair<int,int>
#define cy cout<<"YES"<<"\n"
#define cn cout<<"NO"<<"\n"
using namespace std;

class Queue{
    public:
    int size;
    int front;
    int rear;
    int *arr;
    int queueSize; //no of elements

      Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0; 
        queueSize = 0;
    }

      void Enqueue(int x)
    {
        if (rear == (size) )
            cout << "Queue is full" << endl;
        else
        {
            arr[rear] = x;
            rear++;
            queueSize++;
        }
    }

    int Dequeue()
    {
        if (front== rear)
        {
            return -1;
        }
        else
        {
           int ans= arr[front];
           arr[front]=-1;
            queueSize--;
            front++;

           if(front==rear){
            front=0;
            rear=0;
           }
            return ans;
        }
       
    }

    int frontElement(){
        if(front==rear) return -1;
         else return arr[front];
    }

    int getSize(){
        return  queueSize;
    }


      bool isFull()
    {
        return rear == (size);
    }
    bool isEmpty()
    {
        return front==rear;
    }


    void displayQueue(){
        for(int i=front;i<rear;i++){
            cout<<arr[i]<<" ";
        }

        cout<<endl;
    }

};
int main()
{

Queue q(6);

    q.Enqueue(5);
    q.Enqueue(4);
    q.Enqueue(3);
    q.Enqueue(3);
    q.Enqueue(3);
    q.Enqueue(10);
   
    q.displayQueue();
      q.Dequeue();
        q.Dequeue();
          q.Dequeue();
            q.Dequeue();
             q.Dequeue();
              q.Dequeue();

            q.displayQueue();

return 0;
}