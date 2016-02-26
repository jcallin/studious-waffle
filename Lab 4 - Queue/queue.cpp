#include "queue.h"
#include <iostream>
#include <stdlib.h>

/*
      Julian Callin 1012798
         Maxen Chung 1072369
            Kelly Wesley 1092292
               Lab 4: Priority Queue using a linked list
                  File: queue.cpp
*/

using namespace std;

Queue::Queue(){
        head = NULL;
}

Queue::Queue(Queue& source){
        *this = source;
}

Queue::~Queue(){
        while(!isEmpty())
                Dequeue();
}


void Queue::Enqueue(int n){
        if(head == NULL){
                Node* newnode = new Node;
                newnode->data = n;
                newnode->next = NULL;
                head = newnode;
        }
        else if (head->data < n){
                Node* newnode = new Node;
                newnode->data = n;
                newnode->next = head;
                head = newnode;
        } else {
                Node* cursor = head;
                Node* trail = head;
                while(cursor != NULL){
                        if(cursor->data > n){
                                trail = cursor;
                                cursor = cursor->next;
                        } else
                                break;
                }
                Node* newnode = new Node;
                newnode->data = n;
                newnode->next = cursor;
                trail->next = newnode;
        }
}

int Queue::Dequeue(){
        int temp = head->data;
        Node* temp_ptr = head;
        head = head->next;
        delete temp_ptr;
        return temp;
}

bool Queue::isEmpty(){
        return (head == NULL);
}

void Queue::dump(){
        while(!isEmpty()){
                cout << Dequeue() << endl;
                cout << endl;
        }
        return;
}


void Queue::operator=(const Queue& source){
        if(this == &source)
                return;
        if(!isEmpty())
                delete this;
        Node* cursor = source.head;
        while(cursor != NULL){
                Enqueue(cursor->data);
                cursor = cursor->next;
        }
}