//author: Fahrettin Basturk
//date: 10/07/2022
//description: Double linked list for students class
//version: Possible Final.
//language: cpp
//path: doubleLinkedList.h

#ifndef DoubleLinkedlist_H_
#define DoubleLinkedlist_H_

#include <iostream>
#include <cassert>

namespace std {

//double linked list template node struct
template <typename T>
struct Node {
    T data;
    Node<T> *next;
    Node<T> *prev;
};

//double linked list template class
template <class T>
class DoubleLinkedList {
    Node<T> *head;
    Node<T> *tail;
    int size;
public:
    DoubleLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    
    T get_element(int i) {
        assert(i >= 0 && i < size); // how does it work? 
        Node<T> *temp = head;
        for (int j = 0; j < i; j++) {
            temp = temp->next;
        }
        return temp->data;
    }
    // reaturn head node
    Node<T> *get_head() {
        return head;
    }
    // push method for double linked list
    void instert_end(T data) {
        Node<T> *new_node = new Node<T>;
        new_node->data = data;
        new_node->next = NULL;
        new_node->prev = NULL;
        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
        size++;
    }


    //print all values in ascending order
    void print_ascending() { 
        Node<T> *newNode = head; //first node is the list
        while (newNode != NULL) { 
            cout << newNode->data << " "; //print the data of the node
            newNode = newNode->next; //move to the next node
        }
        cout << endl;
    }

    //print all values in descending order
    void print_descending() {   
        Node<T> *newNode = tail; //last node of the list
        while (newNode != NULL) { 
            cout << newNode->data << " "; //print the data of the node
            newNode = newNode->prev; //move to the previous node
        }
        cout << endl;
    }
    // I just want to write that code in that way, but I don't know why.
    int Remove(T data);

    //find the index of the data
    void index(T data)
    {
        Node<T> *newNode = head;
        if (Find(data)) { //if the data is in the list
            cout <<"backward index of " << data <<" is: " << forwardIndex(data) <<"." << endl;
            cout <<"backward index of " << data <<" is: " << backwardIndex(data) <<"." << endl;
        } 
        else {
            cout << data  << " does not include of the linked list." << endl;
        }  
    }

    /*
    earches a key in the list and returns a pointer
    to the list node that contains the key
    */
    Node<T>* Find(T data) {
        Node<T> *newNode = head;
        while (newNode != NULL) { 
            if (newNode->data == data) { 
                return newNode; 
            }
            newNode = newNode->next;
        }
        return NULL;
    }

    //remove all the nodes in the list
    void Clear() {
        Node<T> *newNod = head; // consider the head node as the first node to be removed
        while (newNod != NULL) //while temp is not null when there are nodes in the list
        {
            Node<T> *Delater_Node = newNod; //Delater_Node is the node that is removed from the list
            newNod = newNod->next; // move the pointer to the next node
            delete Delater_Node; //delete the node
        }
        head =tail =NULL;
        size = 0;
    }

    //return the size of the list
    int getSize() {
        return size;
    }
    //remove all the nodes in the list
    ~DoubleLinkedList() {
        Clear(); //remove all the nodes in the list with using a function.
    }
    protected:

    void removeAccordingToNode(Node<T> *node);
    //find the forward index of the data

    int forwardIndex(T data) {
        Node<T> *newNode = head;
        int index = 0; // creating a variable to store the index of the data
        while (newNode != NULL) { //find the node that contains the data
            if (newNode->data == data) {
                index ++; // to fix the bug of forward index according to the school's example
                return index;
            }
            newNode = newNode->next;
            index++;
        }
        cout <<"I could't find the data inside of the list" << endl;
        return -1; // I think there should be a return value of -1 if the data is not found in the list
    }

    //find the backward index of the data
    int backwardIndex(T data) {
        Node<T> *newNode = tail;
        int index = 0; // creating a variable to store the index of the data
        while (newNode != NULL) { //find the node that contains the data
            if (newNode->data == data) {
                index ++; // to fix the bug of backward index according to the school's example
                return index;
            }
            newNode = newNode->prev; // move the pointer to the previous node
            index++;
        }
        cout <<"I could't find the data inside of the list" << endl;
        return -1; // I think there should be a return value of -1 if the data is not found in the list
    }


};  
    template <class T>
    int DoubleLinkedList<T>::Remove(T data) {     // Returns 0 upon successful deletion, if there is not any node with the given data, returns -1 and use the remove function to delete the node
        Node<T> *newNode = head;
        while (newNode != NULL) {
            if (newNode->data == data) {
                removeAccordingToNode(newNode);
                return 0;
            }
            newNode = newNode->next; // move the pointer to the next node
        }
        return -1;
    }
    template <class T>
    void DoubleLinkedList<T>::removeAccordingToNode(Node<T> *node) {
        if (node == head) { // if the node is the head, then we need to change the head to the next node
            head = node->next;
        } 
        else if (node == tail) { // if the node is the tail, we need to change the tail to the previous node
            tail = node->prev;
        } 
        else { // if the node is in the middle of the list
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        delete node;
        size--;
    }

} /* namespace std */

#endif /* DoubleLinkedList_H_ */
