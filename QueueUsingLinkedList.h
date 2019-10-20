#include <iostream>
using namespace std;
template <class T>
class Node
{
    public:
    T data;
    Node<T>* next;
};
template <class T>
class Queue
{
public:
    Node<T>* front;
    Node<T>* rear;
    void enqueue(T data);
    void dequeue();
    T Front();
    T back();
    void print();
    Queue()
    {
        front=NULL; rear=NULL;
    }
    ~Queue()
    {}
};
template <class T>
void Queue<T> :: enqueue(T data)
{
    Node<T>* newNode=new Node<T>;
    newNode->data=data;
    newNode->next=NULL;
    if(front==NULL && rear==NULL)
    {
        front=rear=newNode;
        return;
    }
    rear->next=newNode;
    rear=newNode;
}
template <class T>
void Queue<T> :: dequeue()
{
    Node<T>* delNode=front;
    front=front->next;
    delete delNode;
}
template <class T>
T Queue<T> :: Front()
{
    return front->data;
}
template <class T>
T Queue<T> :: back()
{
    return rear->data;
}
template <class T>
void Queue<T> :: print()
{
    Node<T>* temp=front;
    cout << "Queue is: ";
    while(temp->next!=NULL)
    {
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout << temp->data << endl;

}
