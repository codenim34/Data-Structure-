// In The Name Of ALlah, The most Gracious The Most Merciful
#include <bits/stdc++.h>
#define ll long long
#define shoot                        \
   ios_base::sync_with_stdio(false); \
   cin.tie(0);
#define tc \
   int t;  \
   cin >> t;
#define vi vector<int>
#define pp pair<int, int>
#define cy cout << "YES" \
                << "\n"
#define cn cout << "NO" \
                << "\n"
using namespace std;

class Heap
{
public:
   int arr[1000];
   int size;

   Heap()
   {
      arr[0] = -1;
      size = 0;
   }

   void insert(int val)
   {
      size = size + 1;
      int index = size;
      arr[index] = val;

      while (index > 1)
      {
         int parent = (index / 2);
         if (arr[parent] < arr[index])
         {
            swap(arr[parent], arr[index]);
            index = parent;
         }
         else
            return;
      }
   }

   void Delete()
   {
      if (size == 0)
      {
         cout << "Nothing to delete" << endl;
         return;
      }
      swap(arr[1], arr[size]);
      arr[size] = -1;
      size--;

      int start = 1;
      while (start < size)
      {
         int rightChild = (start * 2) + 1;
         int leftChild = (start * 2);

         if (arr[start] < arr[leftChild])
         {
            swap(arr[start], arr[leftChild]);
            start = leftChild;
         }
         else if (arr[start] < arr[rightChild])
         {
            swap(arr[start], arr[rightChild]);
            start = rightChild;
         }
         else
         {
            return;
         }
      }
   }

   void Print()
   {
      for (int i = 1; i <= size; i++)
      {
         cout << arr[i] << " ";
      }
   }

   void MaxHeapify(int size, int arr[], int index)
   {
      int left = 2 * index;
      int right = 2 * index + 1;
      int largest = index;

      if (left < size && arr[left] > arr[index])
      {
         largest = left;
      }
      if (right < size && arr[right] > arr[largest])
      {
         largest = right;
      }

      if (largest != index)
      {
         swap(arr[largest], arr[index]);
         MaxHeapify(size, arr, largest);
      }
   }

   void MinHeapify(int size, int arr[], int index)
   {
      int left = 2 * index;
      int right = 2 * index + 1;
      int smallest = index;

      if (left < size && arr[left] < arr[index])
      {
         smallest = left;
      }
      if (right < size && arr[right] < arr[smallest])
      {
         smallest = right;
      }

      if (smallest != index)
      {
         swap(arr[smallest], arr[index]);
         MinHeapify(size, arr, smallest);
      }
   }

   void AscendingHeapSort(int arr[], int size)
   {
   for (int i = (size / 2); i > 0; i--)
      {
         MaxHeapify(size, arr, i);
      }
       

      while (size > 1)
      {
         swap(arr[1], arr[size - 1]);
         size--;
         MaxHeapify(size, arr, 1);
      }
   }

   void DescendingHeapSort(int arr[], int size)
   {
      for (int i = (size / 2); i > 0; i--)
      {
         MinHeapify(size, arr, i);
      }

      while (size > 1)
      {
         //step 1 swap
         swap(arr[1], arr[size - 1]);

         //step 2 
         size--;
         MinHeapify(size, arr, 1);
      }
   }
};
int main()
{
   shoot;
   int n;

   Heap h;
   // h.insert(5);
   // h.insert(10);
   // h.insert(4);
   // h.insert(3);
   // h.insert(6);
   // h.Delete();
   // h.Print();
   int size = 8;
   int arr[size] = {-1, 10, 8, 12, 6, 10,5,16};

   //   for(int i=(size/2);i>0;i--){
   //    h.MinHeapify(size,arr,i);
   //   }

   //   cout<<"MinHeap: "<<endl;
   //   for(int i=1;i<size;i++){
   //    cout<<arr[i]<<" ";
   //   }

   h.AscendingHeapSort(arr, size);

   cout << endl;

   // cout << "Sorted Heap: " << endl;
   // for (int i = 1; i < size; i++)
   // {
   //    cout << arr[i] << " ";
   // }
   
   // cout<<endl;
   // h.DescendingHeapSort(arr,size);
   // cout << "Sorted Heap: " << endl;
   // for (int i = 1; i < size; i++)
   // {
   //    cout << arr[i] << " ";
   // }
}
