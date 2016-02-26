/*
   Julian Callin
   1012698
   Chapter 5 Project 15: Doubly linked list set
*/
#include <iostream>
using namespace std;

struct node{
        int data;
        node* next;
        node* prev;
};

class sequence{
        node header;
        node trailer;
        node* cursor;

        public:
        sequence(){
                header.next = &trailer;
                header.prev = NULL;
                trailer.next = NULL;
                trailer.prev = &header;
                cursor = &header;
                header.data = 0;
                trailer.data = 0;
        }

        sequence(sequence& b){
                header.next = &trailer;
                header.prev = NULL;
                trailer.next = NULL;
                trailer.prev = &header;
                cursor = &header;
                header.data = 0;
                trailer.data = 0;
                *this = b;
        }

        ~sequence(){
                clear();
        }

        void clear(){
                start();
                node* temp;
                while(cursor != &trailer){
                        cursor->prev->next = cursor->next;
                        cursor->next->prev = cursor->prev;
                        temp = cursor;
                        cursor = cursor->next;
                        delete temp;
                }
                return;
        }

        void end(){
                cursor = trailer.prev;
                return;
        }
        void start(){
                cursor = header.next;
                return;
        }
        void advance(){
                cursor = cursor->next;
                return;
        }

        void retreat(){
                cursor = cursor->prev;
                return;
        }

        int current(){
                return cursor->data;
        }

        bool insert(int y){
                if(header.next == &trailer){
                        node* newnode = new node;
                        newnode->data = y;
                        newnode->next = &trailer;
                        newnode->prev = &header;
                        header.next = newnode;
                        trailer.prev = newnode;
                        return true;
                }
                start();
                while(cursor->next != NULL){
                        if (cursor->data < y){
                                break;
                        }
                        advance();
                }
                node* newnode = new node;
                newnode->data = y;
                newnode->next = cursor;
                newnode->prev = cursor->prev;
                cursor->prev->next = newnode;
                cursor->prev = newnode;
                return true;
        }

        bool attach(int y){
                if(header.next == &trailer){
                        node* newnode = new node;
                        newnode->data = y;
                        newnode->next = &trailer;
                        newnode->prev = &header;
                        header.next = newnode;
                        trailer.prev = newnode;
                        return true;
                }
                end();
                while(cursor->prev != NULL){
                        if (cursor->data > y){
                                node* newnode = new node;
                                newnode->data = y;
                                newnode->prev= cursor;
                                newnode->next = cursor->next;
                                cursor->next->prev= newnode;
                                cursor->next= newnode;
                                return true;
                        }
                        retreat();
                }
                return false;
        }

        void dump(){
                cursor = header.next;
                while(cursor != &trailer){
                        cout << cursor->data << endl;
                        cursor = cursor->next;
                }
                cout << "-------------" << endl;
                return;
        }

        sequence& operator=(sequence& b){
                if(this == &b)
                        return *this;
                this->clear();
                b.start();
                this->start();

                while(b.cursor->next != NULL){
                        insert(b.current());
                        b.advance();
                }
                return *this;
        }
};

int main(){
        sequence a;
        sequence b;
        b.insert(999);
        sequence c(b);
        c.dump();

        a.insert(2);
        a.insert(8);
        a.insert(1);
        a.insert(-5);
        a.attach(6);
        a.attach(-10);
        a.dump();

        b.insert(2);
        b.insert(11);
        b.insert(13);
        b.dump();

        cout << "testing assignment overload" << endl;
        c = b;
        c.dump();

        cout << "testing copy cstor" << endl;
        sequence d(c);

        return 0;
}
