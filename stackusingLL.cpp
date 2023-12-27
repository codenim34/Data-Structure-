#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data= data;
        this->next=nullptr;
    }
};

class Stack{
    private:
     Node* head;
    
     public:
     Stack(){
        head = nullptr;
     }

     void push (int data){
        Node* n1 = new Node(data);
        if(isEmpty()){
            head=n1;
           
        }else{
            n1->next=head;
            head=n1;
        }

     }

     void pop(){
        if(!isEmpty()){
           Node* temp = head;
           head= head->next;
           delete temp;
        }
     }

      int peek() {
        if (!isEmpty()) {
            return head->data;
        } else {
            std::cerr << "Stack is empty." << std::endl;
            return -1; // Return a default value or throw an exception
        }
    }

        bool isEmpty() {
        return head==nullptr;
    }
};

int main(){
    Stack stack;

    stack.push(5);
    stack.push(30);

    stack.push(5);
    stack.push(30);

    cout<<stack.peek()<<endl;


}