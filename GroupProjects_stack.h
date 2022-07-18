
#include <iostream>
#include <cassert>

template <typename T>
struct Node
{
    T data;
    Node* next;
};

template <typename T>
class MineStack
{
private:
    Node<T>* top;
    int size;
public:
    MineStack()
    {
        top = nullptr;
        size = 0;
    }
    void push(T data)
    {
        Node<T>* newNode = new Node<T>;
        newNode->data = data;
        newNode->next = top;
        top = newNode;
        size++;
    }
    T pop()
    {
        if (top == nullptr)
        {
            throw "Stack is empty";
        }
        else
        {
            Node<T>* temp = top;
            top = top->next;
            T data = temp->data;
            delete temp;
            size--;
            return data;
        }
    }
    T peek()
    {
        if (top == nullptr)
        {
            throw "Stack is empty";
        }
        else
        {
            return top->data;
        }
    }
    bool isEmpty()
    {
        return top == nullptr;
    }
    int getSize()
    {
        return size;
    }
};



